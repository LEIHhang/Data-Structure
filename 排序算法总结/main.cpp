#pragma once
#include"utill.hpp"

void TestBubbleSort(vector<int>& arr)
{
	cout << "当前数组元素:";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	BubbleSort_flag(arr);
	cout << "排序后数组:";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void TestChooseSort(vector<int>& arr)
{
	cout << "当前数组元素:";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	ChooseSort(arr);
	cout << "排序后数组:";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void TestInsertSort(vector<int>& arr)
{
	cout << "当前数组元素:";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	InsertSort(arr);
	cout << "排序后数组:";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void TestHeapSort(vector<int>& arr)
{
	cout << "当前数组元素:";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	HeapSort(arr);
	cout << "排序后数组:";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	vector<int> arr = GetArr();
	TestHeapSort(arr);
}