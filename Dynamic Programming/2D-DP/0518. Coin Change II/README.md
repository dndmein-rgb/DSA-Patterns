# 518. Coin Change II

## 📋 Problem Description
**Problem Number**: 518  
**Difficulty**: Medium  
**LeetCode Link**: [Coin Change II](https://leetcode.com/problems/coin-change-ii/)  
**Pattern**: Dynamic Programming (Unbounded Knapsack)

---

### Problem Statement
You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the **number of combinations** that make up that amount. If that amount of money cannot be made up by any combination of the coins, return `0`.

You may assume that you have an infinite number of each kind of coin.

---

### 📝 Examples

**Example 1:**
* **Input**: `amount = 5, coins = [1, 2, 5]`
* **Output**: `4`
* **Explanation**: There are four ways to make up the amount:
  1. 5=5
  2. 5=2+2+1
  3. 5=2+1+1+1
  4. 5=1+1+1+1+1

---

## 💡 Approach: Unbounded Knapsack (Top-Down)

This problem differs from "Coin Change I" because we are counting **combinations** rather than finding the minimum number of coins.

### 1. The Decision Logic
For every coin, we have a binary choice that branches the recursion:
* **Take the current coin**: Decrease the target `amount` but **remain at the same index** `i`. This is the "Unbounded" characteristic—you can use the same coin infinite times.
* **Skip the current coin**: Keep the `amount` the same and move to index `i + 1`.



### 2. Correcting the "Skip" Case
In your original code, if `amount < coins[i]`, the function returned `0`. However, even if the current coin is too big, there might be smaller coins further down the array that can still satisfy the target. The logic should be:
* **If amount >= coins[i]**: Total = `solve(take)` + `solve(skip)`.
* **Else**: Total = `solve(skip)`.



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \times \text{amount})$ — We compute each state $(i, \text{amount})$ once.
* **Space Complexity**: $O(N \times \text{amount})$ — Used for the memoization table.

---
**Date Solved**: January 13, 2026
