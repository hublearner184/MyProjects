#通过训练好的模型预测图片
import torch
import os
from PIL import Image
from torchvision import models,transforms
from easydict import EasyDict
from torch import nn


if __name__ == "__main__":
    #初始化模型
    norm_mean,norm_std = [0.485,0.456,0.406] , [0.229,0.224,0.225]

    cfg = EasyDict()
    cfg.num_cls = 102
    cfg.transforms = transforms.Compose([
        transforms.Resize((224,224)),
        transforms.ToTensor(),
        transforms.Normalize(norm_mean,norm_std)
    ])

    model = models.resnet18(pretrained = True)
    in_features = model.fc.in_features
    fc = nn.Linear(in_features = in_features,out_features = cfg.num_cls)
    model.fc = fc
    #载入训练好的权重
    model_weights = r"outputs\20260226\model.pth"
    checkpoint = torch.load(model_weights)
    model.load_state_dict(checkpoint["model"])


    #读图-预处理
    data_dir = r"D:\data\flowers_data\valid"
    for img_name in os.list(data_dir):

        img_path = os.path.join(data_dir, img_name)
        img0 = Image.open(img_path).convert("RGB")
            
        img:torch.Tensor = cfg.transforms(img0)

        img = img.unsqueeze(dim=0)

        #推理
        device = torch.device("cuda")
        model.to(device= device)

        model.eval()
        img = img.to(device = device)
        with torch.no_grad():
            output = model(img) #1*102

        _,pred_label = torch.max(output,1)

    #展示
    print(f"path: {img_path},pred label:{int(pred_label)}")
