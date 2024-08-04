class Solution {
public:
    vector<int> allSum(vector<int>& nums){
        vector<int> arr;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum+=nums[j];
                arr.push_back(sum);
            }
            sum=0;
        }
        return arr;
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr=allSum(nums);
        sort(arr.begin(),arr.end());
        
        int sum=0;
        int M=1e9+7;
        for(int i=left-1;i<=right-1;i++){
            sum+=arr[i];
            sum%=M;
        }
        return sum;
    }
};