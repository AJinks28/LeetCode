class Solution {
public:
    bool canJump(vector<int>& nums) {
    int maxIndex = 0;
    for(int i = 0; i < nums.size(); i++){
        if(maxIndex==nums.size()) return true;
        if (i > maxIndex){
            return false;
        }
        maxIndex = max(maxIndex, i + nums[i]);
    }
    return true;
}
};