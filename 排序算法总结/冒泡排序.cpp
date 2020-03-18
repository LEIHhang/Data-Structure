#include"utill.hpp"

void BubbleSort(vector<int>& arr)
{

	for (int j = 0; j < arr.size(); j++)
	{
		printf("第%d次遍历交换:\n", j + 1);
		for (int i = 0; i < arr.size() - 1 - j; i++)
		{
			if (arr[i]>arr[i + 1])
			{
				printf("交换第%d位(%d)和%d位(%d):\n", i, arr[i], i + 1, arr[i + 1]);
				std::swap(arr[i], arr[i + 1]);
			}
		}
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}
void BubbleSort_flag(vector<int>& arr)
{

	for (int j = 0; j < arr.size(); j++)
	{
		printf("第%d次遍历交换:\n", j + 1);
		int  flag = 0;
		for (int i = 0; i < arr.size() - 1 - j; i++)
		{
			if (arr[i]>arr[i + 1])
			{
				flag++;
				printf("交换第%d位(%d)和%d位(%d):\n", i, arr[i], i + 1, arr[i + 1]);
				std::swap(arr[i], arr[i + 1]);
			}
		}
		if (flag == 0)
			break;
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}