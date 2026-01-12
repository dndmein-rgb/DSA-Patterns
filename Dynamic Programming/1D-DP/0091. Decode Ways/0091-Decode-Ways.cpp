/* Pattern: Dynamic Programming (String Partitioning)
   Time Complexity: O(N) - Each index is solved once
   Space Complexity: O(N) - Memoization array and recursion stack
*/

class Solution {
public:
    int t[101];
    int n;
    string s;

    int solve(int i) {
        // Base case: If we reach the end, we found 1 valid decoding path
        if (i == n) return 1;

        // Leading zero cannot be decoded as a standalone or start of a pair
        if (s[i] == '0') return 0;

        if (t[i] != -1) return t[i];

        // Option 1: Decode as a single digit (always possible if s[i] != '0')
        int ways = solve(i + 1);

        // Option 2: Decode as a pair of digits (must be between 10 and 26)
        if (i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26) {
                ways += solve(i + 2);
            }
        }

        return t[i] = ways;
    }

    int numDecodings(string str) {
        s = str;
        n = s.length();
        if (n == 0) return 0;
        
        memset(t, -1, sizeof(t));
        return solve(0);
    }
};
