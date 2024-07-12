class Solution {
public:
    
    string solve(string &s,string pat){
        int n=s.size();
        stack<char> st;
        char a=pat[0],b=pat[1];

        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()==pat[0] && s[i]==pat[1]){
                st.pop();
            }
            else st.push(s[i]);
        }
        string s2;
        while(!st.empty()){
            s2+=st.top();
            st.pop();
        }
        reverse(s2.begin(),s2.end());
        return s2;
    }
    
    int maximumGain(string s, int x, int y) {
        int res=0;
        string patx="ab",paty="ba";
        if(x<y) swap(patx,paty);
        
        string firstPass=solve(s,patx);
        int pairx=(s.size()-firstPass.size())/2;
        res+=pairx*max(x,y);
        
        string secondPass=solve(firstPass,paty);
        int pairy=(firstPass.size()-secondPass.size())/2;
        res+=pairy*min(x,y);
        
        return res;
    }
};