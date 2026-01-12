/* Pattern: Dynamic Programming (String Partitioning)
   Time Complexity: O(N^3) 
   - N states, and for each state, we loop O(N) with string substring/push_back O(N)
   Space Complexity: O(N + M) 
   - N for DP array/recursion and M for the Hash Set dictionary
*/

class Solution {
public:
    unordered_set<string> dict;
    int n;
    int t[1001];

    bool solve(int i, string& s) {
        // Base Case: If we reach the end of the string, a valid partition was found
        if (i == n)
            return true;

        if (t[i] != -1)
            return t[i];

        string curr = "";
        // Try every possible partition starting from index i
        for (int j = i; j < n; j++) {
            curr.push_back(s[j]);
            
            // If current prefix exists in dictionary, solve for the remaining suffix
            if (dict.count(curr)) {
                if (solve(j + 1, s))
                    return t[i] = true;
            }
        }
        
        return t[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(t, -1, sizeof(t));
        
        // Convert vector to set for O(1) average lookup time
        dict.insert(wordDict.begin(), wordDict.end());
        
        return solve(0, s);
    }
};
