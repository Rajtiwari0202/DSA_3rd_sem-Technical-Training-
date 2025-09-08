Day 4 – Problem 1: Subarray Sum Equals K

Problem:
Given an integer array nums and an integer k, return the total number of subarrays whose sum equals k.

Approach 1: Brute Force (O(n³))

Idea:

Consider all possible subarrays (i, j).

For each subarray, calculate the sum by looping through all elements.

If the sum equals k, increase the counter.

Complexity:

Time: O(n³) (two loops for subarray + one loop for sum)

Space: O(1)

Notes: Very slow, recomputes sums repeatedly.

Approach 2: Better – Running Sum (O(n²))

Idea:

Fix a starting index i.

Maintain a running sum as we expand the subarray ending at j.

Whenever the running sum equals k, increment the count.

Complexity:

Time: O(n²)

Space: O(1)

Notes: Much faster than brute force, avoids recalculating sums.

Approach 3: Optimal – Prefix Sum + HashMap (O(n))

Idea:

Use prefix sums to represent the sum of elements up to index i.

For each prefix sum currSum, we check if (currSum - k) has appeared before.

If yes, then subarrays between those indices sum to k.

Store prefix sums and their frequencies in a hash map.

Algorithm:

Initialize count = 0, currSum = 0, and a hash map with {0:1} (base case).

Traverse the array:

Update currSum += nums[i].

If (currSum - k) exists in map, add its frequency to count.

Update frequency of currSum in map.

Complexity:

Time: O(n)

Space: O(n)

Notes: This is the fastest and most efficient solution.

Day 4 – Problem 2: Subarray Sums Divisible by K
📌 Problem

We are given an array nums and an integer k. We need to find the number of subarrays whose sum is divisible by k.

🔹 Approaches
Approach 1 — Brute Force (O(n³))

For every subarray (i, j) compute the sum explicitly by looping.

Check if sum % k == 0.

Very slow since it checks all subarrays and recomputes sums again and again.

✅ Time Complexity: O(n³)
✅ Space Complexity: O(1)

Approach 2 — Better (O(n²))

Instead of recomputing sum for every subarray, use a running sum.

For every starting index i, extend subarray to j and keep adding elements.

Check divisibility.

✅ Time Complexity: O(n²)
✅ Space Complexity: O(1)
💡 Much better than brute force, but still slow for large arrays.

Approach 3 — Optimal: Prefix Sum + HashMap (O(n))

Idea: If two prefix sums have the same remainder when divided by k, then the subarray between them is divisible by k.

Use a hashmap to store the frequency of each remainder.

For each new prefix sum remainder rem, add freq[rem] to the answer (because all earlier subarrays with the same remainder can form valid subarrays).

Handle negative remainders by converting them into positive:

    if (rem < 0) rem += k;

✅ Time Complexity: O(n)
✅ Space Complexity: O(k)
💡 Fastest and most memory-efficient approach.
🔹 Example Walkthrough

Input: nums = [4, 5, 0, -2, -3, 1], k = 5

    Prefix sums: [4, 9, 9, 7, 4, 5]

    Remainders (mod 5): [4, 4, 4, 2, 4, 0]

    Count subarrays using hashmap of remainders.

👉 Result = 7
🔹 Comparison Table
Approach	Time Complexity	Space Complexity	Notes
Brute Force	O(n³)	O(1)	Checks all subarrays, recomputes sums
Better	O(n²)	O(1)	Running sum avoids recomputation
Optimal	O(n)	O(k)	Prefix sum + HashMap (best solution)
