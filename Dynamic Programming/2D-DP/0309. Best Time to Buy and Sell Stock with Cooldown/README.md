# 309. Best Time to Buy and Sell Stock with Cooldown

## 📋 Problem Description
**Problem Number**: 309  
**Difficulty**: Medium  
**LeetCode Link**: [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)  
**Pattern**: Dynamic Programming (State Machine)

---

### Problem Statement
Find the maximum profit you can achieve by buying and selling stocks with the following constraints:
1. You may complete as many transactions as you like.
2. After you sell your stock, you cannot buy stock on the next day (i.e., **1-day cooldown**).
3. You cannot engage in multiple transactions simultaneously (you must sell before you buy again).

---

### 📝 Examples

**Example 1:**
* **Input**: `prices = [1, 2, 3, 0, 2]`
* **Output**: `3`
* **Explanation**: transactions = [buy, sell, cooldown, buy, sell]

**Example 2:**
* **Input**: `prices = [1]`
* **Output**: `0`

---

## 💡 Approach: State Machine DP

This problem is more complex than basic stock problems because the "Cooldown" requirement creates a dependency on the day after selling.

### 1. The Decision Tree
On any given day, your available actions depend on your current state:



* **State: Can Buy**
    * **Buy**: Profit decreases by `prices[i]`. Next state is **Can Sell** on day `i+1`.
    * **Wait**: Profit unchanged. Next state remains **Can Buy** on day `i+1`.

* **State: Can Sell**
    * **Sell**: Profit increases by `prices[i]`. Next state is **Can Buy** on day `i+2` (skipping one day for cooldown).
    * **Wait**: Profit unchanged. Next state remains **Can Sell** on day `i+1`.

### 2. Why `i + 2`?
The core "complex work" in this logic is the jump to `i + 2`. When you sell at index `i`, you are prohibited from buying at `i + 1`. Therefore, the earliest you can enter the "Can Buy" state again is index `i + 2`.



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N)$ — Each day has two states (Buy/Sell), resulting in $2N$ subproblems.
* **Space Complexity**: $O(N)$ — Used for the memoization table and the recursion stack.

---
**Date Solved**: January 13, 2026
