#include"utill.hpp"
void ChooseSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		int minIndex = i;
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}
		std::swap(arr[i], arr[minIndex]);
	}
}