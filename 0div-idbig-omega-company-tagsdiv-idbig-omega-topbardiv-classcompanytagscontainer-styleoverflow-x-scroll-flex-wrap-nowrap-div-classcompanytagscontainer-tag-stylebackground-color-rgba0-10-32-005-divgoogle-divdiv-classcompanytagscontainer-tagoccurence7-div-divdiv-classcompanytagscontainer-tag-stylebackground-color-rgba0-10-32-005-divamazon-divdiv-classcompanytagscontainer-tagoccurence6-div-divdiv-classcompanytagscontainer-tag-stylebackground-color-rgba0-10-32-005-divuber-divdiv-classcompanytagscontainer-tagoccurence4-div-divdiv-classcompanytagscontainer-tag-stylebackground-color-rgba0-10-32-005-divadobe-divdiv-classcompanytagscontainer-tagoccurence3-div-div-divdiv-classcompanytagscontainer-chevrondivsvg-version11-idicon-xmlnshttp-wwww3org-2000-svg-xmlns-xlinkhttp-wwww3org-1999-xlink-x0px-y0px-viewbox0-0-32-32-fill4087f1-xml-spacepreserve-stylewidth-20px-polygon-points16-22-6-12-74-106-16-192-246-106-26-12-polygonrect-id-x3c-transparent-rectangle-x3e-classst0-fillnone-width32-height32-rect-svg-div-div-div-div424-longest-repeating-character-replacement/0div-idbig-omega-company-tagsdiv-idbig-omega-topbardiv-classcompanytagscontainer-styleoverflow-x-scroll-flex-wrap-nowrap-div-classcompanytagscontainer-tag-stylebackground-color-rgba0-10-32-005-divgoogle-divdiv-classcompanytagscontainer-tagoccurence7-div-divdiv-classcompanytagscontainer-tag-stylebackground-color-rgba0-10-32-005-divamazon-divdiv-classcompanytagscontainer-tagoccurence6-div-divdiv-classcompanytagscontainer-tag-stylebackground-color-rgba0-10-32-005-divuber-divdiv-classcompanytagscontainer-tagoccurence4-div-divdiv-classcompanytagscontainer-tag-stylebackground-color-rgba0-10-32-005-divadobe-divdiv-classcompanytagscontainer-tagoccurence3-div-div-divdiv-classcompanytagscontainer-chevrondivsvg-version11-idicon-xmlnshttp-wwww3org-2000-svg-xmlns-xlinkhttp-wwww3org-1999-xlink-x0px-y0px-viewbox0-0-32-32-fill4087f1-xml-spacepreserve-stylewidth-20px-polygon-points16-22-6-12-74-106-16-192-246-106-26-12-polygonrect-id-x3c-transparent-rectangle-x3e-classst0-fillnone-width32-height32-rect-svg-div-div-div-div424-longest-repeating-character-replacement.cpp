class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int count[100];
        int maxFreq=0;
        int ans=0;
        
        for(int i=0,j=0;j<n;j++){
            // cout<<"start"<<" "<<i<<" "<<s[i]<<" "<<j<<" "<<s[j]<<" "<<maxFreq<<" "<<ans<<endl;
            count[s[j]]++;
            maxFreq=max(maxFreq,count[s[j]]);
            //Check for "AAABCDEEEE"
            //maxCount may be invalid at some points, but this doesn't matter, because it was valid earlier in the string, and all that matters is finding the max window that occurred anywhere in the string. Additionally, it will expand if and only if enough repeating characters appear in the window to make it expand. So whenever it expands, it's a valid expansion.
            if(j-i+1 - maxFreq >k){
                count[s[i]]--;
                i++;
                
            }
            ans=max(ans,j-i+1);
            // cout<<"end   "<<i<<" "<<s[i]<<" "<<j<<" "<<s[j]<<" "<<maxFreq<<" "<<ans<<endl;
            
        }
        return ans;
    }
};