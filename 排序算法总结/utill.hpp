#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
inline vector<int> GetArr()
{
	vector<int> arr;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 100);//插入一个[0,100)的随机数
	}
	return arr;
}
void BubbleSort(vector<int>& arr);
void BubbleSort_flag(vector<int>& arr);
void ChooseSort(vector<int>& arr);
void InsertSort(vector<int>& arr);