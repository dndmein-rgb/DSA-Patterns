# 🌊 Sliding Window Hierarchy: From Pointers to Monotonic Deques

This roadmap represents the mechanical and mental shift required to master Sliding Window problems.

---

## 🧱 Level 1: Absolute Basics (Move pointers without tripping)

**The Focus**: Mechanical accuracy. Learning "Sum In, Sum Out."

* [643. Maximum Average Subarray I](./0643-maximum-average-subarray-i) - Fixed window, sum in and sum out. No excuses.
* [209. Minimum Size Subarray Sum](./0209-minimum-size-subarray-sum) - Variable window, positive numbers only. Sliding window 101.
* [1343. Number of Sub-arrays of Size K and Average ≥ Threshold](./1343-number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold) - Fixed window, mechanical.

---

## 🪟 Level 2: Frequency Window (Maps, counts, discipline)

**The Focus**: Maintaining an internal state of character frequencies.

* [3. Longest Substring Without Repeating Characters](./0003-longest-substring-without-repeating-characters) - If this breaks you, stop and relearn pointers.
* [567. Permutation in String](./0567-permutation-in-string) - Fixed window + frequency match.
* [438. Find All Anagrams in a String](./0438-find-all-anagrams-in-a-string) - Same idea as 567, no hiding.
* [76. Minimum Window Substring](./0076-minimum-window-substring) - The boss fight. You already touched it and tripped. Good.

---

## 🔁 Level 3: Window with Constraints (Thinking required)

**The Focus**: Handling "slack" or "flips" within the window.

* [424. Longest Repeating Character Replacement](./0424-longest-repeating-character-replacement) - Sliding window with a lying invariant. Subtle.
* [1004. Max Consecutive Ones III](./1004-max-consecutive-ones-iii) - Window with limited violations.
* [904. Fruit Into Baskets](./0904-fruit-into-baskets) - Exactly K distinct elements window.

---

## 🧠 Level 4: Monotonic Window (Separate skill)

**The Focus**: Tracking Max/Min without O(K) lookups.

* [239. Sliding Window Maximum](./0239-sliding-window-maximum) - Deque or go home.
* [1438. Longest Continuous Subarray With Absolute Diff ≤ Limit](./1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit) - Two deques. No mercy.

---

## 🧪 Level 5: Non-obvious Sliding Window (Where people fake it)

**The Focus**: The "At Most K" Trick.

* [992. Subarrays with K Different Integers](./0992-subarrays-with-k-different-integers) - "At most K" trick. If you don't know it, you don't know sliding window.
* [1248. Count Number of Nice Subarrays](./1248-count-number-of-nice-subarrays) - Same trick, different skin.
* [930. Binary Subarrays With Sum](./0930-binary-subarrays-with-sum) - Yet again, same trick.

---

## 💀 Level 6: Window + Greed / Multi-Condition

**The Focus**: Rare, but brutal if you haven't done Level 5.

* [1658. Minimum Operations to Reduce X to Zero](./1658-minimum-operations-to-reduce-x-to-zero) - Inverted thinking: find maximum middle subarray.
* [2444. Count Subarrays With Fixed Bounds](./2444-count-subarrays-with-fixed-bounds) - Complex constraint tracking.
* [713. Subarray Product Less Than K](./0713-subarray-product-less-than-k) - Multiplicative window with shrinking.

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
- Examples: 643, 1343

### Pattern 2: Variable Window (Maximize/Minimize)
- Grow window greedily
- Shrink when constraint violated
- Examples: 3, 424, 1004

### Pattern 3: "At Most K" Trick
- To find "exactly K": `atMost(K) - atMost(K-1)`
- Essential for counting problems
- Examples: 992, 1248, 930

### Pattern 4: Monotonic Deque
- Need O(1) min/max queries in sliding window
- Maintain monotonicity by removing obsolete elements
- Examples: 239, 1438

### Pattern 5: Frequency Map Window
- Track character/element counts
- Use hashmap or array for frequencies
- Examples: 76, 438, 567

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

## 📚 Additional Resources

- [LeetCode Sliding Window Tag](https://leetcode.com/tag/sliding-window/)
- [Sliding Window Technique - GeeksforGeeks](https://www.geeksforgeeks.org/window-sliding-technique/)

---

**Progression Metric**: If you can solve 76 (Minimum Window Substring) and 239 (Sliding Window Maximum) without hints, you've mastered the fundamentals. Everything else is pattern recognition.
