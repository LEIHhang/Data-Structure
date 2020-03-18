#include"utill.hpp"
void InsertSort(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		//从第二个元素开始插入
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				std::swap(arr[j], arr[j - 1]);
			}
			else
				break;
		}
	}
}