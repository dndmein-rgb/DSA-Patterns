# 🌊 Sliding Window Hierarchy: From Pointers to Monotonic Deques

This roadmap represents the mechanical and mental shift required to master Sliding Window problems.

---

### 🧱 Level 1: Absolute basics (Move pointers without tripping)
**The Focus**: Mechanical accuracy. Learning "Sum In, Sum Out."
* [643. Maximum Average Subarray I](./0643.%20Maximum%20Average%20Subarray%20I/0643-maximum-average-subarray-i.cpp) - Fixed window, sum in and sum out. No excuses.
* [209. Minimum Size Subarray Sum](./0209.%20Minimum%20Size%20Subarray%20Sum/0209-minimum-size-subarray-sum.cpp) - Variable window, positive numbers only. Sliding window 101.
* [1343. Number of Sub-arrays of Size K and Average ≥ Threshold](./1343.%20Number%20of%20Sub-arrays%20of%20Size%20K%20and%20Average%20Greater%20than%20or%20Equal%20to%20Threshold/1343-number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold.cpp) - Fixed window, mechanical.



---

### 🪟 Level 2: Frequency window (Maps, counts, discipline)
**The Focus**: Maintaining an internal state of character frequencies.
* [3. Longest Substring Without Repeating Characters](./0003-%20Longest%20Substring%20Without%20Repeating%20Characters/03-Longest-Substring-Without-Repeating-Characters.cpp) - If this breaks you, stop and relearn pointers.
* [567. Permutation in String](./0567-%20Permutation%20in%20String/0567-permutation-in-string.cpp) - Fixed window + frequency match.
* [438. Find All Anagrams in a String](./0438.%20Find%20All%20Anagrams%20in%20a%20String/0438-find-all-anagrams-in-a-string.cpp) - Same idea as 567, no hiding.
* [76. Minimum Window Substring](./0076-%20Minimum%20Window%20Substring/0076-minimum-window-substring.cpp) - The boss fight. You already touched it and tripped. Good.

---

### 🔁 Level 3: Window with constraints (Thinking required)
**The Focus**: Handling "slack" or "flips" within the window.
* [424. Longest Repeating Character Replacement](./0424-%20Longest%20Repeating%20Character%20Replacement/0424-longest-repeating-character-replacement.cpp) - Sliding window with a lying invariant. Subtle.
* [1004. Max Consecutive Ones III](./1004.%20Max%20Consecutive%20Ones%20III/1004-max-consecutive-ones-iii.cpp) - Window with limited violations.
* [904. Fruit Into Baskets](./0904.%20Fruit%20Into%20Baskets/0904-fruit-into-baskets.cpp) - Exactly K distinct elements window.

---

### 🧠 Level 4: Monotonic window (Separate skill)
**The Focus**: Tracking Max/Min without $O(K)$ lookups.
* [239. Sliding Window Maximum](./0239.%20Sliding%20Window%20Maximum/0239-sliding-window-maximum.cpp) - Deque or go home.
* [1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](./1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit.cpp) - Two deques. No mercy.



---

### 🧪 Level 5: Non-obvious sliding window (Where people fake it)
**The Focus**: The "At Most K" Trick.
* [992. Subarrays with K Different Integers](#) - “At most K” trick. If you don’t know it, you don’t know sliding window.
* [1248. Count Number of Nice Subarrays](#) - Same trick, different skin.
* [930. Binary Subarrays With Sum](#) - Yet again, same trick.

---

### 💀 Level 6: Window + Greed / Multi-Condition
**The Focus**: Rare, but brutal if you haven’t done Level 5.
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
