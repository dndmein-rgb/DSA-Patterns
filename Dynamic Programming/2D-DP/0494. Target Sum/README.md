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
* Since the sum of elements in `nums` can be up to 1000, the `curr` sum can range from **-1000** (all negative) to **1000** (all positive).
* Array indices cannot be negative, so we add an **offset of 1000** to shift the range from `[-1000, 1000]` to `[0, 2000]`.



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \times \text{TotalSum})$ — We explore $N \times 2001$ states.
* **Space Complexity**: $O(N \times \text{TotalSum})$ — For the memoization table.

---
**Date Solved**: January 13, 2026
