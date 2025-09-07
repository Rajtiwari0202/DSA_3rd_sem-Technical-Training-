#include <bits/stdc++.h>
using namespace std;

// Brute Force O(n^2)
int majorityBrute(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) count++;
        }
        if (count > n/2) return nums[i];
    }
    return -1;
}

// HashMap O(n)
int majorityHash(vector<int>& nums) {
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;
    for (auto& [val, cnt] : freq) {
        if (cnt > nums.size()/2) return val;
    }
    return -1;
}

// Sorting O(n log n)
int majoritySort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2]; // guaranteed majority
}

// Boyer-Moore O(n)
int majorityBoyerMoore(vector<int>& nums) {
    int count = 0, candidate = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    // optional verification
    return candidate;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << "Brute Force: " << majorityBrute(nums) << endl;
    cout << "HashMap: " << majorityHash(nums) << endl;
    cout << "Sorting: " << majoritySort(nums) << endl;
    cout << "Boyer-Moore: " << majorityBoyerMoore(nums) << endl;
    return 0;
}
