#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------
// Approach 1: Brute Force O(n^3)
// ---------------------------------------------------
int subarraySumBrute(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int p = i; p <= j; p++) {
                sum += nums[p];
            }
            if (sum == k) count++;
        }
    }
    return count;
}

// Approach 2: Better - Running Sum O(n^2)
int subarraySumBetter(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == k) count++;
        }
    }
    return count;
}

// Approach 3: Optimal - Prefix Sum + HashMap O(n)
int subarraySumOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0, currSum = 0;
    unordered_map<int, int> freq;

    freq[0] = 1; // base case

    for (int num : nums) {
        currSum += num;

        // check if (currSum - k) exists
        if (freq.find(currSum - k) != freq.end()) {
            count += freq[currSum - k];
        }

        // update frequency of currSum
        freq[currSum]++;
    }

    return count;
}
int main() {
    vector<int> nums = {1, 2, 3, -2, 5, 1, 2};
    int k = 5;

    cout << "Brute Force (O(n^3)): " << subarraySumBrute(nums, k) << endl;
    cout << "Better (O(n^2)): " << subarraySumBetter(nums, k) << endl;
    cout << "Optimal (O(n)): " << subarraySumOptimal(nums, k) << endl;

    return 0;
}
