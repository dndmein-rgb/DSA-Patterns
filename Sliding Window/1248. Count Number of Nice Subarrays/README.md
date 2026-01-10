# 1248. Count Number of Nice Subarrays

## 📋 Problem Description

**Problem Number**: 1248  
**Difficulty**: Medium  
**LeetCode Link**: [Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/)  
**Level**: 🧪 Level 5: Non-obvious sliding window (The "At Most K" Trick)

---

### Problem Statement

Given an array of integers `nums` and an integer `k`. A continuous subarray is called **nice** if there are `k` odd numbers on it.
Return the number of **nice** subarrays.

---

### Examples

#### Example 1
**Input**: `nums = [1,1,2,1,1], k = 3`  
**Output**: `2`  
**Explanation**: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

#### Example 2
**Input**: `nums = [2,2,2,1,2,2,1,2,2,2], k = 2`  
**Output**: `16`

---

## 💡 Approach: The "At Most K" Trick

This problem is functionally identical to finding subarrays with exactly $K$ distinct elements, but the condition is now based on the **count of odd numbers**.



### The Strategy
Just like in problem 992, it is difficult to count "Exactly $K$" using a standard sliding window because the window doesn't have a unique size for a fixed number of odds (due to surrounding even numbers).

We transform the problem:
$$\text{Exactly}(K \text{ odds}) = \text{AtMost}(K \text{ odds}) - \text{AtMost}(K - 1 \text{ odds})$$

### Why it works
- `atMostK(nums, k)` counts all subarrays having $0, 1, 2, \dots, k$ odd numbers.
- `atMostK(nums, k-1)` counts all subarrays having $0, 1, 2, \dots, k-1$ odd numbers.
- Subtracting the two leaves only the subarrays that have **exactly** $k$ odd numbers.

---

## ⚡ Complexity Analysis

* **Time Complexity**: $O(N)$ — We iterate through the array twice (once for each call to `atMostK`).
* **Space Complexity**: $O(1)$ — We only use integer variables to track counts and pointers.

---

**Pattern**: Sliding Window (Variable Size) + Counting Trick  
**Date Solved**: January 10, 2026
