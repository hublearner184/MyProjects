#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> nums;

int main()
{
    int n = 10;

    vector<int> nums(n);
   
    cout << nums.empty() << endl;

    cout << nums.size() << endl;

    nums.push_back(20);//在末尾添加元素

    cout << nums.size() << endl;

    cout << nums.back() << endl;//返回最后一个元素

    nums.pop_back();//删除最后一个元素

    nums[0] = 11;

    cout << nums[0] << endl;

    nums.insert(nums.begin() + 3,99);//在指定位置插入元素

    nums.erase(nums.begin() + 2);//删除指定位置元素

    swap(nums[0],nums[1]);//交换两个元素

    for(int i = 0;i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;


}