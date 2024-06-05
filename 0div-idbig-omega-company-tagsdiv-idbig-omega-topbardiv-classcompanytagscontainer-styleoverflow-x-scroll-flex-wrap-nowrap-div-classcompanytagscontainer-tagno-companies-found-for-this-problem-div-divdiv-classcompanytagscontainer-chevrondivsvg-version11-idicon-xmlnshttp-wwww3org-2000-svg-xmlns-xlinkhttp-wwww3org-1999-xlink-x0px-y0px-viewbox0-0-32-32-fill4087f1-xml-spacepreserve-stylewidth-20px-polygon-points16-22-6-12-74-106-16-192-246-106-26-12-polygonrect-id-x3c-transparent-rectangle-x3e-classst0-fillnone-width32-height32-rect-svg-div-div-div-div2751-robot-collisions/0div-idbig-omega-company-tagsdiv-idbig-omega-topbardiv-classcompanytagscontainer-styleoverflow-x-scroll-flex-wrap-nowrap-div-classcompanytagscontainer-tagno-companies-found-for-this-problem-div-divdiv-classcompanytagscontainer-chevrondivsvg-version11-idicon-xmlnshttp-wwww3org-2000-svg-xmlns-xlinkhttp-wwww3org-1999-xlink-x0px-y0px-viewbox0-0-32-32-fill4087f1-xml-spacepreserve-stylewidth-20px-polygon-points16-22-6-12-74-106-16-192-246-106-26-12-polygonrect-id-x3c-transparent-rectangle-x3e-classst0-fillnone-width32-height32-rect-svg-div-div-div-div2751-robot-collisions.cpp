class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        int n=h.size();
        
        vector<int> ind(n),stack;
        for(int i=0;i<n;i++) ind[i]=i;
        sort(ind.begin(),ind.end(),[&]( int a, int b){
            return pos[a]<pos[b];
        });
        
        for(int i:ind){
            if(dir[i]=='R'){
                stack.push_back(i);
                continue;
            }
            //else
            while(!stack.empty() && h[i]>0){
                if(h[stack.back()]<h[i]){
                    h[i]--;
                    h[stack.back()]=0;stack.pop_back();
                }
                else if(h[stack.back()]>h[i]){
                    h[stack.back()]--;
                    h[i]=0;
                }
                else{
                    h[i]=0;
                    h[stack.back()]=0;stack.pop_back();
                }
            }
        }
        
        vector<int> ans;
        for(int v:h){
            if(v>0) ans.push_back(v);
        }
        return ans;
            
    }
};