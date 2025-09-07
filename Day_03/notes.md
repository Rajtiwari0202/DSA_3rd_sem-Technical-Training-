📘 Problem 1: Majority Element

Statement:
Given an array nums of size n, return the majority element (element that appears more than ⌊n/2⌋ times). It is guaranteed to exist.

Approaches

1. Brute Force

For each element, count occurrences with inner loop.

Time: O(n²)

Space: O(1)

2. HashMap

Use map to count frequency.

Return element with frequency > n/2.

Time: O(n)

Space: O(n)

3. Sorting

Sort array, majority element will be at middle index.

Time: O(n log n)

Space: O(1)

4. Boyer-Moore Majority Vote (Optimal)

Maintain candidate + counter.

First pass: find candidate.

Second pass: verify.

Time: O(n)

Space: O(1)

📘 Problem 2: Group Anagrams

Statement:
Given an array of strings, group the anagrams together. Return groups in any order.

Approaches

1. Brute Force (Check each string against others)

Compare every pair by sorting or frequency.

Time: O(n² * k log k) where k = word length.

2. Sorting Key

Sort each string → use as key in hashmap.

Group words with same sorted form.

Time: O(n * k log k)

Space: O(nk)

3. Frequency Count Key

Use a 26-length frequency vector as key.

Faster than sorting for long strings.

Time: O(n * k)

Space: O(nk)

Longest Consecutive Sequence

Problem:
Given an unsorted array nums, find the length of the longest consecutive sequence.

Approaches

1. Brute Force (Simple, Slow)

Idea: For every number, try to build a consecutive sequence starting from it: check num+1, num+2, … until the sequence breaks.

Time Complexity: O(n²)

Space Complexity: O(1)

Notes: Simple to implement but very slow for large arrays.

2. Sort then Scan (Better than Brute Force)

Idea:

Sort the array.

Walk through the sorted list and count runs of consecutive numbers.

Skip duplicates — they don’t break a run but shouldn’t be counted twice.

Time Complexity: O(n log n)

Space Complexity: O(1) (if in-place sort)

Notes: Easy and much faster than brute force, but not linear.

3. HashSet / O(n) Solution (Recommended)

Idea:

Put all numbers into a hash set for O(1) lookup.

Only start building a sequence if the current number is the start of a sequence (num-1 not in set).

Count consecutive numbers (num+1, num+2, …) until the sequence ends.

Time Complexity: O(n)

Space Complexity: O(n)

Notes: Each number is part of at most one sequence expansion, so this approach is linear and optimal.

Hashing

Definition:
Hashing is a technique to map data of arbitrary size to fixed-size values (hashes) using a hash function. These hashes are used to store and retrieve data efficiently.

Key Points:

Provides O(1) average time for search, insert, and delete.

Common data structures:

unordered_map / unordered_set in C++

Hash tables in general

Collisions: Occur when two keys map to the same hash; handled by chaining or open addressing.

Applications in DSA problems:

Counting frequency of elements (Majority Element, Contains Duplicate)

Grouping items by key (Group Anagrams)

Checking existence quickly (Longest Consecutive Sequence)

Example Use Cases from Day3 Problems:

Majority Element: Use unordered_map to count occurrences in O(n)

Group Anagrams: Use sorted string or frequency array as hash key

Longest Consecutive Sequence: Store numbers in unordered_set to check presence in O(1)

Notes / Tips:

Hashing reduces nested loops to single-pass solutions.

Always check for collisions when designing custom hash functions.

Perfect for problems where lookup speed matters more than ordering.