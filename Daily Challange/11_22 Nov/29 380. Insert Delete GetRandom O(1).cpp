/*
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

 

Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
 

Constraints:

-231 <= val <= 231 - 1
At most 2 * 105 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.

*/
#include <bits/stdc++.h>
using namespace std;
class RandomizedSet {
    unordered_map<int,int> mp;
    vector<int> vec;

public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /* Using the map, we keep track of the indices (inside the array) where the elements are insertd, so that the 
    random access can easily be handled. So, we insert vec.size() as the value, and 'val' as the key */
    bool insert(int val) {
        if(mp.count(val)) return false;
        mp[val]=vec.size();
        vec.push_back(val);
        return true;
    }
    

    /* While removing an element we need to rearrange the array, as any element from any index can be deleted, so 
    in order to delete the last element only (as it will cause lesser TC for array) we copy the value of the last 
    element to the position from where the current element will be deleted. And hence the tracking in 'mp' got 
    distured by the shifting so we need to update this one also.   */
    bool remove(int val) {
        if(mp.count(val)==0) return false;

        int curPos=mp[val], lastPos=vec.size()-1;
        vec[curPos]=vec[lastPos];  
        mp[vec[lastPos]]=curPos;

        vec.pop_back();
        mp.erase(val);
        return true;
    }

    
    int getRandom() {
        return vec[rand()%mp.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
}