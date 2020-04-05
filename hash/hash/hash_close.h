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
		//按照位置信息和数据信息的关系映射，将数据放入到数组中。
		typedef HashData<pair<K, V>> HashData;
		pair<HashData*, bool> Insert(pair<K, V> _kv)
		{
			//1.如果容器元素填满了，怎么办
			if (_dataNum == _hashtable.size())
			{
				//创建一个新对象，将原先_hashtable中的数据重新隐射进新对象_hashTable中
				//最后将新创建的对象内的数组映射到目前的_hashtable
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
			//2.插入相同数据

			int index = _kv.first % _hashtable.size();//获取映射位置
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
		size_t _dataNum;//有效数据的个数
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
