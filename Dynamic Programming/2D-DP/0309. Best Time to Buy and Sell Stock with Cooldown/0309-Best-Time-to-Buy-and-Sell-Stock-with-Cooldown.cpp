/* Pattern: Dynamic Programming (State Machine / Decision Making)
   Time Complexity: O(N) - Each state (day, buy/sell) is visited once
   Space Complexity: O(N) - For memoization table (5001 x 2)
*/

class Solution {
public:
    int t[5001][2];
    int n;

    int solve(int i, int buy, vector<int>& prices) {
        // Base Case: If we pass the last day, no more profit can be made
        if (i >= n) return 0;
        
        if (t[i][buy] != -1) return t[i][buy];

        if (buy == 0) { // State: Can Buy
            // Choice 1: Buy today -> cost is -prices[i], move to 'Sell' state for next day
            // Choice 2: Skip today -> stay in 'Buy' state for next day
            return t[i][buy] = max(-prices[i] + solve(i + 1, 1, prices), 
                                   solve(i + 1, 0, prices));
        } else { // State: Can Sell
            // Choice 1: Sell today -> gain is +prices[i], MUST cooldown (skip i+1), move to 'Buy' at i+2
            // Choice 2: Skip today -> stay in 'Sell' state for next day
            return t[i][buy] = max(prices[i] + solve(i + 2, 0, prices), 
                                   solve(i + 1, 1, prices));
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(t, -1, sizeof(t));
        // Start on day 0 with the ability to buy (buy=0)
        return solve(0, 0, prices);
    }
};
