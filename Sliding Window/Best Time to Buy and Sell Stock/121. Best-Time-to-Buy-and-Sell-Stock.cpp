class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int minVal = 1e9; 
        
        
        int maxPro = 0;
        
        for (int p : prices) {
            minVal = min(minVal, p);
            
            maxPro = max(maxPro, p - minVal);
        }
        
        return maxPro;
    }
};
