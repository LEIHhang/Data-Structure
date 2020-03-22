//#include"AVLTree.hpp"
#include"RB_Tree.hpp"
//void test1()
//{
//	AVLTree<int,int> a;
//	a.Insert(pair<int, int>(1, 1));
//	a.Insert(pair<int, int>(3, 1));
//	a.Insert(pair<int, int>(2, 1));
//	a[1] = 2;
//
//}
void test2()
{
	RBTree<int,int> a;
	a.Insert(pair<int, int>(1, 1));
	a.Insert(pair<int, int>(3, 1));
	a.Insert(pair<int, int>(2, 1));

}
int main()
{
	test2();
}