class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Store all words for O(1) lookup
        unordered_set<string> wordset(wordList.begin(), wordList.end());

        // If endWord is not present, transformation is impossible
        if (!wordset.count(endWord)) return 0;

        int count = 1; // Number of levels (words) in transformation
        queue<string> q;
        q.push(beginWord);

        // Standard BFS
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                string word = q.front();
                q.pop();

                // If reached endWord, return depth
                if (word == endWord)
                    return count;

                // Try changing every character
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;

                        word[i] = c;

                        // If transformed word exists and not yet visited
                        if (wordset.count(word)) {
                            q.push(word);
                            wordset.erase(word); // mark as visited
                        }
                    }

                    // Restore original character
                    word[i] = original;
                }
            }

            // Move to next level
            count++;
        }

        return 0;
    }
};
