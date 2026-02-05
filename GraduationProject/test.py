import torch

print(f"PyTorch 版本: {torch.__version__}")
print(f"显卡是否可用: {torch.cuda.is_available()}")
if torch.cuda.is_available():
    print(f"正在使用的 GPU: {torch.cuda.get_device_name(0)}")
    # 创建一个张量并移动到 GPU
    x = torch.randn(1).to("cuda")
    print("GPU 张量计算测试成功！")