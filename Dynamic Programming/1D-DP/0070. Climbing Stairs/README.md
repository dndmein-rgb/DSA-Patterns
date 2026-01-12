# 70. Climbing Stairs

## 📋 Problem Description
**Problem Number**: 70  
**Difficulty**: Easy  
**LeetCode Link**: [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)  
**Pattern**: Dynamic Programming (Fibonacci Variation)

---

### Problem Statement
You are climbing a staircase. It takes `n` steps to reach the top. Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

---

## 💡 Implementation Strategies

### 1. Top-Down (Memoization)
We break the problem into subproblems: "To reach step $n$, I must have come from $n-1$ or $n-2$." We store results in a `dp` array to avoid recalculating the same steps.



* **Recursive Formula**: $f(n) = f(n-1) + f(n-2)$
* **Base Cases**: $f(0)=1, f(1)=1$

### 2. Space Optimized (Iterative)
Since we only ever need the values of the **previous two steps** to calculate the current step, we can replace the $O(N)$ array with just two variables: `prev1` and `prev2`.



* **Logic**: In each step, calculate the sum and shift the "window" of two variables forward.
* **Memory Benefit**: Reduces space from linear to constant.

---

## ⚡ Complexity Comparison

| Feature | Top-Down (Memoization) | Space Optimized (Iterative) |
| :--- | :--- | :--- |
| **Time Complexity** | $O(N)$ | $O(N)$ |
| **Space Complexity** | $O(N)$ (Array + Stack) | $O(1)$ (Only 2-3 variables) |
| **Method** | Recursive | Iterative |

---
**Date Solved**: January 12, 2026
