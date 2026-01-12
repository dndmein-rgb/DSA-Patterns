# 746. Min Cost Climbing Stairs

## 📋 Problem Description
**Problem Number**: 746  
**Difficulty**: Easy  
**LeetCode Link**: [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)  
**Pattern**: Dynamic Programming (Decision Making)

---

### Problem Statement
You are given an integer array `cost` where `cost[i]` is the cost of $i^{th}$ step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`. Return the minimum cost to reach the top of the floor.

---

## 💡 Implementation Strategies

### 1. Top-Down (Memoization)
We define a recursive function `solve(i)` which represents the minimum cost to reach the top starting from index `i`. 
- **Base Case**: If `i >= n`, the cost is 0.
- **Recursive Step**: `cost[i] + min(solve(i+1), solve(i+2))`



### 2. Space Optimized (Iterative)
We observe that to calculate the minimum cost to reach the current step, we only need the costs calculated for the two previous steps.



- **Logic**: For each step `i`, the total cost to reach and pass it is the current `cost[i]` plus the minimum of the total costs calculated for the previous two steps.
- **Result**: The top of the floor can be reached by either the last step or the second-to-last step.

---

## ⚡ Complexity Comparison

| Feature | Top-Down (Memoization) | Space Optimized (Iterative) |
| :--- | :--- | :--- |
| **Time Complexity** | $O(N)$ | $O(N)$ |
| **Space Complexity** | $O(N)$ (Array + Stack) | $O(1)$ |
| **Strategy** | Recursive | Iterative |

---
**Date Solved**: January 12, 2026
