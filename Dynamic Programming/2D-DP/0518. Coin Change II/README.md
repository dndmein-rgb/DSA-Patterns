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

### 🛑 Constraints
* `1 <= coins.length <= 300`
* `1 <= coins[i] <= 5000`
* All the values of `coins` are **unique**.
* `0 <= amount <= 5000`

---

### 📝 Examples

**Example 1:**
* **Input**: `amount = 5, coins = [1, 2, 5]`
* **Output**: `4`
* **Explanation**: There are four ways to make up the amount:
  1. 5 = 5
  2. 5 = 2 + 2 + 1
  3. 5 = 2 + 1 + 1 + 1
  4. 5 = 1 + 1 + 1 + 1 + 1

---

## 💡 Approach: Unbounded Knapsack (Top-Down)

This problem is a variation of the Knapsack problem where items (coins) can be reused infinitely.

### 1. The Decision Logic
For every coin at index `i`, we have two primary choices:
* **Take the current coin**: We subtract `coins[i]` from the `amount`. Crucially, we **do not** increment `i` because we might want to use the same coin again.
* **Skip the current coin**: We keep the `amount` as is and move to `i + 1` to try different denominations.



### 2. Correcting the "Skip" Case
A common pitfall is returning `0` early if `amount < coins[i]`. Even if the current coin is too large, the recursion must continue to `i + 1` because subsequent coins in the array might be small enough to fit.

* **If amount >= coins[i]**: `Total = solve(i, amount - coins[i]) + solve(i + 1, amount)`
* **Else**: `Total = solve(i + 1, amount)`



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \times \text{amount})$ — Where $N$ is the number of coins. We visit each state in the `t[301][5001]` table exactly once.
* **Space Complexity**: $O(N \times \text{amount})$ — Required for the memoization table. This can be optimized to $O(\text{amount})$ using a bottom-up approach with a 1D array.

---
**Date Solved**: January 13, 2026
