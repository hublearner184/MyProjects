import numpy as np
import torch
#arr = np.ones((3,3))
#print(arr)

#t = torch.tensor(arr)
#print(t)
#a = torch.tensor(arr,device = 'cuda')
#print(a)
out_t = torch.tensor([1]) 
print(out_t)
t = torch.zeros((3,3),out = out_t)
print(t)
print(out_t)