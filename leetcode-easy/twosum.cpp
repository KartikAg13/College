#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<int> result;
        if(length >= 2 && length <= 10000) {
            map<int, int> pairing;
            auto it = pairing.begin();
            int index = 0;
            for(index = 0; index < length; index++)
                pairing[nums[index]] = index;
            for(index = 0; index < length; index++) {
                it = pairing.find(target - nums[index]);
                if(it != pairing.end() && it->second != index) {
                    result.push_back(index);
                    result.push_back(it->second);
                    return result;
                }
            }
        }
        return result;
    }
};