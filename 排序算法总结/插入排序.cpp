#include"utill.hpp"
void InsertSort(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		//�ӵڶ���Ԫ�ؿ�ʼ����
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