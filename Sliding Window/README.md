# 🌊 Sliding Window Hierarchy: From Pointers to Monotonic Deques

This roadmap represents the mechanical and mental shift required to master Sliding Window problems.

---

### 🧱 Level 1: Absolute basics (Move pointers without tripping)
**The Focus**: Mechanical accuracy. Learning "Sum In, Sum Out."
* [643. Maximum Average Subarray I](./0643-maximum-average-subarray-i/0643-maximum-average-subarray-i.cpp)
* [209. Minimum Size Subarray Sum](./0209-minimum-size-subarray-sum.cpp/0209-minimum-size-subarray-sum.cpp)
* [1343. Number of Sub-arrays of Size K and Average ≥ Threshold](./1343-number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold.cpp/1343-number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold.cpp)

### 🪟 Level 2: Frequency window (Maps, counts, discipline)
**The Focus**: Maintaining an internal state of character frequencies.
* [3. Longest Substring Without Repeating Characters](./0003-Longest-Substring-Without-Repeating-Characters/03-Longest-Substring-Without-Repeating-Characters.cpp)
* [567. Permutation in String](./0567-permutation-in-string/solution.cpp)
* [438. Find All Anagrams in a String](./0438-find-all-anagrams-in-a-string.cpp/solution.cpp)
* [76. Minimum Window Substring](./0076-minimum-window-substring/solution.cpp)



### 🔁 Level 3: Window with constraints (Thinking required)
**The Focus**: Handling "slack" or "flips" within the window.
* [424. Longest Repeating Character Replacement](./0424-Longest-Repeating-Character-Replacement/solution.cpp)
* [1004. Max Consecutive Ones III](./1004-max-consecutive-ones-iii.cpp/solution.cpp)
* [904. Fruit Into Baskets](./0904-fruit-into-baskets.cpp/solution.cpp)

### 🧠 Level 4: Monotonic window (Separate skill)
**The Focus**: Tracking Max/Min without $O(K)$ lookups.
* [239. Sliding Window Maximum](./0239-sliding-window-maximum/solution.cpp)
* [1438. Longest Continuous Subarray With Absolute Diff ≤ Limit](./1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit.cpp/solution.cpp)



### 🧪 Level 5: Non-obvious sliding window (Where people fake it)
**The Focus**: The "At Most K" Trick.
* **Core Logic**: `Exactly(K) = AtMost(K) - AtMost(K - 1)`
* [992. Subarrays with K Different Integers](./0992-Subarrays-with-K-Different-Integers/solution.cpp)
* [1248. Count Number of Nice Subarrays](./1248-Count-Number-of-Nice-Subarrays/solution.cpp)
* [930. Binary Subarrays With Sum](./0930-Binary-Subarrays-With-Sum/solution.cpp)

### 💀 Level 6: Window + Greed / Multi-Condition
**The Focus**: Usually involves calculating "Exactly K" by transforming the logic or combining with greedy heuristics.
* [992. Subarrays with K Different Integers](./0992-Subarrays-with-K-Different-Integers/solution.cpp)
* [1248. Count Number of Nice Subarrays](./1248-Count-Number-of-Nice-Subarrays/solution.cpp)

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
