# 992. Subarrays with K Different Integers

## 📋 Problem Description

**Problem Number**: 992  
**Difficulty**: Hard  
**LeetCode Link**: [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)  
**Level**: 🧪 Level 5: Non-obvious sliding window (The "At Most K" Trick)

---

### Problem Statement

Given an integer array `nums` and an integer `k`, return the number of **good subarrays** of `nums`.
A **good subarray** is an array where the number of different integers in that array is exactly `k`.

---

### Examples

#### Example 1
**Input**: `nums = [1,2,1,2,3], k = 2`  
**Output**: `7`  
**Explanation**: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].

#### Example 2
**Input**: `nums = [1,2,1,3,4], k = 3`  
**Output**: `3`  
**Explanation**: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

---

## 💡 Approach: The "At Most K" Trick

This is the definitive problem for the "At Most K" strategy. Directly finding "Exactly K" distinct elements with a sliding window is difficult because the window doesn't shrink monotonically in a way that helps count "exactly."



### The Mathematical Insight
To find the number of subarrays with **exactly** $K$ distinct elements, we use:
$$\text{Exactly}(K) = \text{AtMost}(K) - \text{AtMost}(K - 1)$$

### Why `count += j - i + 1`?
In the `atMostK` function, when the window `[i, j]` is valid (has $\le K$ distinct elements), every subarray ending at `j` and starting at any index from `i` to `j` is also valid. 
- Example: If `[1, 2, 3]` is valid for $K=3$, then `[3]`, `[2, 3]`, and `[1, 2, 3]` are all valid. 
- There are exactly `j - i + 1` such subarrays.

---

## ⚡ Complexity Analysis

* **Time Complexity**: $O(N)$ — We call `atMostK` twice. Each call processes the array in linear time.
* **Space Complexity**: $O(K)$ — The hash map stores at most $K+1$ elements at any time.

---

**Pattern**: Sliding Window (Variable Size) + Counting Trick  
**Date Solved**: January 10, 2026
