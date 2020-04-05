#pragma once
#include<vector>
#include<iostream>
using namespace std;
namespace Hash_Close
{
	enum State
	{
		EMPTY,
		EXITES,
		DELETE,
	};
	template<class T>
	class HashData
	{
	public:
		T _data;
		State _state = EMPTY;
	};
	template<class K, class V>
	class HashTable
	{
	public:
		//����λ����Ϣ��������Ϣ�Ĺ�ϵӳ�䣬�����ݷ��뵽�����С�
		typedef HashData<pair<K, V>> HashData;
		pair<HashData*, bool> Insert(pair<K, V> _kv)
		{
			//1.�������Ԫ�������ˣ���ô��
			if (_dataNum == _hashtable.size())
			{
				//����һ���¶��󣬽�ԭ��_hashtable�е���������������¶���_hashTable��
				//����´����Ķ����ڵ�����ӳ�䵽Ŀǰ��_hashtable
				int newSize = _dataNum == 0 ? 10 : _dataNum * 2;
				HashTable NewHTB;
				NewHTB._hashtable.resize(newSize);
				for (int i = 0; i < _hashtable.size(); ++i)
				{
					if(_hashtable[i]._state==EXITES)
						NewHTB.Insert(_hashtable[i]._data);
				}
				_hashtable.swap(NewHTB._hashtable);
			}
			//2.������ͬ����

			int index = _kv.first % _hashtable.size();//��ȡӳ��λ��
			while (_hashtable[index]._state != EMPTY)
			{
				++index;
				if (index == _hashtable.size())
					index = 0;
				if (_kv.first == _hashtable[index]._data.first)
				{
					return make_pair(&_hashtable[index], false);
				}
			}
			_hashtable[index]._data = _kv;
			_hashtable[index]._state = EXITES;
			++_dataNum;
			return make_pair(&_hashtable[index], true);
		}
		HashData* Find(const K& key)
		{
			int index = key % _hashtable.size();
			
			while(_hashtable[index]._state!=EMPTY)
			{
				if (_hashtable[index]._data.first == key)
					return &_hashtable[index];
				else
					++index;
				if (index == _hashtable.size())
					index = 0;
			}

			return nullptr;
		}
		void Erase(const K& key)
		{
			HashData* ret = Find(key);
			if (ret)
				ret->_state = DELETE;
		}

		V& operator [](const K& key)
		{
			pair<HashData*, bool> ret = Insert(make_pair(key, V()));
			return ret.first->_data.second;
			
		}
	private:
		vector<HashData> _hashtable;
		size_t _dataNum;//��Ч���ݵĸ���
	};
	void Test()
	{
		HashTable<int,int> hashTable;
		hashTable.Insert(make_pair(2, 3));
		hashTable.Insert(make_pair(1, 3));
		hashTable.Insert(make_pair(3, 3));
		hashTable.Insert(make_pair(5, 3));
		hashTable.Insert(make_pair(6, 3));
		hashTable.Insert(make_pair(7, 3));
		hashTable.Insert(make_pair(8, 3));
		hashTable.Insert(make_pair(9, 3));
		hashTable.Insert(make_pair(11, 3));
		hashTable.Insert(make_pair(13, 3));

		hashTable.Insert(make_pair(17, 3));
		hashTable.Insert(make_pair(19, 3));
		hashTable.Insert(make_pair(120, 3));
		hashTable.Insert(make_pair(16, 3));
		hashTable.Insert(make_pair(16, 3));
	}
}
