# 322. Coin Change

## 📋 Problem Description
**Problem Number**: 322  
**Difficulty**: Medium  
**LeetCode Link**: [Coin Change](https://leetcode.com/problems/coin-change/)  
**Pattern**: Dynamic Programming (Unbounded Knapsack)

---

### Problem Statement
You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the **fewest number of coins** that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

---

## 💡 Approach: Top-Down DP (Unbounded Knapsack)

This problem is a classic variation of the Knapsack problem. Since we can use each coin an infinite number of times, it is categorized as **Unbounded**.



### Decision Logic
At each step (for each coin), we have two choices:
1.  **Take**: If the coin value is $\le$ the remaining amount, use the coin (add 1 to count) and **stay at the same index** to allow reusing the same coin.
2.  **Not Take**: Skip the current coin and move to the next denomination.



### Implementation Notes
* **State**: `t[i][amount]` stores the minimum coins needed using coins from index `i` to `n-1` to form `amount`.
* **Infinity**: We use `1e9` (a large integer) to represent an impossible state. If the final result is $\ge 1e9$, we return `-1`.
* **Memoization**: Crucial to reduce the complexity from $O(2^{\text{amount}})$ to $O(n \times \text{amount})$.

---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(n \times \text{amount})$ — We fill a 2D table of size $n \times \text{amount}$.
* **Space Complexity**: $O(n \times \text{amount})$ — To store the memoization table.

---
**Date Solved**: January 12, 2026
