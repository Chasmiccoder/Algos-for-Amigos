/*
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.
*/

#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Using Kadane's Algorithm
        
        int len = nums.size();
        
        int result = INT_MIN;
        int maxCurrent = 0;
        
        for(int i = 0; i < len; i++) {
            maxCurrent = maxCurrent + nums[i];
            if(maxCurrent > result) {
                result = maxCurrent;
            }
            if(maxCurrent < 0) {
                maxCurrent = 0;
            }
        }
        return result;
    }
};


int main() {
    int n;
    scanf("%d", &n);
    vector<int> vi;
    for(int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        vi.push_back(k);
    }

    Solution sol;
    cout << sol.maxSubArray(vi);
    return 0;
}