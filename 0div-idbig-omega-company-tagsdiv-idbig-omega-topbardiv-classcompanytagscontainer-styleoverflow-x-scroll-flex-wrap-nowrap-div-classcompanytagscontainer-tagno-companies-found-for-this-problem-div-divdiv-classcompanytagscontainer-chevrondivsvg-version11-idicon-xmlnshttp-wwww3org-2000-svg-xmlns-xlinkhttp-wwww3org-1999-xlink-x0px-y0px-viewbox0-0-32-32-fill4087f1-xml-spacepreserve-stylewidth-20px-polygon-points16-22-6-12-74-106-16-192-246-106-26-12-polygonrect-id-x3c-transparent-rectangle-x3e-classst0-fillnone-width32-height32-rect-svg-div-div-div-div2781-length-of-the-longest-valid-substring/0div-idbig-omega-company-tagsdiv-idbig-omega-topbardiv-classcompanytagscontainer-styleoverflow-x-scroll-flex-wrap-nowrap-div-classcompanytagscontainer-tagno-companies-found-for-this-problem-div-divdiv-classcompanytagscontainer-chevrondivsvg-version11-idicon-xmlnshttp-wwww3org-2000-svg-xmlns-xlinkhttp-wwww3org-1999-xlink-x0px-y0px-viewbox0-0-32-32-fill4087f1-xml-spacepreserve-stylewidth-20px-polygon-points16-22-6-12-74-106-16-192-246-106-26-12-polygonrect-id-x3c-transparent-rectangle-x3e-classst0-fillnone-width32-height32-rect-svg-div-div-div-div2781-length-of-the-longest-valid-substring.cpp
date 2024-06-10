class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n=word.size();
        unordered_set<string> s(forbidden.begin(),forbidden.end());
        
        int i=-1,j=0,maxLen=0;
        string curr="";
        while(j<n){
            curr+=word[j];
            // cout<<str<<" "<<j<<" "<<endl;
            string str2="";
            for(int k=j;k>(j-10);k--){
                if(k<=i)
                    break;
                str2=word[k]+ str2;
                // cout<<curr<<" "<<str2<<" "<<endl;
                if(s.find(str2)!=s.end()){
                    i=k;
                    curr="";
                    for(int g = k+1;g<=min(j,n-1);g++)
                    {
                        curr+=word[g];
                    }
                    break;
                }
            }
           
            int len=curr.size();
            maxLen=max(maxLen,len);
            j++;
        }
        
        return maxLen;
    }
};