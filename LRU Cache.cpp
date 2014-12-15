struct LRUNode {
	int key, value;
	LRUNode(int k, int v)
	{
		key = k;
		value = v;
	}
};

class LRUCache{
private:
	unordered_map<int, list<LRUNode>::iterator> mapping;
	list<LRUNode> usedList;
	int capacity;

	unordered_map<int, list<LRUNode>::iterator>::iterator mapIter;
	list<LRUNode>::iterator listIter;

	list<LRUNode>::iterator activate(list<LRUNode>::iterator iter)
	{
		list<LRUNode>::iterator newIter = usedList.insert(usedList.begin(), *iter);
		usedList.erase(iter);
		return newIter;
	}
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		mapIter = mapping.find(key);
		if (mapIter != mapping.end())
		{
			mapping[key] = activate(mapIter->second);
			return mapping[key]->value;
		}
		else
			return -1;
	}

	void set(int key, int value) {
		mapIter = mapping.find(key);
		if (mapIter != mapping.end())
		{
			mapping[key] = activate(mapIter->second);
			mapping[key]->value = value;
		}
		else
		{
			if (mapping.size() >= capacity)
			{
				mapping.erase(usedList.back().key);
				usedList.pop_back();
			}
			mapping[key] = usedList.insert(usedList.begin(), LRUNode(key, value));
		}
	}
};