# 312. Burst Balloons

## 📋 Problem Description
**Problem Number**: 312  
**Difficulty**: Hard  
**LeetCode Link**: [Burst Balloons](https://leetcode.com/problems/burst-balloons/)  
**Pattern**: Interval Dynamic Programming (MCM Variation)

---

### Problem Statement
You are given `n` balloons, indexed from `0` to `n - 1`. Each balloon is painted with a number on it represented by an array `nums`. You are asked to burst all the balloons.

If you burst the $i^{th}$ balloon, you will get `nums[i - 1] * nums[i] * nums[i + 1]` coins. If `i - 1` or `i + 1` goes out of bounds of the array, then treat it as if there is a balloon with a `1` painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

---

### 🛑 Constraints
* `n == nums.length`
* `1 <= n <= 300`
* `0 <= nums[i] <= 100`

---

### 📝 Example
**Input**: `nums = [3, 1, 5, 8]`  
**Output**: `167`  
**Explanation**: 
`nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []`
`Coins =  3*1*5    +  3*5*8   +  1*3*8  + 1*8*1  = 167`

---

## 💡 Approach: Interval DP (Think Backwards)

The "simple" greedy approach fails because bursting a balloon changes the neighbors for the remaining balloons, making subproblems dependent. To solve this, we use the **Matrix Chain Multiplication (MCM)** logic.

### 1. Reverse Thinking
Instead of asking **"Which balloon should I burst first?"**, we ask **"Which balloon should I burst LAST in this interval $[i, j]$?"**.

If balloon `k` is the last to burst in $[i, j]$, then:
1. All balloons between $i$ and $k-1$ are already gone.
2. All balloons between $k+1$ and $j$ are already gone.
3. Therefore, the neighbors of `k` when it eventually bursts are $i-1$ and $j+1$.



### 2. The DP Formula
For an interval $[i, j]$, if we choose balloon `ind` to be the final one to burst:
$$Cost = (nums[i-1] \times nums[ind] \times nums[j+1]) + DP(i, ind-1) + DP(ind+1, j)$$

This effectively splits the problem into two independent sub-intervals $[i, ind-1]$ and $[ind+1, j]$.



### 3. Boundary Setup
To avoid handling out-of-bounds `i-1` and `j+1` checks, we pad the input array with `1` at both ends. 
Example: `[3, 1, 5]` becomes `[1, 3, 1, 5, 1]`. Our actual balloons now occupy indices `1` to `n`.

---

## ⚡ Complexity Analysis

| Type | Complexity | Reason |
| :--- | :--- | :--- |
| **Time** | **$O(N^3)$** | There are $O(N^2)$ possible intervals $[i, j]$. For each interval, we run a loop of size $N$ to pick the last balloon. |
| **Space** | **$O(N^2)$** | We maintain a 2D memoization table `t[302][302]` to store results for each interval. |

---
**Date Solved**: January 13, 2026
