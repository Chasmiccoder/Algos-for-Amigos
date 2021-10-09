/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays 
and you may return the result in any order.

Example:
nums1 = [1,2,2,1]
nums2 = [2,2,4]

Result = [2,2]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        int limit = len1 + len2;
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        for(k = 0; k < limit; k++) {
            if(i < len1 && j < len2) {
                
                if(nums1[i] == nums2[j]) {
                    res.push_back(nums1[i]);
                    i++;
                    j++;
                }

                else if(nums1[i] > nums2[j]) {
                    j++;
                }

                else {
                    i++;
                }
            }   
        }
        return res;
    }
};

int main() {

    int l1,l2;
    cin >> l1;
    vector<int> v1;
    for(int i = 0; i < l1; i++) {
        int k;
        cin >> k;
        v1.push_back(k);
    }

    cin >> l2;
    vector<int> v2;
    for(int i = 0; i < l2; i++) {
        int k;
        cin >> k;
        v2.push_back(k);
    }

    Solution sol;

    vector<int> result = sol.intersect(v1,v2);
    for(auto x : result) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}