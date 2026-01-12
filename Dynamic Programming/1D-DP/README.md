# 🧮 Dynamic Programming Hierarchy: From Fibonacci to State Machines

This roadmap represents the conceptual shift required to master Dynamic Programming—from seeing recursion to seeing overlapping subproblems.

---

## 🧱 Level 1: 1D DP - Single Array (Learn to see the recurrence)

**The Focus**: Recognize that `dp[i]` depends on previous states. Build the foundation.

* [70. Climbing Stairs](./0070-Climbing-Stairs) - If you can't do this, you don't understand recursion. Start here.
* [746. Min Cost Climbing Stairs](./0746-Min-Cost-Climbing-Stairs) - Same structure, slightly harder decision.
* [198. House Robber](./0198-House-Robber) - Non-adjacent selection. Classic DP introduction.
* [213. House Robber II](./0213-House-Robber-II) - Circular array. Learn to break into subproblems.

---

## 📊 Level 2: 1D DP - Decision Making (Choose or skip)

**The Focus**: Every element presents a choice. Track what happens when you take it vs. leave it.

* [300. Longest Increasing Subsequence](./0300-Longest-Increasing-Subsequence) - O(N²) first, then O(N log N). You need both.
* [139. Word Break](./0139-Word-Break) - Dictionary lookup DP. String decision problem.
* [91. Decode Ways](./0091-Decode-Ways) - Decision tree disguised as DP. Watch for edge cases.
* [152. Maximum Product Subarray](./0152-Maximum-Product-Subarray) - Track both max and min. Negative numbers flip everything.

---

## 🎯 Level 3: 2D DP - Grid/Matrix (Two dimensions = new state space)

**The Focus**: `dp[i][j]` depends on neighbors. Learn to navigate grids.

* [62. Unique Paths](./0062-Unique-Paths) - Grid navigation 101. Can only move right/down.
* [63. Unique Paths II](./0063-Unique-Paths-II) - Same problem, obstacles added. Handle blocked cells.
* [64. Minimum Path Sum](./0064-Minimum-Path-Sum) - Not just counting paths, minimizing cost.
* [221. Maximal Square](./0221-Maximal-Square) - 2D state depends on 3 neighbors. Not trivial.

---

## 🎭 Level 4: 2D DP - String Problems (Two sequences, infinite pain)

**The Focus**: Matching, editing, comparing two strings. This is where interviews live.

* [1143. Longest Common Subsequence](./1143-Longest-Common-Subsequence) - The gateway drug to string DP.
* [72. Edit Distance](./0072-Edit-Distance) - The boss fight. Insert, delete, replace decisions.
* [10. Regular Expression Matching](./0010-Regular-Expression-Matching) - Pattern matching with `*` and `.`. Brutal.
* [44. Wildcard Matching](./0044-Wildcard-Matching) - Similar to regex, different rules.

---

## 💰 Level 5: Knapsack Variants (The classic problem, infinite forms)

**The Focus**: Limited capacity, maximize value. Bounded vs unbounded.

* [416. Partition Equal Subset Sum](./0416-Partition-Equal-Subset-Sum) - 0/1 Knapsack in disguise.
* [322. Coin Change](./0322-Coin-Change) - Unbounded knapsack. Minimize coins used.
* [518. Coin Change II](./0518-Coin-Change-II) - Count ways, not minimize. Different recurrence.
* [474. Ones and Zeroes](./0474-Ones-and-Zeroes) - 2D knapsack constraint. Nasty.

---

## 🔄 Level 6: State Machine DP (Track which state you're in)

**The Focus**: Your state isn't just position—it's what you're allowed to do next.

* [121. Best Time to Buy and Sell Stock](./0121-Best-Time-to-Buy-and-Sell-Stock) - Not really DP, but sets up the pattern.
* [122. Best Time to Buy and Sell Stock II](./0122-Best-Time-to-Buy-and-Sell-Stock-II) - Infinite transactions. Greedy works, but DP mindset matters.
* [123. Best Time to Buy and Sell Stock III](./0123-Best-Time-to-Buy-and-Sell-Stock-III) - At most 2 transactions. State explosion begins.
* [188. Best Time to Buy and Sell Stock IV](./0188-Best-Time-to-Buy-and-Sell-Stock-IV) - At most K transactions. Full state machine.
* [309. Best Time to Buy and Sell Stock with Cooldown](./0309-Best-Time-to-Buy-and-Sell-Stock-with-Cooldown) - States: holding, sold, cooldown.
* [714. Best Time to Buy and Sell Stock with Transaction Fee](./0714-Best-Time-to-Buy-and-Sell-Stock-with-Transaction-Fee) - Fee modifies profit calculation.

