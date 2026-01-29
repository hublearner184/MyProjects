#include <iostream>

int main()
{
    int arr[20];
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    
    for(int i = 2; i < 10; i++)
    {
        arr[i] = arr[i + 1];
    }

    for(int i = 10; i > 2; i--)
    {
        arr[i] = arr[i - 1];
    }

}