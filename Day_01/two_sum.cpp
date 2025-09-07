#include <bits/stdc++.h>
using namespace std;

// Brute Force: O(n^2), O(1)
vector<int> twoSumBrute(vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i] + nums[j] == target){
                return {i, j};
            }
        }
    }
    return {};
}

// Sorting + Two Pointers: O(n log n), O(n)
vector<int> twoSumSorting(vector<int>& nums, int target) {
    vector<pair<int,int>> v;
    for(int i=0;i<nums.size();i++) v.push_back({nums[i], i});
    sort(v.begin(), v.end());
    
    int l=0, r=nums.size()-1;
    while(l<r){
        int sum = v[l].first + v[r].first;
        if(sum == target) return {v[l].second, v[r].second};
        else if(sum < target) l++;
        else r--;
    }
    return {};
}

// Hash Map: O(n), O(n) (Best)
vector<int> twoSumHash(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        int diff = target - nums[i];
        if(mp.count(diff)) return {mp[diff], i};
        mp[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Choose which method to run:
    auto ans = twoSumBrute(nums, target);
    // auto ans = twoSumSorting(nums, target);
    // auto ans = twoSumHash(nums, target);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}

// Problem: https://leetcode.com/problems/two-sum/
// Editorial: https://leetcode.com/problems/two-sum/editorial/