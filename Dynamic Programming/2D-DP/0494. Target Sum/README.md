# 494. Target Sum

## 📋 Problem Description
**Problem Number**: 494  
**Difficulty**: Medium  
**LeetCode Link**: [Target Sum](https://leetcode.com/problems/target-sum/)  
**Pattern**: Dynamic Programming (0/1 Knapsack Variation)

---

### Problem Statement
You are given an integer array `nums` and an integer `target`.

You want to build an **expression** out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

Return the number of different expressions that you can build, which evaluates to `target`.

---

### 🛑 Constraints
* `1 <= nums.length <= 20`
* `0 <= nums[i] <= 1000`
* `0 <= sum(nums[i]) <= 1000`
* `-1000 <= target <= 1000`

---

### 📝 Examples

**Example 1:**
* **Input**: `nums = [1,1,1,1,1], target = 3`
* **Output**: `5`
* **Explanation**: There are 5 ways to assign symbols:
  1. -1+1+1+1+1 = 3
  2. +1-1+1+1+1 = 3
  3. +1+1-1+1+1 = 3
  4. +1+1+1-1+1 = 3
  5. +1+1+1+1-1 = 3

---

## 💡 Approach: Top-Down DP (Recursion + Memoization)

At every element, we make a binary decision: assign it a positive sign or a negative sign.

### 1. The Decision Tree
For each number, we branch into two possibilities. This creates a recursion tree of depth $N$.



### 2. Handling Negative Indices (The Offset Trick)
A crucial part of the implementation is `curr + 1000`. 
* **The Logic**: Since the maximum possible sum of `nums` is 1000 (per constraints), the range of our `curr` sum is `[-1000, 1000]`.
* **The Problem**: Array indices in C++ must be $\ge 0$. 
* **The Solution**: We add an **offset of 1000** to the current sum. This maps the range `[-1000, 1000]` to `[0, 2000]`, fitting perfectly into our `t[21][2001]` memoization table.



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \times \text{TotalSum})$ — Since $N \le 20$ and $TotalSum \le 1000$, we explore approximately $20 \times 2001$ states.
* **Space Complexity**: $O(N \times \text{TotalSum})$ — For the memoization table.

---
**Date Solved**: January 13, 2026
