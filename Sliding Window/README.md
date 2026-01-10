# 🌊 Sliding Window Hierarchy: From Pointers to Monotonic Deques

This roadmap represents the mechanical and mental shift required to master Sliding Window problems.

---

### 🧱 Level 1: Absolute basics (Move pointers without tripping)
**The Focus**: Mechanical accuracy. Learning "Sum In, Sum Out."
* [643. Maximum Average Subarray I](./0643.%20Maximum%20Average%20Subarray%20I/solution.cpp)
* [209. Minimum Size Subarray Sum](./0209.%20Minimum%20Size%20Subarray%20Sum/solution.cpp)
* [1343. Number of Sub-arrays of Size K and Average ≥ Threshold](./1343.%20Number%20of%20Sub-arrays%20of%20Size%20K%20and%20Average%20Greater%20than%20or%20Equal%20to%20Threshold/solution.cpp)



### 🪟 Level 2: Frequency window (Maps, counts, discipline)
**The Focus**: Maintaining an internal state of character frequencies.
* [3. Longest Substring Without Repeating Characters](./0003-%20Longest%20Substring%20Without%20Repeating%20Characters/03-Longest-Substring-Without-Repeating-Characters.cpp)
* [567. Permutation in String](./0567-%20Permutation%20in%20String/solution.cpp)
* [438. Find All Anagrams in a String](./0438.%20Find%20All%20Anagrams%20in%20a%20String/solution.cpp)
* [76. Minimum Window Substring](./0076-%20Minimum%20Window%20Substring/solution.cpp)



### 🔁 Level 3: Window with constraints (Thinking required)
**The Focus**: Handling "slack" or "flips" within the window.
* [424. Longest Repeating Character Replacement](./0424-%20Longest%20Repeating%20Character%20Replacement/solution.cpp)
* [1004. Max Consecutive Ones III](./1004.%20Max%20Consecutive%20Ones%20III/solution.cpp)
* [904. Fruit Into Baskets](./0904.%20Fruit%20Into%20Baskets/solution.cpp)

### 🧠 Level 4: Monotonic window (Separate skill)
**The Focus**: Tracking Max/Min without $O(K)$ lookups.
* [239. Sliding Window Maximum](./0239.%20Sliding%20Window%20Maximum/solution.cpp)
* [1438. Longest Continuous Subarray With Absolute Diff ≤ Limit](#) - *Coming Soon*



### 🧪 Level 5: Non-obvious sliding window (Where people fake it)
**The Focus**: The "At Most K" Trick.
* **Core Logic**: `Exactly(K) = AtMost(K) - AtMost(K - 1)`
* [992. Subarrays with K Different Integers](#) - *Coming Soon*
* [1248. Count Number of Nice Subarrays](#) - *Coming Soon*
* [930. Binary Subarrays With Sum](#) - *Coming Soon*

### 💀 Level 6: Window + Greed / Multi-Condition
**The Focus**: Usually involves calculating "Exactly K" by transforming the logic or combining with greedy heuristics.
* [121. Best Time to Buy and Sell Stock](./0121-Best%20Time%20to%20Buy%20and%20Sell%20Stock/solution.cpp) - (A variation of a 1-pass window)

---

### 🛠️ Core Variable Window Template
```cpp
int i = 0, j = 0, ans = 0;
while (j < n) {
    state.add(nums[j]);          // 1. Expand (Right pointer)
    
    while (state.isInvalid()) {  // 2. Shrink (Left pointer)
        state.remove(nums[i]);
        i++;
    }
    
    ans = max(ans, j - i + 1);   // 3. Update Result
    j++;
}
