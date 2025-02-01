//Problem Statement: Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int size;

    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            l.splice(l.begin(), l, m[key]);
            m[key]->second = value;
            return;
        }
        if (l.size() == size) {
            auto d_key = l.back().first;
            l.pop_back();
            m.erase(d_key);
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; 
    cache.put(3, 3);               
    cout << cache.get(2) << endl; 
    cache.put(4, 4);               
    cout << cache.get(1) << endl; 
    cout << cache.get(3) << endl; 
    cout << cache.get(4) << endl; 
    return 0;
}
