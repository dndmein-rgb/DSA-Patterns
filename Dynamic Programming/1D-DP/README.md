# 🧮 Dynamic Programming Hierarchy: From Fibonacci to State Machines

This roadmap represents the conceptual shift required to master Dynamic Programming—from seeing recursion to seeing overlapping subproblems.

---

## 🧱 Level 1: 1D DP - Single Array (The Foundation)
**The Focus**: Recognize that `dp[i]` depends on previous states. 
*Space Optimization:* If you only need the last 2 states, you can reduce space from $O(N)$ to $O(1)$.



* [0070. Climbing Stairs](./0070.%20Climbing%20Stairs) - If you can't do this, start here.
* [0746. Min Cost Climbing Stairs](./0746.%20Min%20Cost%20Climbing%20Stairs) - Same structure, slightly harder decision.
* [0198. House Robber](./0198.%20House%20Robber) - Non-adjacent selection. Classic DP intro.
* [0213. House Robber II](./0213.%20House%20Robber%20II) - Circular array. Learn to break into subproblems.
* [0091. Decode Ways](./0091.%20Decode%20Ways) - Decision tree disguised as DP. Watch for edge cases.

---

## 📊 Level 2: 1D DP - Decision Making (Choose or Skip)
**The Focus**: Every element presents a choice. Track what happens when you take it vs. leave it.

* [0300. Longest Increasing Subsequence](./0300.%20Longest%20Increasing%20Subsequence) - $O(N^2)$ first, then $O(N \log N)$.
* [0139. Word Break](./0139.%20Word%20Break) - Dictionary lookup DP. String decision problem.
* [0152. Maximum Product Subarray](./0152.%20Maximum%20Product%20Subarray) - Track both max and min (negatives flip signs).
* [0322. Coin Change](./0322.%20Coin%20Change) - Unbounded knapsack logic. Minimize items.
* [0416. Partition Equal Subset Sum](./0416.%20Partition%20Equal%20Subset%20Sum) - 0/1 Knapsack in disguise.

---

## 🎯 Level 3: 2D DP - Grid/Matrix (Two Dimensions)
**The Focus**: `dp[i][j]` depends on neighbors. Learn to navigate grids.

* [0062. Unique Paths](./0062.%20Unique%20Paths) - Grid navigation 101.
* [0063. Unique Paths II](./0063.%20Unique%20Paths%20II) - Same problem, obstacles added.
* [0064. Minimum Path Sum](./0064.%20Minimum%20Path%20Sum) - Minimizing cost through a grid.
* [0221. Maximal Square](./0221.%20Maximal%20Square) - 2D state depends on 3 neighbors.

---

## 🎭 Level 4: 2D DP - String Problems (The Interview Sweet Spot)
**The Focus**: Matching, editing, or comparing two strings. 



* [1143. Longest Common Subsequence](./1143.%20Longest%20Common%20Subsequence) - The gateway drug to string DP.
* [0072. Edit Distance](./0072.%20Edit%20Distance) - The boss fight. Insert, delete, replace decisions.
* [0010. Regular Expression Matching](./0010.%20Regular%20Expression%20Matching) - Pattern matching with `*` and `.`.
* [0044. Wildcard Matching](./0044.%20Wildcard%20Matching) - Similar to regex, different rules.

---

## 🔄 Level 6: State Machine DP (Tracking Permission)
**The Focus**: Your state isn't just position—it's what you're allowed to do next.



* [0121. Best Time to Buy and Sell Stock](./0121.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock) - Foundation for the pattern.
* [0122. Best Time to Buy and Sell Stock II](./0122.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20II) - Infinite transactions.
* [0123. Best Time to Buy and Sell Stock III](./0123.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20III) - At most 2 transactions. 
* [0188. Best Time to Buy and Sell Stock IV](./0188.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20IV) - At most K transactions.
* [0309. Best Time to Buy and Sell Stock with Cooldown](./0309.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Cooldown) - Includes a "rest" state.
* [0714. Best Time to Buy and Sell Stock with Transaction Fee](./0714.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Transaction%20Fee) - Fee modifies profit.

---

## 🎲 Level 7: Interval DP (Ranges as Subproblems)
**The Focus**: `dp[i][j]` = optimal solution for range `[i, j]`.

* [0005. Longest Palindromic Substring](./0005.%20Longest%20Palindromic%20Substring) - Expanding from center vs DP.
* [0516. Longest Palindromic Subsequence](./0516.%20Longest%20Palindromic%20Subsequence) - Subsequence allows gaps.
* [0647. Palindromic Substrings](./0647.%20Palindromic%20Substrings) - Count all palindromic substrings.
* [0312. Burst Balloons](./0312.%20Burst%20Balloons) - Think backwards from the last balloon.

---

## 🛠️ Implementation Templates

### Top-Down (Memoization)
```cpp
int solve(int i, vector<int>& memo) {
    if (i <= 1) return i;
    if (memo[i] != -1) return memo[i];
    return memo[i] = solve(i - 1, memo) + solve(i - 2, memo);
}
