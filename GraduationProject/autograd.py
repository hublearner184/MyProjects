import torch

#============================requires_grad=============================
flag = False
if flag:
    w = torch.tensor([1.],requires_grad = True)
    x = torch.tensor([2.],requires_grad = True)

    a = torch.add(w,x)
    b = torch.add(w,1)
    y = torch.mul(a,b)

    y.backward(retain_graph = True)
    print(w.grad)
    y.backward()

#============================grad_tensors==============================
flag = False
if flag:
    w = torch.tensor([1.],requires_grad = True)
    x = torch.tensor([2.],requires_grad = True)

    a = torch.add(w,x)
    b = torch.add(w,1)

    y0 = torch.mul(a,b)
    y1 = torch.add(a,b)
    
    loss = torch.cat([y0,y1],dim=0)
    grad_tensors = torch.tensor([1.,2.])

    loss.backward(gradient = grad_tensors)

    print(w.grad)

#============================create_graph==============================
flag = False
if flag:
    x = torch.tensor([3.],requires_grad = True)
    y = torch.pow(x,2)

    grad_1 = torch.autograd.grad(y,x,create_graph = True)
    print(grad_1)
    grad_2 = torch.autograd.grad(grad_1[0],x)
    print(grad_2)
#=============================tips_1=====================================
flag = False
if flag:
    w = torch.tensor([1.],requires_grad = True)
    x = torch.tensor([2.],requires_grad = True)

    for i in range(4):
        a = torch.add(w,x)
        b = torch.add(w,1)
        y = torch.mul(a,b)

        y.backward()
        print(w.grad)

        w.grad.zero_()
#===========================step 1/5 生成数据==============================
sample_nums = 100
mean_value = 1.7
bias = 1
n_data = torch.ones(sample_nums, 2)
x0 = torch.normal(mean_value * n_data, 1) + bias
y0 = torch.zeros(sample_nums)
x1 = torch.normal(-mean_value * n_data, 1) + bias
y1 = torch.ones(sample_nums)
train_x = torch.cat((x0,x1),0)
train_y = torch.cat((y0,y1),0)
#========================step 2/5 选择模型============================
class LR(nn.Module):
    def __init__(self):
        super(LR,self).__init__()
        self.features = nn.Linear(2,1)
        self.sigmoid = nn.Sigmoid()


    def forward(self,x):
        x = self.features(x)
        x = self.sigmoid(x)
        return x
lr_net = LR()#实例化逻辑回归模型
#===========================step 3/5 选择损失函数===========================
loss_fn = nn.BCELoss()

#===========================step 4/5 选择优化器=========================
lr = 0.01
optimizer = torch.optim.SGD(lr_net.parameters(), lr = lr, momentum = 0.9)
#==========================step 5/5 模型训练==============================
for iteration in range(1000):

    #前向传播
    y_pred = lr_net(train_x)

    #计算loss
    loss = loss_fn(y_pred.squeeze(),train_y)

    #计算反向传播
    loss.backward()

    #更新参数
    optimizer.step()

    #清空梯度
    optimizer.zero_grad()

    #绘图
    if iteration % 20 == 0:

        mask = y_pred.ge(0.5).float().squeeze() #以0.5的阈值进行分类
        correct = (mask == train_y).sum() #计算正确预测的样本个数
        