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