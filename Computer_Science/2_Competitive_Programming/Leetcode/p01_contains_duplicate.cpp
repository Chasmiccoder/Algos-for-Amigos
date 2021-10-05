// Program to see if an array contains duplicates

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        int len = nums.size();
        
        for(int i = 0; i < len; i++) {
            
            // if not present
            if ( freq.find(nums[i]) == freq.end() ) {
                freq[nums[i]] = 0;
            }
            else {
                return true;
            }
        }
        return false;
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
    cout << sol.containsDuplicate(vi);

}