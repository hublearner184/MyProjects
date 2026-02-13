import numpy as np
import torch
#arr = np.ones((3,3))
#print(arr)

#t = torch.tensor(arr)
#print(t)
#a = torch.tensor(arr,device = 'cuda')
#print(a)


#out_t = torch.tensor([1]) 
#print(out_t)
#t = torch.zeros((3,3),out = out_t)
#print(t)
#print(out_t)

#t = torch.ones((2,3))
#a = torch.cat([t,t],dim = 0)
#print(a)

#t = torch.ones((2,3))
#a = torch.stack([t,t,t],dim = 1)
#print(a)
#print(a.shape)

#t = torch.randint(0,9,size = (3,3))
#print(t)
#idx = torch.tensor([0,2],dtype = torch.long)
#print(torch.index_select(t,dim = 0,index = idx))

w = torch.tensor([1.],requires_grad = True)
x = torch.tensor([2.],requires_grad = True)

a = torch.add(w,x)
b = torch.add(w,1)
y = torch.mul(a,b)

y.backward()
print(w.grad)
