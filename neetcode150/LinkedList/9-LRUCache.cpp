class LRUCache {
private:
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void setMostRecent(list<pair<int, int>>::iterator dllIter)
    {
        dll.splice(dll.end(), dll, dllIter);
    }

    int get(int key) {
        auto foundIter = mp.find(key);

        if (foundIter != mp.end())
        {
            // we found the key in the map
            auto dllIter = foundIter->second;
            setMostRecent(dllIter);
            return dllIter->second;
        }

        return -1;
    }

    void put(int key, int value) {
        auto foundIter = mp.find(key);

        if (foundIter != mp.end())
        {
            // we found the key in the map
            auto dllIter = foundIter->second;
            dllIter->second = value; // update value
            setMostRecent(dllIter);
            return;
        }

        if (dll.size() == capacity)
        {
            auto lru = dll.front();
            mp.erase(lru.first);
            dll.pop_front();
        }

        dll.push_back({key, value});
        mp[key] = prev(dll.end());
    }
};
