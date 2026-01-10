# 🌊 Sliding Window Hierarchy: From Pointers to Monotonic Deques

This roadmap represents the mechanical and mental shift required to master Sliding Window problems.

---

## 🧱 Level 1: Absolute Basics (Move pointers without tripping)

**The Focus**: Mechanical accuracy. Learning "Sum In, Sum Out."
* [121. Best Time to Buy and Sell Stock](./0121-Best%20Time%20to%20Buy%20and%20Sell%20Stock) - Classic one-pass window tracking.
* [643. Maximum Average Subarray I](./0643.%20Maximum%20Average%20Subarray%20I) - Fixed window, sum in and sum out. No excuses.
* [209. Minimum Size Subarray Sum](./0209.%20Minimum%20Size%20Subarray%20Sum) - Variable window, positive numbers only. Sliding window 101.
* [1343. Number of Sub-arrays of Size K and Average ≥ Threshold](./1343.%20Number%20of%20Sub-arrays%20of%20Size%20K%20and%20Average%20Greater%20than%20or%20Equal%20to%20Threshold) - Fixed window, mechanical.

---

## 🪟 Level 2: Frequency Window (Maps, counts, discipline)

**The Focus**: Maintaining an internal state of character frequencies.

* [3. Longest Substring Without Repeating Characters](./0003-%20Longest%20Substring%20Without%20Repeating%20Characters) - If this breaks you, stop and relearn pointers.
* [567. Permutation in String](./0567-%20Permutation%20in%20String) - Fixed window + frequency match.
* [438. Find All Anagrams in a String](./0438.%20Find%20All%20Anagrams%20in%20a%20String) - Same idea as 567, no hiding.
* [76. Minimum Window Substring](./0076-%20Minimum%20Window%20Substring) - The boss fight. You already touched it and tripped. Good.

---

## 🔁 Level 3: Window with Constraints (Thinking required)

**The Focus**: Handling "slack" or "flips" within the window.

* [424. Longest Repeating Character Replacement](./0424-%20Longest%20Repeating%20Character%20Replacement) - Sliding window with a lying invariant. Subtle.
* [1004. Max Consecutive Ones III](./1004.%20Max%20Consecutive%20Ones%20III) - Window with limited violations.
* [904. Fruit Into Baskets](./0904.%20Fruit%20Into%20Baskets) - Exactly K distinct elements window.

---

## 🧠 Level 4: Monotonic Window (Separate skill)

**The Focus**: Tracking Max/Min without O(K) lookups.

* [239. Sliding Window Maximum](./0239.%20Sliding%20Window%20Maximum) - Deque or go home.
* [1438. Longest Continuous Subarray With Absolute Diff ≤ Limit](./1438.%20Longest%20Continuous%20Subarray%20With%20Absolute%20Diff%20Less%20Than%20or%20Equal%20to%20Limit) - Two deques. No mercy.

---

## 🧪 Level 5: Non-obvious Sliding Window (Where people fake it)

**The Focus**: The "At Most K" Trick.

* [992. Subarrays with K Different Integers](./0992.%20Subarrays%20with%20K%20Different%20Integers) - "At most K" trick. If you don't know it, you don't know sliding window.
* [1248. Count Number of Nice Subarrays](./1248.%20Count%20Number%20of%20Nice%20Subarrays) - Same trick, different skin.
* [930. Binary Subarrays With Sum](./930.%20Binary%20Subarrays%20With%20Sum) - Yet again, same trick.

---

## 💀 Level 6: Window + Greed / Multi-Condition

**The Focus**: Rare, but brutal if you haven't done Level 5.


