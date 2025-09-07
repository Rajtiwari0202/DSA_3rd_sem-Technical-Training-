#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force O(n^2)
int longestConsecutiveBrute(vector<int>& nums) {
    int n = nums.size();
    int longest = 0;
    for (int num : nums) {
        int count = 1;
        int current = num;
        while (find(nums.begin(), nums.end(), current + 1) != nums.end()) {
            current++;
            count++;
        }
        longest = max(longest, count);
    }
    return longest;
}

// Approach 2: Sort then Scan O(n log n)
int longestConsecutiveSort(vector<int>& nums) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int longest = 1, count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i-1]) continue; // skip duplicates
        if (nums[i] == nums[i-1] + 1) count++;
        else count = 1;
        longest = max(longest, count);
    }
    return longest;
}

// Approach 3: HashSet O(n)
int longestConsecutiveSet(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;
    for (int num : s) {
        if (!s.count(num - 1)) { // start of sequence
            int current = num;
            int streak = 1;
            while (s.count(current + 1)) {
                current++;
                streak++;
            }
            longest = max(longest, streak);
        }
    }
    return longest;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << "Brute Force: " << longestConsecutiveBrute(nums) << endl;
    cout << "Sort & Scan: " << longestConsecutiveSort(nums) << endl;
    cout << "HashSet (Optimal): " << longestConsecutiveSet(nums) << endl;

    return 0;
}
