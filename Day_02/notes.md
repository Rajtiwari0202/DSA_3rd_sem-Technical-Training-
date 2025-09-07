📘 Day 2 – 
Problem - 1: Contains Duplicate

Problem:
Given an integer array, return true if any value appears at least twice, otherwise return false.

Approaches

1. Brute Force

Compare every element with every other element.

Time: O(n²)

Space: O(1)

Easy but too slow for large inputs.

2. Sorting

Sort the array, then check adjacent elements.

Time: O(n log n)

Space: O(1) (in-place) or O(n) (if not in-place).

More efficient, but sorting dominates runtime.

3. HashSet

Insert elements into a set.

If element already exists, return true.

Time: O(n) average, O(n²) worst if hash collisions.

Space: O(n)

4. HashMap

Similar to HashSet but store frequency counts.

Return true if count > 1.

Time: O(n)

Space: O(n)

5. Length Trick (Set Size)

Convert array into a set.

If length of set < length of array, duplicates exist.

Time: O(n)

Space: O(n)

Concise but builds entire set even if duplicate found early.

Comparison Table
Approach	Best Case	Worst Case	Avg Case	Notes
Brute Force	O(1)	O(n²)	O(n²)	Very slow for large n
Sorting	O(n log n)	O(n log n)	O(n log n)	Sorting dominates runtime
HashSet	O(1)	O(n)	O(n)	Fast, early exit possible
HashMap	O(1)	O(n)	O(n)	Similar to HashSet
Length Trick	O(n)	O(n)	O(n)	Must build full set, no early exit

📘 Problem 2: Kth Largest Element in an Array

Given an integer array nums and an integer k, return the k-th largest element in the array.
(Not necessarily distinct, but by order in sorted array).

Example:nums = [3,2,1,5,6,4], k = 2
Output = 5

Approaches

1. Brute Force (Sorting Descending)

Sort array in descending order.

Return element at index k-1.

Time: O(n log n)

Space: O(1)

2. Min-Heap (Priority Queue)

Maintain a min-heap of size k.

Push elements one by one.

If heap size > k, pop smallest.

At end, heap top = kth largest.

Time: O(n log k)

Space: O(k)

3. Max-Heap (Priority Queue)

Push all elements into max-heap.

Pop k-1 times.

Top = kth largest.

Time: O(n + k log n)

Space: O(n)

4. Quickselect (Hoare’s Selection Algorithm)

Partition like QuickSort.

Only recurse into side containing k.

Avg Time: O(n)

Worst Time: O(n²) (rare).

Space: O(1)

Comparison Table
Approach	Best Case	Worst Case	Avg Case	Notes
Sorting	O(n log n)	O(n log n)	O(n log n)	Simple, reliable
Min-Heap	O(n log k)	O(n log k)	O(n log k)	Efficient for large n, small k
Max-Heap	O(n) + O(k log n)	O(n + k log n)	O(n + k log n)	Good but heavier than min-heap
Quickselect	O(n)	O(n²)	O(n)	Most optimal on average