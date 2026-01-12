# 198. House Robber

## 📋 Problem Description
**Problem Number**: 198  
**Difficulty**: Medium  
**LeetCode Link**: [House Robber](https://leetcode.com/problems/house-robber/)  
**Pattern**: Dynamic Programming (Linear / "Include-Exclude")

---

### Problem Statement
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight **without alerting the police**.

---

## 💡 Implementation Strategies

### 1. Top-Down (Memoization)
The problem boils down to a recursive decision at every house:
1.  **Rob the house**: Gain `nums[i]` and jump to index `i + 2`.
2.  **Skip the house**: Gain `0` and move to index `i + 1`.



### 2. Space Optimized (Iterative)
This follows the same logic as *Climbing Stairs*. To decide the maximum loot for the current house, we only need to know the maximum loot possible from:
-   One house ahead (`prev1`)
-   Two houses ahead (`prev2`)



**Recurrence Relation**:  
$$dp[i] = \max(nums[i] + dp[i+2], dp[i+1])$$

---

## ⚡ Complexity Comparison

| Feature | Top-Down (Memoization) | Space Optimized (Iterative) |
| :--- | :--- | :--- |
| **Time Complexity** | $O(N)$ | $O(N)$ |
| **Space Complexity** | $O(N)$ (Stack + Memo) | $O(1)$ |
| **State Definition** | `solve(i)` max loot from `i` to `n` | `prev1` max loot from `i+1` to `n` |

---
**Date Solved**: January 12, 2026
