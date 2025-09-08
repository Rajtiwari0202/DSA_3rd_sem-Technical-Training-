#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------
// Approach 1: Brute Force O(n^3)
// ---------------------------------------------------
int subarraysDivByK_Brute(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int p = i; p <= j; p++) {
                sum += nums[p];
            }
            if (sum % k == 0) count++;
        }
    }
    return count;
}

// ---------------------------------------------------
// Approach 2: Better O(n^2)
// ---------------------------------------------------
int subarraysDivByK_Better(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum % k == 0) count++;
        }
    }
    return count;
}

// ---------------------------------------------------
// Approach 3: Optimal O(n) - Prefix Sum + HashMap
// ---------------------------------------------------
int subarraysDivByK_Optimal(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> freq;
    freq[0] = 1; // base case

    int sum = 0, count = 0;

    for (int num : nums) {
        sum += num;
        int rem = sum % k;

        // handle negative remainders
        if (rem < 0) rem += k;

        if (freq.find(rem) != freq.end()) {
            count += freq[rem];
        }

        freq[rem]++;
    }

    return count;
}

// ---------------------------------------------------
// Driver code
// ---------------------------------------------------
int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    cout << "Brute Force (O(n^3)): " << subarraysDivByK_Brute(nums, k) << endl;
    cout << "Better (O(n^2)): " << subarraysDivByK_Better(nums, k) << endl;
    cout << "Optimal (O(n)): " << subarraysDivByK_Optimal(nums, k) << endl;

    return 0;
}
