# 0127. Word Ladder

## 📋 Problem Description
**Difficulty**: Medium  
**LeetCode**: [Word Ladder](https://leetcode.com/problems/word-ladder/)  

Given two words `beginWord` and `endWord`, and a dictionary `wordList`, return the length of the shortest transformation sequence from `beginWord` to `endWord`.

Rules:
- Only one letter can be changed at a time
- Each transformed word must exist in `wordList`
- All words have the same length
- Return `0` if no transformation is possible

### Constraints
- 1 <= wordList.length <= 5000
- All words have the same length and contain lowercase letters
- `beginWord != endWord`

---

## Approach: Breadth-First Search (BFS)
This problem can be visualized as a graph:
- Each word is a node
- An edge exists between two words if they differ by exactly one character

BFS guarantees the shortest path in an unweighted graph.

**Algorithm Steps:**
1. Insert all dictionary words into an `unordered_set` for O(1) lookup.
2. Start BFS from `beginWord`.
3. For each word:
   - Change one character at a time (`a` to `z`)
   - If the new word exists in the set, push it into the queue
   - Remove it from the set to avoid revisiting
4. Increase the level counter after each BFS layer
5. Return the level when `endWord` is found

---

## Example

**Input:** beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]

**Output:** 5

**Explanation:** hit → hot → dot → dog → cog

---

## Time Complexity
- O(N × L × 26)
  - N = number of words
  - L = length of each word
  - 26 possible character replacements per position

## Space Complexity
- O(N)
  - For the BFS queue and hash set

---

## Suggestions / Alternate Approaches

1. **Bidirectional BFS (Recommended)**  
   BFS from both `beginWord` and `endWord` simultaneously. Meet in the middle to reduce search space. Reduces runtime significantly for large dictionaries.

2. **Intermediate Pattern Mapping**  
   Convert words like "hot" into patterns: `*ot`, `h*t`, `ho*`. Build adjacency using these patterns. Avoids generating all 26×L mutations every step.

**Verdict:**  
- ✅ Current BFS solution is correct  
- ⚠️ May be slower on large inputs  
- 🚀 Bidirectional BFS is the optimal approach
