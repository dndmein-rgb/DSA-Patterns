# 416. Partition Equal Subset Sum

## 📋 Problem Description
**Problem Number**: 416  
**Difficulty**: Medium  
**LeetCode Link**: [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)  
**Pattern**: Dynamic Programming (0/1 Knapsack Variation)

---

### Problem Statement
Given an integer array `nums`, return `true` if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or `false` otherwise.

---

## 💡 Approach: Top-Down DP (Subset Sum)

This problem is a direct application of the **Subset Sum Problem**. If we can find a subset that sums up to exactly half of the total sum, the remaining elements will naturally sum up to the other half.



### Logic
1. **The Target**: Calculate the total sum of the array. If it's odd, return `false` immediately. If even, our target is `sum / 2`.
2. **The State**: `t[i][target]` stores whether it's possible to achieve `target` using a subset of elements starting from index `i`.
3. **The Choices**:
   - **Include**: Subtract `nums[i]` from the target and move to `i + 1`.
   - **Exclude**: Keep the target same and move to `i + 1`.



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \times \text{Target})$ — Where $N$ is the number of elements and $\text{Target}$ is $\frac{TotalSum}{2}$.
* **Space Complexity**: $O(N \times \text{Target})$ — To store the memoization table.

---
**Date Solved**: January 12, 2026
