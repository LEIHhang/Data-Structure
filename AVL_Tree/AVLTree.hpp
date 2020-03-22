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

	AVLTreeNode(const pair<K, V>& kv)
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
		//进行平衡处理
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf += 1;
			}
			else
			{
				parent->_bf -= 1;
			}
			if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//旋转处理
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				break;
			}
			else
			{
				break;
			}
		}
		return pair<Node*, bool>(cur, true);
	}
	void RotateL(Node* parent)
	{
		//左单旋
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		Node* parent_par = parent->_parent;
		
		if (parent_par == nullptr)
		{
			_root=subR;
			subR->_parent = nullptr;
		}
		else
		{
			subR->_parent = parent_par;
			if (parent_par->_right == parent)
			{
				parent_par->_right = subR;
			}
			else
			{
				parent_par->_left = subR;
			}
		}
		parent->_parent = subR;
		parent->_bf = 0;
		subR->_bf = 0;
	}
	void RotateR(Node* parent)
	{
		//右单旋
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		subL->_right = parent;
		Node* parent_par = parent->_parent;
		if (parent_par == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			subL->_parent = parent_par;
			if (parent_par->_right == parent)
			{
				parent_par->_right = subL;
			}
			else
			{
				parent_par->_left = subL;
			}
		}
		parent->_parent = subL;
		parent->_bf = 0;
		subL->_bf = 0;
	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);
		if (bf == 1)
		{
			subRL->_bf = 0;
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if (bf == -1)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 0)
		{
			subRL->_bf = 0;
			parent = 0;
			subR->_bf = 0;
		}
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(subL);
		RotateR(parent);
		if (bf == 1)
		{
			parent->_bf = -1;
			subL->_bf = 0;
			subLR = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subL->_bf = 1;
			subLR->_bf = 0;
		}
		else if (bf==0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
	}
private:
	Node* _root = nullptr;
};