---

## 🎲 Level 7: Interval DP (Subproblems are ranges)

**The Focus**: `dp[i][j]` = optimal solution for range `[i, j]`. Non-trivial iteration order.

* [5. Longest Palindromic Substring](./0005-Longest-Palindromic-Substring) - Expand from center, or use DP. Both valid.
* [516. Longest Palindromic Subsequence](./0516-Longest-Palindromic-Subsequence) - Not substring. Subsequence allows gaps.
* [647. Palindromic Substrings](./0647-Palindromic-Substrings) - Count all palindromic substrings.
* [312. Burst Balloons](./0312-Burst-Balloons) - Interval DP nightmare. Think backwards.

---

## 💀 Level 8: Multi-Dimensional DP (3D+, only if you hate yourself)

**The Focus**: State space explodes. Optimize or cry.

* [1000. Minimum Cost to Merge Stones](./1000-Minimum-Cost-to-Merge-Stones) - 3D DP. Merging intervals with constraints.
* [1335. Minimum Difficulty of a Job Schedule](./1335-Minimum-Difficulty-of-a-Job-Schedule) - 2D with tricky transitions.
* [1406. Stone Game III](./1406-Stone-Game-III) - Game theory + DP. Opponent plays optimally.

---

## 🧪 Level 9: DP + Other Patterns (Hybrid monsters)

**The Focus**: DP isn't the only tool. Combine with greedy, binary search, etc.

* [1092. Shortest Common Supersequence](./1092-Shortest-Common-Supersequence) - LCS + backtracking construction.
* [1312. Minimum Insertion Steps to Make a String Palindrome](./1312-Minimum-Insertion-Steps-to-Make-a-String-Palindrome) - LPS variant.
* [1547. Minimum Cost to Cut a Stick](./1547-Minimum-Cost-to-Cut-a-Stick) - Interval DP with sorting.

---

## 🛠️ Core Top-Down DP Template (Memoization)

```cpp
class Solution {
    vector<int> memo;
    
    int solve(int i, /* state params */) {
        // Base case
        if (i == n) return 0;
        
        // Check memo
        if (memo[i] != -1) return memo[i];
        
        // Recurrence relation
        int option1 = /* do something */ + solve(i + 1);
        int option2 = /* do something else */ + solve(i + 1);
        
        // Store and return
        return memo[i] = max(option1, option2);
    }
    
public:
    int mainFunction(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, -1);
        return solve(0);
    }
};
```

---

## 🧬 Core Bottom-Up DP Template (Tabulation)

```cpp
class Solution {
public:
    int mainFunction(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        
        // Base case
        dp[0] = /* base value */;
        
        // Fill table
        for (int i = 1; i <= n; i++) {
            dp[i] = /* recurrence relation */;
        }
        
        return dp[n];
    }
};
```

---

## 🎯 Key Patterns to Recognize

### Pattern 1: Linear DP (1D Array)
- State depends on previous 1-2 states
- Usually O(N) time, O(N) or O(1) space
- **Examples**: Climbing Stairs, House Robber

### Pattern 2: Grid DP (2D Matrix)
- Moving through a grid with constraints
- `dp[i][j]` depends on top/left neighbors
- **Examples**: Unique Paths, Min Path Sum

### Pattern 3: String DP (2D, Two Sequences)
- Comparing/matching two strings
- `dp[i][j]` = solution for `s1[0...i]` and `s2[0...j]`
- **Examples**: LCS, Edit Distance

### Pattern 4: Knapsack (0/1 or Unbounded)
- Limited capacity, maximize value
- 0/1: each item used once. Unbounded: infinite items
- **Examples**: Partition Sum, Coin Change

