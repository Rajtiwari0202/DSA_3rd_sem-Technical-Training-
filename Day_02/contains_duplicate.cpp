#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force O(n^2)
bool containsDuplicateBrute(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}

// Approach 2: Sorting O(n log n)
bool containsDuplicateSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) return true;
    }
    return false;
}

// Approach 3: HashSet O(n)
bool containsDuplicateSet(vector<int>& nums) {
    unordered_set<int> seen;
    for (int x : nums) {
        if (seen.count(x)) return true;
        seen.insert(x);
    }
    return false;
}

// Approach 4: HashMap O(n)
bool containsDuplicateMap(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int x : nums) {
        freq[x]++;
        if (freq[x] > 1) return true;
    }
    return false;
}

// Approach 5: Length Trick O(n)
bool containsDuplicateLength(vector<int>& nums) {
    unordered_set<int> unique(nums.begin(), nums.end());
    return unique.size() < nums.size();
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4};      // No duplicates
    vector<int> nums2 = {1, 2, 3, 1};      // Has duplicates

    cout << "Testing nums1 = {1,2,3,4}\n";
    cout << "Brute Force: " << containsDuplicateBrute(nums1) << endl;
    cout << "Sorting: " << containsDuplicateSort(nums1) << endl;
    cout << "HashSet: " << containsDuplicateSet(nums1) << endl;
    cout << "HashMap: " << containsDuplicateMap(nums1) << endl;
    cout << "Length Trick: " << containsDuplicateLength(nums1) << endl;

    cout << "\nTesting nums2 = {1,2,3,1}\n";
    cout << "Brute Force: " << containsDuplicateBrute(nums2) << endl;
    cout << "Sorting: " << containsDuplicateSort(nums2) << endl;
    cout << "HashSet: " << containsDuplicateSet(nums2) << endl;
    cout << "HashMap: " << containsDuplicateMap(nums2) << endl;
    cout << "Length Trick: " << containsDuplicateLength(nums2) << endl;

    return 0;
}

