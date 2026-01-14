/* Pattern: Dynamic Programming (Two Strings / Pattern Matching)
   Time Complexity: O(N * M) - N and M are lengths of text and pattern
   Space Complexity: O(N * M) - For the memoization table
*/

class Solution {
public:
    int t[21][21]; // Constraint: s and p lengths are <= 20

    bool solve(int i, int j, string& text, string& pattern) {
        // Base Case: If pattern is exhausted, text must also be exhausted
        if (j == pattern.length())
            return i == text.length();
            
        if (t[i][j] != -1) {
            return t[i][j];
        }
        
        bool ans = false;

        // Check if the current characters match or if pattern has a '.'
        bool first_match = (i < text.length() &&
                            (pattern[j] == text[i] || pattern[j] == '.'));

        // Handle the '*' wildcard logic
        if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
            /* Case 1: '*' matches zero occurrences of the preceding element
               Action: Skip the character and the '*' (move j + 2)
               
               Case 2: '*' matches one or more occurrences
               Action: If first_match is true, move text pointer (i + 1) but stay at same pattern index
            */
            ans = (solve(i, j + 2, text, pattern) ||
                   (first_match && solve(i + 1, j, text, pattern)));
        } else {
            // Standard matching logic
            ans = first_match && solve(i + 1, j + 1, text, pattern);
        }

        return t[i][j] = ans;
    }
    
    bool isMatch(string text, string pattern) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, text, pattern);
    }
};
