class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;
        
        for(int& num:nums) pq.push(num);
        k--;
        while(k--) pq.pop();
        return pq.top();
    }
};