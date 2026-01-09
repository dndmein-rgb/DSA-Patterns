class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int i = 0, j = 0;
        int sum = 0;
        int count = 0;
        
        while (j < n) {
            sum += arr[j];
            
            if (j - i + 1 > k) {
                sum -= arr[i];
                i++;
            }
            
            if (j - i + 1 == k && sum >= threshold * k) {
                count++;
            }
            
            j++;
        }
        
        return count;
    }
};
