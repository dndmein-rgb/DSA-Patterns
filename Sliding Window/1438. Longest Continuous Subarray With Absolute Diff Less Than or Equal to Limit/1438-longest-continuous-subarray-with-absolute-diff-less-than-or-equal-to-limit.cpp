// Optimal O(N) Deque Implementation
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minDQ, maxDQ;
        int n = nums.size();
        int i = 0, ans = 0;
        
        for (int j = 0; j < n; j++) {
            // Maintain Max Deque (decreasing order)
            while (!maxDQ.empty() && nums[maxDQ.back()] < nums[j])
                maxDQ.pop_back();
            maxDQ.push_back(j);
            
            // Maintain Min Deque (increasing order)
            while (!minDQ.empty() && nums[minDQ.back()] > nums[j])
                minDQ.pop_back();
            minDQ.push_back(j);

            // If the absolute difference between max and min exceeds limit, shrink window
            while (nums[maxDQ.front()] - nums[minDQ.front()] > limit) {
                if (maxDQ.front() == i) maxDQ.pop_front();
                if (minDQ.front() == i) minDQ.pop_front();
                i++;
            }

            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};

// Alternative O(N log N) Heap Implementation

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>> maxH; 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;
        int i = 0, ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            maxH.push({nums[j], j});
            minH.push({nums[j], j});
            while (true) {
                while (!maxH.empty() && maxH.top().second < i) maxH.pop();
                while (!minH.empty() && minH.top().second < i) minH.pop();
                if (maxH.top().first - minH.top().first <= limit) break;
                i++; 
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