### Pattern 5: State Machine DP
- State = (position, current_state)
- Transitions between states have rules
- **Examples**: Stock problems with cooldown/fees

### Pattern 6: Interval DP
- `dp[i][j]` = solution for range `[i, j]`
- Iterate length, then start position
- **Examples**: Palindrome problems, Burst Balloons

---

## 🎓 Learning Path Recommendations

1. **Start with Level 1** - If you can't do Climbing Stairs, stop everything.
2. **Master Level 2** - Decision-making DP is everywhere in interviews.
3. **Survive Level 3** - Grid problems are easier than they look.
4. **Level 4 is the filter** - Edit Distance separates beginners from intermediates.
5. **Level 5 is pattern recognition** - All knapsack problems are the same problem.
6. **Level 6 for advanced roles** - State machines show up in senior interviews.
7. **Level 7+ is flex territory** - Only do this if you're hunting FAANG hard problems.

---

## 🔥 Common Mistakes to Avoid

- **Not defining state clearly** - If you don't know what `dp[i]` represents, you're lost.
- **Wrong base cases** - Off-by-one errors kill DP solutions.
- **Not considering all transitions** - Every decision must be in your recurrence.
- **Forgetting to memoize** - Top-down without memo = exponential time.
- **Wrong iteration order** - Bottom-up requires correct dependency order.
- **Trying to optimize too early** - Get O(N²) working before hunting O(N log N).

---

## 📊 Problem Distribution

| Level | Problems | Time to Master |
|-------|----------|----------------|
| Level 1 | 4 | 2-3 days |
| Level 2 | 4 | 3-4 days |
| Level 3 | 4 | 2-3 days |
| Level 4 | 4 | 5-7 days |
| Level 5 | 4 | 4-5 days |
| Level 6 | 6 | 5-7 days |
| Level 7 | 4 | 4-5 days |
| Level 8 | 3 | 3-4 days |
| Level 9 | 3+ | 3-4 days |

**Total**: 36+ problems, 4-6 weeks to mastery

---

## 💡 Pro Tips

1. **Draw the recurrence tree** - Visualize overlapping subproblems before coding.
2. **Start with brute force recursion** - Then add memoization. Then convert to tabulation.
3. **Optimize space after time** - Get correct answer first, then reduce from O(N²) to O(N).
4. **Backtracking construction** - Some problems need the actual solution, not just optimal value.
5. **State compression** - Often you only need last 1-2 rows/columns in memory.

---

## 🎯 Quick Reference: When to Use DP

✅ **Use DP when:**
- Problem asks for "optimal" (min/max/longest/shortest)
- Problem has overlapping subproblems
- Current state depends only on previous states
- You can define recurrence relation clearly
- Brute force recursion works but times out

❌ **Don't force DP when:**
- Greedy gives optimal solution (coin change with specific denominations)
- No overlapping subproblems (just divide and conquer)
- State space is infinite or unbounded
- Problem is inherently graph-based (use graph algorithms)

---

## 🧠 The DP Checklist (Before You Code)

Before writing ANY DP solution, answer these:

1. **What is my state?** - What does `dp[i]` or `dp[i][j]` represent?
2. **What are my base cases?** - When does recursion stop?
3. **What is my recurrence relation?** - How does `dp[i]` depend on previous states?
4. **What is my iteration order?** - Bottom-up: which cells must be filled first?
5. **Can I optimize space?** - Do I need the full table or just last row?

If you can't answer all 5, don't start coding.

---

## 📁 Problem Structure

Each problem folder contains:
```
XXXX-Problem-Name/
├── README.md          # Problem description, approach, complexity
└── solution.cpp       # Clean, commented implementation
```

---

## 🏆 Boss Fights (Mastery Check)

If you can solve these without hints, you've mastered DP:

- **72. Edit Distance** - The ultimate string DP test.
- **312. Burst Balloons** - Interval DP nightmare.
- **188. Best Time to Buy and Sell Stock IV** - State machine mastery.

Everything else is pattern recognition applied correctly.

---

**Progression Metric**: If you can independently derive the recurrence relation for **Edit Distance (72)** and **LCS (1143)**, you understand DP. If you can solve **Burst Balloons (312)** without hints, you've mastered it.

---

[← Back to Main](../README.md)
