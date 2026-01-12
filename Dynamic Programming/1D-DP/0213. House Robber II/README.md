# 213. House Robber II

## 📋 Problem Description
**Problem Number**: 213  
**Difficulty**: Medium  
**LeetCode Link**: [House Robber II](https://leetcode.com/problems/house-robber-ii/)  
**Pattern**: Dynamic Programming (Circular Array)

---

### Problem Statement
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are **arranged in a circle.** This means the first house is the neighbor of the last one. 

Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array `nums`, return the maximum amount of money you can rob tonight **without alerting the police**.

---

## 💡 Approach: Linear DP Transformation

The "Circular" constraint means we cannot rob both the **first** and the **last** house simultaneously. To solve this, we break the circle into two separate linear problems:



### The Two-Scenario Logic
1.  **Exclude Last House**: Rob the houses from index `0` to `n-2`.
2.  **Exclude First House**: Rob the houses from index `1` to `n-1`.

By running the standard **House Robber I** logic on these two sub-arrays and taking the maximum, we ensure that the circular adjacency constraint is never violated.

### Base Cases & Memoization
* If there is only **one house**, just rob it.
* Use a `memo` array `t` to store results for each index to avoid $O(2^n)$ complexity.
* **Note**: You must reset the `memo` array (using `memset`) between the two scenario calls.

---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N)$ — We perform two linear DP passes.
* **Space Complexity**: $O(N)$ — To store the memoization table and recursion stack.

---
**Date Solved**: January 12, 2026
