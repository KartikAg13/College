#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        map<int, int> indexing;
        int length = prices.size();
        for(int index = 0; index < length; index++)
            indexing[prices[index]] = index;
        sort(indexing.begin(), indexing.end());
        auto start = indexing.begin();
        auto end = indexing.end();
        end--;
        do {
            profit = start->first - end->first;
            if(start->second < end->second)
                return profit;
            else {
                
            }
        } while(1);
        return 0;
    }
};