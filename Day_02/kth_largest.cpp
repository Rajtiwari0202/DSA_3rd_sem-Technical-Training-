#include <bits/stdc++.h>
using namespace std;

// Approach 1: Sorting
int kthLargestSort(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k-1];
}

// Approach 2: Min-Heap (size k)
int kthLargestMinHeap(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int num : nums) {
        pq.push(num);
        if (pq.size() > k) pq.pop();
    }
    return pq.top();
}

// Approach 3: Max-Heap
int kthLargestMaxHeap(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k-1; i++) pq.pop();
    return pq.top();
}

// Partition helper for Quickselect
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (nums[j] >= pivot) { // note: >= for kth largest
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}

// Approach 4: Quickselect
int quickselect(vector<int>& nums, int left, int right, int k) {
    if (left == right) return nums[left];
    int pivotIndex = partition(nums, left, right);
    if (pivotIndex == k) return nums[pivotIndex];
    else if (pivotIndex > k) return quickselect(nums, left, pivotIndex-1, k);
    else return quickselect(nums, pivotIndex+1, right, k);
}

int kthLargestQuickselect(vector<int> nums, int k) {
    return quickselect(nums, 0, nums.size()-1, k-1);
}

// Driver Code
int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    cout << "Array = {3,2,1,5,6,4}, k=2\n";
    cout << "Sorting: " << kthLargestSort(nums, k) << endl;
    cout << "Min-Heap: " << kthLargestMinHeap(nums, k) << endl;
    cout << "Max-Heap: " << kthLargestMaxHeap(nums, k) << endl;
    cout << "Quickselect: " << kthLargestQuickselect(nums, k) << endl;

    return 0;
}
