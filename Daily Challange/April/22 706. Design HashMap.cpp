/*
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.


Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]


Constraints:

0 <= key, value <= 106
At most 104 calls will be made to put, get, and remove.

*/
#include <bits/stdc++.h>
using namespace std;
class MyHashMap
{
    vector<list<pair<int, int>>> m_data;
    size_t m_size = 10000;

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        m_data.resize(m_size);
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        auto &list = m_data[key % m_size];
        for (auto &val : list)
        {
            if (val.first == key)
            {
                val.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        const auto &list = m_data[key % m_size];
        if (list.empty())
        {
            return -1;
        }
        for (const auto &val : list)
        {
            if (val.first == key)
            {
                return val.second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        auto &list = m_data[key % m_size];
        list.remove_if([key](auto n)
                       { return n.first == key; });
    }
};
int main()
{
}