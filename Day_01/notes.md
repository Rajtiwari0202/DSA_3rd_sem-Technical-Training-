# Day 1 - Technical Training Notes

## Problem 1: Two Sum

### Problem Statement
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

---

### Approach 1: Brute Force
- **Idea**: Check every pair `(i, j)` and see if `nums[i] + nums[j] == target`.
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Notes**: Very simple but slow.

---

### Approach 2: Sorting + Two Pointers
- **Idea**:
  - First, sort the array.
  - Use two pointers (left and right) to move inward based on the sum.
- **Time Complexity**: O(n log n) (due to sorting)
- **Space Complexity**: O(n) (to keep track of original indices)
- **Notes**: More efficient than brute force, but sorting complicates index tracking.

---

### Approach 3: Hash Map
- **Idea**:
  - Traverse the array, for each element check if `target - nums[i]` exists in a hash map.
  - If it exists, return indices.
  - Otherwise, store the current number with its index.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- **Notes**: Best solution, works in one pass.

---

## Problem 2: 4Sum II

### Problem Statement
You are given four integer arrays `nums1, nums2, nums3, nums4` each of length `n`.  
Return the number of tuples `(i, j, k, l)` such that:

nums1[i] + nums2[j] + nums3[k] + nums4[l] = 0


---

### Approach 1: Brute Force
- **Idea**: Check all quadruples `(i, j, k, l)` using 4 nested loops.
- **Time Complexity**: O(n⁴)
- **Space Complexity**: O(1)
- **Notes**: Not practical for large input sizes.

---

### Approach 2: Hash Map (Optimized)
- **Idea**:
  - Split into two halves:
    - Compute all sums of pairs from `nums1 + nums2` and store in a hash map with frequency.
    - Compute all sums of pairs from `nums3 + nums4`, and check if the negative of this sum exists in the hash map.
  - Add up frequencies for matches.
- **Dry Run Example**:  
  nums1 = [1, 2], nums2 = [-2, -1], nums3 = [-1, 2], nums4 = [0, 2]  
  Final answer = 2
- **Time Complexity**: O(n²)
- **Space Complexity**: O(n²)
- **Notes**: Best approach, reduces complexity drastically.
