class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            int b = c - (int)(a * a);
            int l=0,r=b;
            while(l<=r){
                long mid=(l+r)/2;
                if(mid*mid==b) return true;
                else if(mid*mid>b) r=mid-1;
                else l=mid+1;
            }
        }
        return false;
    }
};