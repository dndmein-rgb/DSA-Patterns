# 🧮 2D Dynamic Programming - Mastering Two-Dimensional State Transitions

A curated collection of 2D DP problems that build your intuition for multi-dimensional state spaces. Master these patterns and you'll recognize when to apply 2D DP in interviews.

---

## 📖 What is 2D DP?

2D Dynamic Programming extends the 1D concept by tracking state across **two dimensions**. Instead of `dp[i]`, you work with `dp[i][j]`, where each dimension typically represents:
- Position in two sequences (strings, arrays)
- A range `[i, j]` in interval DP
- Current position + a constraint (path with obstacles, transaction state)

**Key Insight**: `dp[i][j]` usually depends on its neighbors: `dp[i-1][j]`, `dp[i][j-1]`, or `dp[i-1][j-1]`.

---

## 🗺️ Problem Categories

### 🎯 Grid Navigation (Path Finding)
Navigate through a 2D grid with various constraints.

**Pattern**: `dp[i][j] = f(dp[i-1][j], dp[i][j-1])`

* **[0062. Unique Paths](./0062.%20Unique%20Paths)**  
  *The classic.* Count all paths from top-left to bottom-right.

* **[0329. Longest Increasing Path in a Matrix](./0329.%20Longest%20Increasing%20Path%20in%20a%20Matrix)**  
  *DFS + Memoization.* Find longest increasing path in any direction.

---

### 📝 String Matching & Transformation
Compare, match, or transform two strings. The most interview-common 2D DP pattern.

**Pattern**: `dp[i][j]` represents the solution for `s1[0...i]` and `s2[0...j]`

* **[1143. Longest Common Subsequence](./1143.%20Longest%20Common%20Subsequence)**  
  *Foundation problem.* Find longest subsequence common to both strings.
  
* **[0072. Edit Distance](./0072.%20Edit%20Distance)**  
  *Levenshtein distance.* Minimum operations to convert one string to another.
  
* **[0010. Regular Expression Matching](./0010.%20Regular%20Expression%20Matching)**  
  *Pattern matching.* Support `.` (any char) and `*` (zero or more).
  
* **[0097. Interleaving String](./0097.%20Interleaving%20String)**  
  *Merge validation.* Check if s3 is formed by interleaving s1 and s2.
  
* **[0115. Distinct Subsequences](./0115.%20Distinct%20Subsequences)**  
  *Count occurrences.* Number of distinct subsequences of s matching t.

---

### 🎒 Knapsack Variants (Unbounded/Bounded)
Decision making with items and constraints.

**Pattern**: Include/exclude current item, track remaining capacity

* **[0494. Target Sum](./0494.%20Target%20Sum)**  
  *Assign +/- signs.* Subset sum with positive/negative choices.
  
* **[0518. Coin Change II](./0518.%20Coin%20Change%20II)**  
  *Unbounded knapsack.* Count combinations to make amount with infinite coins.

---

### 🎲 Interval DP (Range Optimization)
`dp[i][j]` represents the optimal solution for subarray/substring `[i, j]`.

**Pattern**: Consider all ways to split the interval

* **[0312. Burst Balloons](./0312.%20Burst%20Balloons)**  
  *Think backwards.* Maximize coins by bursting balloons optimally.

---

### 🔄 State Machine DP
Track not just position but also the **state** you're in (buy/sell/cooldown).

* **[0309. Best Time to Buy and Sell Stock with Cooldown](./0309.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Cooldown)**  
  *Multiple states.* Track held/sold/cooldown states across days.

---

## 🛠️ Common Patterns & Templates

### Pattern 1: Grid Navigation
```cpp
// Bottom-up approach
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}
```

### Pattern 2: String Matching (LCS Template)
```cpp
// Longest Common Subsequence
int longestCommonSubsequence(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
```

### Pattern 3: Top-Down with Memoization
```cpp
// DFS + Memo for flexible state transitions
class Solution {
    vector<vector<int>> memo;
    
    int dfs(int i, int j, /* parameters */) {
        // Base cases
        if (/* boundary */) return /* value */;
        
        // Check memo
        if (memo[i][j] != -1) return memo[i][j];
        
        // Recursive cases
        int result = /* compute from neighbors */;
        
        return memo[i][j] = result;
    }
    
public:
    int solve(/* inputs */) {
        memo.assign(m, vector<int>(n, -1));
        return dfs(0, 0);
    }
};
```

---

## 💡 Problem-Solving Strategy

### Step 1: Identify the State
What does `dp[i][j]` represent?
- Position in two sequences?
- A range `[i, j]`?
- Position + constraint?

### Step 2: Find the Recurrence
How does `dp[i][j]` relate to previous states?
- Grid: `dp[i-1][j]`, `dp[i][j-1]`, `dp[i-1][j-1]`
- String: Match vs. mismatch cases
- Interval: Split point in range `[i, j]`

### Step 3: Handle Base Cases
- Empty strings/arrays
- Single character/element
- Out of bounds conditions

### Step 4: Optimize Space
Can you reduce from `O(m × n)` to `O(n)` by using rolling arrays?

---

## 📊 Complexity Analysis

| Problem Type | Time Complexity | Space Complexity | Space Optimized |
|-------------|----------------|------------------|-----------------|
| Grid (m×n) | O(m × n) | O(m × n) | O(n) |
| String (len m, n) | O(m × n) | O(m × n) | O(min(m,n)) |
| Interval (len n) | O(n³) | O(n²) | O(n²) |

---

## 🎯 Learning Path

1. **Start with Grid Problems** (0062, 0063, 0064)  
   Build intuition for 2D state dependencies
   
2. **Master LCS** (1143)  
   The foundation for all string DP
   
3. **Tackle Edit Distance** (0072)  
   The interview classic—understand all three operations
   
4. **Pattern Matching** (0010, 0044)  
   Handle wildcards and complex matching rules
   
5. **Advanced Problems** (0312, 0329)  
   Interval DP and DFS+Memo hybrids

---

## 🔥 Interview Tips

- **Draw the DP table** for small examples—visualization reveals the pattern
- **Start with recursion**, then add memoization, then convert to bottom-up
- **Watch for edge cases**: empty strings, single elements, out of bounds
- **Explain your state definition** clearly in interviews
- **Mention space optimization** even if you don't implement it

---

## 📚 Resources

- [Dynamic Programming Patterns](https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns)
- [DP for Beginners](https://leetcode.com/discuss/general-discussion/662866/dp-for-beginners-problems-patterns-sample-solutions)

---

## ⭐ Contributing

Feel free to add more problems or improve explanations! Follow the naming convention: `0XXX-Problem-Name/`

---

**Happy Coding!** 🚀 Master these patterns and 2D DP will become second nature.

---

## 📁 Folder Structure

All problems follow the naming convention: `0XXX. Problem Name/` with spaces and proper capitalization as shown in the repository structure.
