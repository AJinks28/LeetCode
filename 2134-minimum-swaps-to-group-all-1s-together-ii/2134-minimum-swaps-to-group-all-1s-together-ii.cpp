class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = count(begin(nums), end(nums), 1);
        vector<int> nums2(n * 2);
        for (int i = 0; i < n * 2; i++) nums2[i] = nums[i % n];
        
        int cnt=0,onesInWindow=0;
        for (int i = 0; i < n*2; i++) {
            if (i >= ones && nums2[i - ones] == 1) cnt--;
            if (nums2[i] == 1) cnt++;
            onesInWindow = max(cnt, onesInWindow);
        }
        return ones - onesInWindow;
    }
};