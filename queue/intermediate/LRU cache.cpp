class LRUCache
{
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mymap;

    void refreshPosition(int key, int value)
    {
        cache.erase(mymap[key]);
        cache.push_front(make_pair(key, value));
        mymap[key] = cache.begin();
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (mymap.find(key) == mymap.end())
        {
            return -1;
        }
        else
        {
            int value = (*mymap[key]).second;
            refreshPosition(key, value);
            return value;
        }
    }

    void put(int key, int value)
    {
        if (mymap.find(key) != mymap.end())
        {
            refreshPosition(key, value);
        }
        else
        {
            cache.push_front(make_pair(key, value));
            mymap[key] = cache.begin();
            if (mymap.size() > cap)
            {
                mymap.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */