#include"UnorderedMap.h"
using namespace lei;
#include<iostream>
#include<utility>
int main()
{
	unordered_map<int, int> my_map;
	my_map.insert(std::make_pair(1, 1));
	my_map.insert(std::make_pair(2, 1));
	my_map.insert(std::make_pair(3, 1));
	my_map.insert(std::make_pair(4, 1));
	my_map.insert(std::make_pair(4, 1));
	unordered_map<int, int>::Iterator it = my_map.begin();
	unordered_map<int, int>::Iterator eit = my_map.end();
}