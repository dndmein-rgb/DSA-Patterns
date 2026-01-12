# 300. Longest Increasing Subsequence

## 📋 Problem Description
**Problem Number**: 300  
**Difficulty**: Medium  
**LeetCode Link**: [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)  
**Pattern**: Dynamic Programming (Subsequences)

---

### Problem Statement
Given an integer array `nums`, return the length of the longest **strictly increasing subsequence**.

---

### 📝 Examples

**Example 1:**
* **Input**: `nums = [10, 9, 2, 5, 3, 7, 101, 18]`
* **Output**: `4`
* **Explanation**: The longest increasing subsequence is `[2, 3, 7, 101]`, therefore the length is `4`.

**Example 2:**
* **Input**: `nums = [0, 1, 0, 3, 2, 3]`
* **Output**: `4`
* **Explanation**: The LIS is `[0, 1, 2, 3]`.

**Example 3:**
* **Input**: `nums = [7, 7, 7, 7, 7]`
* **Output**: `1`
* **Explanation**: Subsequences must be **strictly** increasing.

---

## 💡 Approach: Dynamic Programming

### 1. Top-Down (Memoization)
To know if we can pick `nums[i]`, we need to know the value of the **last element picked**. Therefore, our state requires two variables: `solve(current_index, previous_index)`.



* **Take**: Only if `nums[current] > nums[prev]`.
* **Not Take**: Skip and move to `current + 1`.

### 2. Bottom-Up (Tabulation)
We use a 1D `dp` array where `dp[i]` represents the length of the LIS ending exactly at index `i`.



For every `i`, we look back at all `j < i`. If `nums[j] < nums[i]`, it means we can extend the subsequence ending at `j` by adding `nums[i]`.

**Recurrence**:  
$$dp[i] = \max(1 + dp[j] \text{ for all } j < i \text{ where } nums[j] < nums[i])$$

---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N^2)$ — Two nested loops to fill the DP table.
* **Space Complexity**: $O(N)$ — For the 1D DP array (tabulation).

---
**Date Solved**: January 12, 2026
