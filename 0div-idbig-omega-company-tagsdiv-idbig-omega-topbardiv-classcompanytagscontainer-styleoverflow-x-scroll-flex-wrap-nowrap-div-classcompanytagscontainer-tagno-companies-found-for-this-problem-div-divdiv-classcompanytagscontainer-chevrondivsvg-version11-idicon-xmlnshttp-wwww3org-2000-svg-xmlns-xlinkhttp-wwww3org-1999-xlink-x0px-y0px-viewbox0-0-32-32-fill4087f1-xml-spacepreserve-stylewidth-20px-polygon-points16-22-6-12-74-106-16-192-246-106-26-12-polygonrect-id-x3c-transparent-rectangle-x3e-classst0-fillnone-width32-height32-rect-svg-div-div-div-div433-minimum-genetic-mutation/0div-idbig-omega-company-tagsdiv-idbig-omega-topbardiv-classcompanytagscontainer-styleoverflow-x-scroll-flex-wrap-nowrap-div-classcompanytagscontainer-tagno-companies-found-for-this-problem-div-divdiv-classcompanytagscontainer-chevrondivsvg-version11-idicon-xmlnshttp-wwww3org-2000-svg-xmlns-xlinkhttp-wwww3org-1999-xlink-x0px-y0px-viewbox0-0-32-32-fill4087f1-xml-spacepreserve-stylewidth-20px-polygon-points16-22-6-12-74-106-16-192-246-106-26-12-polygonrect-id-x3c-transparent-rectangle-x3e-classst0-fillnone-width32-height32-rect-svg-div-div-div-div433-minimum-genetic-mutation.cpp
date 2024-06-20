class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> s(bank.begin(),bank.end());
        // vector<string>
        
        queue<string> q;
        q.push(startGene);
        int steps=0;
        
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string curr=q.front();
                q.pop();
                s.erase(curr);
                if(curr==endGene) return steps;


                for(string adj:s){
                    int diff=0;
                    for(int i=0;i<8;i++){
                        if(curr[i]!=adj[i]) diff++;
                    }

                    if(diff==1){
                        q.push(adj);
                    }
                }
            }
            steps++;
            
        }
        return -1;
    }
};