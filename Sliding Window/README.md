# 🌊 Sliding Window Hierarchy: From Pointers to Monotonic Deques

This roadmap represents the mechanical and mental shift required to master Sliding Window problems.

---

### 🧱 Level 1: Absolute basics (Move pointers without tripping)
**The Focus**: Mechanical accuracy. Learning "Sum In, Sum Out."
* [643. Maximum Average Subarray I](./0643-maximum-average-subarray-i.cpp) - Fixed window, simple sum.
* [209. Minimum Size Subarray Sum](./0209-minimum-size-subarray-sum.cpp) - Variable window, sliding window 101.
* [1343. Number of Sub-arrays of Size K and Average ≥ Threshold](./1343-number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold.cpp) - Fixed window, mechanical.

### 🪟 Level 2: Frequency window (Maps, counts, discipline)
**The Focus**: Maintaining an internal state of character frequencies.
* [3. Longest Substring Without Repeating Characters](#) - The foundational variable window problem.
* [567. Permutation in String](./0567-permutation-in-string) - Fixed window frequency matching.
* [438. Find All Anagrams in a String](./0438-find-all-anagrams-in-a-string.cpp) - Same logic as 567.
* [76. Minimum Window Substring](./0076-minimum-window-substring) - **The Boss Fight.** High frequency and pointer complexity.


### 🔁 Level 3: Window with constraints (Thinking required)
**The Focus**: Handling "slack" or "flips" within the window.
* [424. Longest Repeating Character Replacement](#) - Window with a lying invariant. Subtle logic.
* [1004. Max Consecutive Ones III](./1004-max-consecutive-ones-iii.cpp) - Window with limited violations (k-flips).
* [904. Fruit Into Baskets](./0904-fruit-into-baskets.cpp) - Exactly 2 distinct elements window.

### 🧠 Level 4: Monotonic window (Separate skill)
**The Focus**: Tracking Max/Min without $O(K)$ lookups.
* [239. Sliding Window Maximum](./0239-sliding-window-maximum) - Deque or go home.
* [1438. Longest Continuous Subarray With Absolute Diff ≤ Limit](./1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit.cpp) - Two deques. No mercy.


### 🧪 Level 5: Non-obvious sliding window (Where people fake it)
**The Focus**: The "At Most K" Trick.
* **Core Logic**: `Exactly(K) = AtMost(K) - AtMost(K - 1)`
* [992. Subarrays with K Different Integers](#) - The ultimate application of the trick.
* [1248. Count Number of Nice Subarrays](#) - Same trick, different skin (odd numbers).
* [930. Binary Subarrays With Sum](#) - Yet again, same trick.


## 💀 Level 6: Window + Greed / Multi-Condition
**The Brutal Level**: Usually involves calculating "Exactly K" by transforming the logic.
* **Trick**: `Exactly(K) = AtMost(K) - AtMost(K-1)`
* [992. Subarrays with K Different Integers](#)
* [1248. Count Number of Nice Subarrays](#)

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
