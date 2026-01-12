/* Pattern: Two Pointers (Expand Around Center)
   Problem: 647. Palindromic Substrings
*/

// Implementation 1: Direct expansion inside the loop
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            // Case 1: Odd-length palindromes (center is 'i')
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }

            // Case 2: Even-length palindromes (center is 'i' and 'i+1')
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};

// Implementation 2: Clean expansion using a helper function
class SolutionClean {
public:
    int expand(string& s, int left, int right) {
        int n = s.size();
        int count = 0;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += expand(s, i, i);     // odd-length
            ans += expand(s, i, i + 1); // even-length
        }
        return ans;
    }
};
