#include<iostream>
using namespace std;
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode* _left;
	AVLTreeNode* _right;
	AVLTreeNode* _parent;
	pair<K, V> _kv;
	int _bf;

	AVLTreeNode(pair<K, V> kv)
		:_left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _bf(0)
	{}
};
template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	V& operator[](const K& k)
	{
		pair<Node*, bool> ret = Insert(pair<K, V>(k, V()));
		return ret.first->_kv.second;
	}
	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
		}
		Node* cur = _root;
		Node* parent = _root;
		while (cur)
		{
			//当前cur指向结点小于kv，说明kv应该再cur的右子数
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return pair<Node*, bool>(cur, false);
			}
		}
		if (parent->_kv.first < kv.first)
		{
			cur = new Node(kv);
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			cur = new Node(kv);
			parent->_left = cur;
			cur->_parent = parent;
		}
		return pair<Node*, bool>(cur, true);
	}
private:
	Node* _root = nullptr;
};