/*
You are given two integer arrays nums1 and nums2, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in ascending order. 

Example input:
3
1 2 3
3
2 5 6

Answer:
1 2 2 3 5 6
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int limit = min(m,n);
        vector<int> vi;
        
        int i = 0;
        int j = 0;
        int k = 0;
        for(k = 0; k < m+n; k++) {
            if(i < m && j < n) {
                
                if(nums1[i] < nums2[j]) {
                    vi.push_back(nums1[i++]);
                }
                else {
                    vi.push_back(nums2[j++]);
                }
            }
            else {
                break;
            }
        }
        
        while(i < m) {
            vi.push_back(nums1[i++]);
            
        }
        while(j < n) {
            vi.push_back(nums2[j++]);
        }
        
        return vi;
        
    }
};


int main() {

    int n,m;
    cin >> m;
    vector<int> v1;
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        v1.push_back(k);
    }

    cin >> n;
    vector<int> v2;
    for(int j = 0; j < n; j++) {
        int k;
        cin >> k;
        v2.push_back(k);
    }

    Solution sol;
    vector<int> res = sol.merge(v1,m,v2,n);
    for(auto x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}