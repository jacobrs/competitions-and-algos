#include <map>
#include <vector>

using namespace std;

class RandomizedCollection {
public:

    map<int, int> arr;
    vector<int> cache;
    bool rebuild;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        rebuild = true;
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        rebuild = true;
        if(arr.find(val) == arr.end()){
            arr.insert({val, 1});
            return true;
        }else{
            arr[val] ++;
            return false;
        }
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        rebuild = true;
        if(arr.find(val) != arr.end()){
            arr[val] --;
            if(arr[val] <= 0){
                arr.erase(val);
            }
            return true;
        }
        return false;

    }

    /** Get a random element from the collection. */
    int getRandom() {
        if(rebuild){
            cache.clear();
            for(auto elem : arr){
                for(int j = 0; j < elem.second; j++){
                    cache.push_back(elem.first);
                }
            }
        }
        int r = rand() % cache.size();
        return cache[r];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */