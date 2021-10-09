/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and 
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int maxProfit = 0;
        int minimumSoFar = prices[0];
        int len = prices.size();
        
        for(int i = 0; i < len; i++) {
            if(prices[i] < minimumSoFar) {
                minimumSoFar = prices[i];
            }
            if(prices[i]-minimumSoFar > maxProfit) {
                maxProfit = prices[i]-minimumSoFar;
            }
        }
        
        return maxProfit;
        
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> vi;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vi.push_back(k);
    }

    Solution sol;
    cout << sol.maxProfit(vi) << endl;
    return 0;
}