* [1658. Minimum Operations to Reduce X to Zero](#) - Inverted thinking: find maximum middle subarray. *(Add when available)*
* [2444. Count Subarrays With Fixed Bounds](#) - Complex constraint tracking. *(Add when available)*

---

## 🛠️ Core Variable Window Template

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
```

---

## 🧬 Core Fixed Window Template

```cpp
int windowSum = 0;
for (int i = 0; i < k; i++) {
    windowSum += nums[i];        // Build initial window
}

int ans = windowSum;
for (int i = k; i < n; i++) {
    windowSum += nums[i];        // Add new element
    windowSum -= nums[i - k];    // Remove old element
    ans = max(ans, windowSum);   // Update result
}
```

---

## 🎯 Key Patterns to Recognize

### Pattern 1: Fixed Window
- Window size K is given
- Use simple add/remove logic
- **Examples**: 643, 1343

### Pattern 2: Variable Window (Maximize/Minimize)
- Grow window greedily
- Shrink when constraint violated
- **Examples**: 3, 424, 1004

### Pattern 3: "At Most K" Trick
- To find "exactly K": `atMost(K) - atMost(K-1)`
- Essential for counting problems
- **Examples**: 992, 1248, 930

### Pattern 4: Monotonic Deque
- Need O(1) min/max queries in sliding window
- Maintain monotonicity by removing obsolete elements
- **Examples**: 239, 1438

### Pattern 5: Frequency Map Window
- Track character/element counts
- Use hashmap or array for frequencies
- **Examples**: 76, 438, 567

---

## 🎓 Learning Path Recommendations

1. **Start with Level 1** - Build muscle memory for pointer movement
2. **Master Level 2** - Frequency tracking is everywhere
3. **Don't skip Level 3** - This is where intuition develops
4. **Level 4 is separate** - Monotonic deque is its own beast
5. **Level 5 unlocks counting** - The "At Most K" trick is non-negotiable
6. **Level 6 for mastery** - When you're ready to flex

---

## 🔥 Common Mistakes to Avoid

- **Off-by-one errors** - Always verify `j - i + 1` vs `j - i`
- **Forgetting to shrink** - The `while` loop for shrinking is critical
- **Wrong state updates** - Add/remove in correct order
- **Not handling edge cases** - Empty arrays, K > N, etc.
- **O(K) lookups in window** - Use monotonic deque when needed

---

## 📊 Problem Distribution

| Level | Problems | Time to Master |
|-------|----------|----------------|
| Level 1 | 3 | 1-2 days |
| Level 2 | 4 | 3-5 days |
| Level 3 | 3 | 2-3 days |
| Level 4 | 2 | 2-3 days |
| Level 5 | 3 | 3-4 days |
| Level 6 | 1+ | 2-3 days |

---

## 💡 Pro Tips

1. **Visualize the window** - Draw it out on paper for the first 10 problems
2. **State management is everything** - Know what your window tracks at all times
3. **When stuck, brute force first** - Then optimize to sliding window
4. **The "At Most K" trick** - Memorize this formula: `exactly(K) = atMost(K) - atMost(K-1)`
5. **Monotonic deque** - This is a separate data structure skill, not just sliding window

---

## 🎯 Quick Reference: When to Use Sliding Window

✅ **Use Sliding Window when:**
- Problem involves subarrays/substrings
- Asked for "maximum/minimum/longest/shortest" with constraints
- Need to find something in contiguous elements
- Brute force would involve nested loops checking all subarrays

❌ **Don't force Sliding Window when:**
- Elements can be non-contiguous (use DP or greedy)
- Need to find individual elements, not subarrays
- Problem requires comparing distant elements without window context

---

## 📁 Repository Structure

```
Sliding Window/
├── 0003- Longest Substring Without Repeating Characters/
│   └── 03-Longest-Substring-Without-Repeating-Characters.cpp
├── 0076- Minimum Window Substring/
│   └── 076-Minimum-Window-Substring.cpp
├── 0121-Best Time to Buy and Sell Stock/
│   └── 0121-Best-Time-to-Buy-and-Sell-Stock.cpp
├── 0209. Minimum Size Subarray Sum/
│   └── 0209-Minimum-Size-Subarray-Sum.cpp
├── 0239. Sliding Window Maximum/
│   └── 0239-Sliding-Window-Maximum.cpp
├── 0424- Longest Repeating Character Replacement/
│   └── 0424-Longest-Repeating-Character-Replacement.cpp
├── 0438. Find All Anagrams in a String/
│   └── 0438-Find-All-Anagrams-in-a-String.cpp
├── 0567- Permutation in String/
│   └── 0567-Permutation-in-String.cpp
├── 0643. Maximum Average Subarray I/
│   └── 0643-Maximum-Average-Subarray-I.cpp
├── 0904. Fruit Into Baskets/
│   └── 0904-Fruit-Into-Baskets.cpp
├── 0992. Subarrays with K Different Integers/
│   └── 0992-Subarrays-with-K-Different-Integers.cpp
├── 1004. Max Consecutive Ones III/
│   └── 1004-Max-Consecutive-Ones-III.cpp
├── 1248. Count Number of Nice Subarrays/
│   └── 1248-Count-Number-of-Nice-Subarrays.cpp
├── 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold/
│   └── 1343-Number-of-Sub-arrays-of-Size-K-and-Average-Greater-than-or-Equal-to-Threshold.cpp
├── 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit/
│   └── 1438-Longest-Continuous-Subarray-With-Absolute-Diff-Less-Than-or-Equal-to-Limit.cpp
├── 930. Binary Subarrays With Sum/
│   └── 930-Binary-Subarrays-With-Sum.cpp
└── README.md
```

---

**Progression Metric**: If you can solve **76 (Minimum Window Substring)** and **239 (Sliding Window Maximum)** without hints, you've mastered the fundamentals. Everything else is pattern recognition.
