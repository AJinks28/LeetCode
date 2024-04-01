class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int count[128];
        int maxCnt=0; //largest count of a single, unique character in the current window
        int ans=0;
        for(int i=0,j=0;j<n;j++){
            count[s[j]]++;
            maxCnt=max(maxCnt,count[s[j]]);
            
        // end-start+1-maxCount is equal to exactly the # of characters that are NOT the character that                 occurs the most in that window. Example: For a window "xxxyz", end-start+1-maxCount would equal               2. (maxCount is 3 and there are 2 characters here, "y" and "z" that are not "x" in the window.)
            if(j-i+1-maxCnt > k){
                count[s[i]]--;
                i++;
            }
            
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};