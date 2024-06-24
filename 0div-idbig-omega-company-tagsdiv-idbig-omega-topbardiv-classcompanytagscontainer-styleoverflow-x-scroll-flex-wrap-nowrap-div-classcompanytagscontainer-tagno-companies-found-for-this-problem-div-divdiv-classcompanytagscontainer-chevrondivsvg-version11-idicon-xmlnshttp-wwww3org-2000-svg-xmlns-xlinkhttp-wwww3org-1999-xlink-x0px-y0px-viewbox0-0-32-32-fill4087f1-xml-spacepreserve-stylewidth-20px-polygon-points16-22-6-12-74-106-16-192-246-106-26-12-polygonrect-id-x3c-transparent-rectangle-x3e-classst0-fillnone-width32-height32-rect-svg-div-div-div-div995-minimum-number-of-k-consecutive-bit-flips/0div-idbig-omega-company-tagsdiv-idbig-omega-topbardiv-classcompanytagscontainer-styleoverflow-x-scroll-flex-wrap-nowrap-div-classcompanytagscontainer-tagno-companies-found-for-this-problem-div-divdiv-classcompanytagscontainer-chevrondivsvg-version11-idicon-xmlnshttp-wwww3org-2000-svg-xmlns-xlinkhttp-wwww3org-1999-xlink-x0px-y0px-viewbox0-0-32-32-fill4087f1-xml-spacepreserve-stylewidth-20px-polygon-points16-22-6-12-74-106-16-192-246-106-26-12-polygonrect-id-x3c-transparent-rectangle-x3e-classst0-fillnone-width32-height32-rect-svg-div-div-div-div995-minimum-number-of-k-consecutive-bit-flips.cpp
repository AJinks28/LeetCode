class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size(),flipTimes=0,res=0;
        vector<int> isFlipAt(n,0);
        
        for(int i=0;i<n;i++){
            if(i>=k) flipTimes-=isFlipAt[i-k];
            
            if(nums[i]==1 && flipTimes%2==0) continue; //nums[i] flipped even times will remain 1
            else if(nums[i]==0 && flipTimes%2==1) continue; //nums[i] flipped odd times will become 1
            else if(nums[i]==1 && flipTimes%2==1){
                if(i+k>n) return -1;
                isFlipAt[i]=1;//flip at index i
                flipTimes++;
                res++;
            }
            else if(nums[i]==0 && flipTimes%2==0){
                if(i+k>n) return -1;
                isFlipAt[i]=1;//flip at index i
                flipTimes++;
                res++;
            }
            
        }
        return res;
    }
};