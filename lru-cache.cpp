#include <iostream>
#include <queue>

using namespace std;

class LRUCache
{
public:
    class Item
    {
    private:
        int _key, _value, _lastAccessed;

    public:
        Item(int key, int value, int lastAccessed)
            : _key(key),
              _value(value),
              _lastAccessed(lastAccessed)
        {
        }
        int getKey() { return _key; }
        int getValue() { return _value; }
        int getLastAccessed() { return _lastAccessed; }
        void setKey(int key) { _key = key; }
        void setValue(int value) { _value = value; }
        void setLastAccessed(int lastAccessed) { _lastAccessed = lastAccessed; }
        bool operator<(Item *rhs)
        {
            return _lastAccessed < rhs->_lastAccessed;
        }

        friend class LRUCache;
    };

    LRUCache(int capacity)
    {
    }

    int get(int key)
    {
    }

    void put(int key, int value)
    {
    }

private:
    priority_queue<Item *> q;
};

int main()
{
    LRUCache *obj = new LRUCache(2);
    return 0;
}