#训练花朵分类模型脚本
import torch
import time
import os
from torchvision import transforms,models
from flower_dataset import FlowerDataset
from torch.utils.data import DataLoader
from torch import nn,optim
from model_trainer import ModelTrainer
if __name__  == "__main__":

#参数配置
    train_dir = r"D:\data\flowers_data\train"
    valid_dir = r"D:\data\flowers_data\valid"
    batch_size = 64
    max_epoch = 40
    num_cls = 102
    lr0 = 0.01
    momentum = 0.9
    weight_decay = 1e-4
    milestones = [25, 35]
    decay_factor = 0.1
    log_interval = 10 #iteration
    norm_mean,norm_std = [0.485,0.456,0.406] , [0.229,0.224,0.225]
    time_str = time.strftime("%Y%m%d")
    output_dir = f"outputs/{time_str}"
    os.makedirs(output_dir,exist_ok = True)
    #实例化dataset(train valid)
    train_transform = transforms.Compose([
        transforms.Resize(256),#(256,256)区别 256：短边保持256 1920*1080[1080->256 1920*1080/256]
        transforms.RandomCrop(224),#模型最终的输入大小[224,224]
        transforms.RandomHorizontalFlip(p=0.5),
        transforms.ToTensor(),#0-225 -> 0-1 float HWC -> CHW -> BCHW
        transforms.Normalize(norm_mean,norm_std)#减去均值 除以方差
    ])
    train_dataset = FlowerDataset(img_dir = train_dir, transform = train_transform)
    #valid
    valid_transform = transforms.Compose([
        transforms.Resize((224,224)),
        transforms.ToTensor(),
        transforms.Normalize(norm_mean,norm_std)
    ])
    valid_dataset = FlowerDataset(img_dir = valid_dir,transform = valid_transform)
    #组装dataloader
    train_loader = DataLoader(train_dataset, batch_size, shuffle = True,num_workers = 2)
    valid_loader = DataLoader(valid_dataset, batch_size, shuffle = False,num_workers = 2)
    #实例化网络模型
    model = models.resnet18(pretrained = True)
    in_features = model.fc.in_features
    fc = nn.Linear(in_features = in_features,out_features = num_cls)
    model.fc = fc

    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    model.to(device = device) 
    #优化器相关
        #loss函数
    loss_fn = nn.CrossEntropyLoss()
        #优化器实例化
    optimizer = optim.SGD(model.parameters(), lr = lr0,momentum = momentum,weight_decay = weight_decay)
        #lr的下降策略实例化
    lr_scheduler = optim.lr_scheduler.MultiStepLR(optimizer,milestones = milestones,gamma = decay_factor)

#loop

    for epoch in range(max_epoch):
        """一次epoch的训练
        按batch形式取数据
        前向传播
        计算Loss
        反向传播计算梯度
        更新权重
        统计Loss 准确率
        """
        loss_train,acc_train,conf_mat_train,path_error_train = ModelTrainer.train_one_epoch(
            train_loader,model,
            loss_f = loss_fn,
            optimizer = optimizer,
            scheduler = lr_scheduler,
            epoch_idx = epoch,
            device = device,
            log_interval = log_interval,
            max_epoch = max_epoch,
        )
        """
            一次epoch验证
            按Batch形式取数据
            前向传播
            计算Loss
            统计Loss  准确率
        """
        loss_valid,acc_valid,conf_mat_valid,path_error_valid = ModelTrainer.valid_one_epoch(
            valid_loader,
            model,loss_fn,
            device = device,
        )
        #保存模型
        checkpoint = {
            "model": model.state_dict(),
            "epoch": epoch,
        }
        torch.save(checkpoint,f"{output_dir}/model.pth")
