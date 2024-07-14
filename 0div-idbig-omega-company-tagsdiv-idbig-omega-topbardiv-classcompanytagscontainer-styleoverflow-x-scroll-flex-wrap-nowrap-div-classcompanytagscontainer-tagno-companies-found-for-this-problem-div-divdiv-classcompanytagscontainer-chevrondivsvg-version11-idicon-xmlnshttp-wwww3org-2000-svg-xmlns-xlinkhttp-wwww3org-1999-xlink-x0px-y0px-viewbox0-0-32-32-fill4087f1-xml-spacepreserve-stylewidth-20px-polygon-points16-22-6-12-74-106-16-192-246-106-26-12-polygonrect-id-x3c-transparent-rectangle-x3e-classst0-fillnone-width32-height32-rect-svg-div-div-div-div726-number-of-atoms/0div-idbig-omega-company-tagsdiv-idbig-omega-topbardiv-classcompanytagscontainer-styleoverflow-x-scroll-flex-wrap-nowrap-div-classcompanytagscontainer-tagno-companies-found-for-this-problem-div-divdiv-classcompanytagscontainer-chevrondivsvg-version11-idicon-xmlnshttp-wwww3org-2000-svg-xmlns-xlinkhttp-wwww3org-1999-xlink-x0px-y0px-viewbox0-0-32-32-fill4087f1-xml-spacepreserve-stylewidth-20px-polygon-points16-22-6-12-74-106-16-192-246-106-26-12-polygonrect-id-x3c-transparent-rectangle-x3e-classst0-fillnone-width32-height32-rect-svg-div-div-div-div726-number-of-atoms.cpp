class Solution {
public:
    string countOfAtoms(string s) {
        int n=s.size();
        
        stack<unordered_map<string,int>> st;
        st.push( unordered_map<string,int>() ); //pushing empty map
        
        int i=0;
        while(i<n){
            if( s[i]=='(' ){
                st.push( unordered_map<string,int>() ); //pushing empty map
                i++;
            } 
            
            else if( s[i]==')' ){
                unordered_map<string,int> curr =st.top(); //taking out map at top
                st.pop();
                i++;
                
                //if number is there  after ) multiply it to all elements count
                string mult;
                while(i<n && isdigit(s[i])){
                    mult.push_back(s[i]);
                    i++;
                }
                
                if(!mult.empty()){
                    int multInt=stoi(mult);
                    for(auto &it : curr){//multiplying multiplier
                        string elem=it.first;
                        int cnt=it.second;
                        
                        curr[elem]= multInt*cnt;
                    }
                }
                
                //merging this to stack's top map
                for(auto &it : curr){
                    string elem=it.first;
                    int cnt=it.second;
                    //adding elem count in top map 
                    st.top()[elem]+= cnt;
            
                }
            } 
            
            else{//s[i] is char
                string currElem;
                currElem.push_back(s[i]);//s[i] is Capital letter 
                i++;
                
                while(i<n && isalpha(s[i]) && islower(s[i]) ){//while s[i] is lower char
                    currElem.push_back(s[i]);
                    i++;
                }
                
                string currCnt;//"O14"
                while(i<n && isdigit(s[i])){
                    currCnt.push_back(s[i]);
                    i++;
                }
                
                int currCntInt= currCnt.empty() ? 1 : stoi(currCnt);
                st.top()[currElem]+= currCntInt;
            }
        }
        
        //st will be have only one map on top which has <Elem : cnt>
        map<string, int> sortedMap (begin(st.top()), end(st.top()));
        string res;
        
        for(auto &it:sortedMap){
            res+=it.first;
            int cnt=it.second;
            if(cnt>1) res+= (to_string(cnt));
        }
        
        return res;
    }
};