/* Problem: 152. Maximum Product Subarray
*/

/* Approach 1: Brute Force (Nested Loops)
   Time Complexity: O(N^2)
   Space Complexity: O(1)
   Note: This will pass for small inputs but may result in TLE (Time Limit Exceeded) for large constraints.
*/
class SolutionBrute {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = nums[0];
        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = i; j < n; j++) {
                product *= nums[j];
                maxProduct = max(maxProduct, product);
            }
        }
        return maxProduct;
    }
};

/* Approach 2: Optimized Dynamic Programming (Kadane's Variation)
   Time Complexity: O(N)
   Space Complexity: O(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], minProd = nums[0], ans = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            
            // If negative, the largest product can become the smallest and vice versa
            if (x < 0) swap(maxProd, minProd);
            
            maxProd = max(x, x * maxProd);
            minProd = min(x, x * minProd);
            
            ans = max(ans, maxProd);
        }
        return ans;
    }
};
