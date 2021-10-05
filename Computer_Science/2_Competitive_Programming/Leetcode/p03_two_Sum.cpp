/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to a target
You may assume that each input would have exactly one solution, and you may not use the same element twice.

O(nlogn) solution done with vector of pairs and binary search
O(n) solution done with a hash map

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility> //for pair
#include <unordered_map>


using namespace std;

class SolutionNlogN {
public:
    static bool comparison(const pair<int,int> &p1, const pair<int,int> &p2) {
        return (p1.first < p2.first);
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        // O(nlogn) solution
        
        int len = nums.size();
        vector<pair<int,int>> vi;
        for(int i = 0; i < len; i++) {
            pair<int,int> p;
            p.first = nums[i];
            p.second = i;
            vi.push_back(p);
        }
        
        sort(vi.begin(), vi.end(), comparison);
        
        for(int i = 0; i < len; i++) {
            
            int possiblePair = binarySearch(vi, target - vi[i].first, len);
            if(vi[i].second != possiblePair) {
                if( possiblePair != -1) {
                    return {vi[i].second,possiblePair};
                }

            }
            else {
                // when 2x = target
                if(i+1 < len && vi[i].first != vi[i+1].first) {
                    return {vi[i].second, vi[i+1].second};
                }
                
            }
            
        }
        
        return {-1,-1};   
    }
    
    static int binarySearch(vector<pair<int,int>> vi, int x, int len) {
        int ul = (len) - 1;
        int ll = 0;
        
        while(ul >= ll) {
            int mid = (ul+ll)/2;
            if(vi[mid].first == x) {
                return vi[mid].second;
            }
            else if(vi[mid].first > x) {
                ul = mid-1;
            }
            else {
                ll = mid+1;   
            }
        }
        return -1;
    }
    
};

class SolutionN {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        // O(n) solution
        
        int len = nums.size();
        
        unordered_map<int,int> hash;
        
        for(int i = 0; i < len; i++) {
            if(hash.find(nums[i]) == hash.end()) {
                hash[nums[i]] = i;
            }
            else {
                if(nums[i]*2 == target) {
                    return {i,hash[nums[i]]};
                }
            }
            
            if(hash.find(target - nums[i]) != hash.end() && hash.find(nums[i]) != hash.end() && hash[target-nums[i]] != hash[nums[i]] ) {
                return {hash[target-nums[i]], hash[nums[i]]};
            }
            
        }
        return {-1,-1};
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

    int x;
    scanf("%x", &x);

    SolutionNlogN sol1;
    SolutionN sol2;

    vector<int> a1 = sol1.twoSum(vi,x);
    vector<int> a2 = sol2.twoSum(vi,x);

    cout << "O(nlogn): " << a1[0] << " " << a1[1] << endl;
    cout << "O(n): " << a2[0] << " " << a2[1] << endl;

    return 0;
}