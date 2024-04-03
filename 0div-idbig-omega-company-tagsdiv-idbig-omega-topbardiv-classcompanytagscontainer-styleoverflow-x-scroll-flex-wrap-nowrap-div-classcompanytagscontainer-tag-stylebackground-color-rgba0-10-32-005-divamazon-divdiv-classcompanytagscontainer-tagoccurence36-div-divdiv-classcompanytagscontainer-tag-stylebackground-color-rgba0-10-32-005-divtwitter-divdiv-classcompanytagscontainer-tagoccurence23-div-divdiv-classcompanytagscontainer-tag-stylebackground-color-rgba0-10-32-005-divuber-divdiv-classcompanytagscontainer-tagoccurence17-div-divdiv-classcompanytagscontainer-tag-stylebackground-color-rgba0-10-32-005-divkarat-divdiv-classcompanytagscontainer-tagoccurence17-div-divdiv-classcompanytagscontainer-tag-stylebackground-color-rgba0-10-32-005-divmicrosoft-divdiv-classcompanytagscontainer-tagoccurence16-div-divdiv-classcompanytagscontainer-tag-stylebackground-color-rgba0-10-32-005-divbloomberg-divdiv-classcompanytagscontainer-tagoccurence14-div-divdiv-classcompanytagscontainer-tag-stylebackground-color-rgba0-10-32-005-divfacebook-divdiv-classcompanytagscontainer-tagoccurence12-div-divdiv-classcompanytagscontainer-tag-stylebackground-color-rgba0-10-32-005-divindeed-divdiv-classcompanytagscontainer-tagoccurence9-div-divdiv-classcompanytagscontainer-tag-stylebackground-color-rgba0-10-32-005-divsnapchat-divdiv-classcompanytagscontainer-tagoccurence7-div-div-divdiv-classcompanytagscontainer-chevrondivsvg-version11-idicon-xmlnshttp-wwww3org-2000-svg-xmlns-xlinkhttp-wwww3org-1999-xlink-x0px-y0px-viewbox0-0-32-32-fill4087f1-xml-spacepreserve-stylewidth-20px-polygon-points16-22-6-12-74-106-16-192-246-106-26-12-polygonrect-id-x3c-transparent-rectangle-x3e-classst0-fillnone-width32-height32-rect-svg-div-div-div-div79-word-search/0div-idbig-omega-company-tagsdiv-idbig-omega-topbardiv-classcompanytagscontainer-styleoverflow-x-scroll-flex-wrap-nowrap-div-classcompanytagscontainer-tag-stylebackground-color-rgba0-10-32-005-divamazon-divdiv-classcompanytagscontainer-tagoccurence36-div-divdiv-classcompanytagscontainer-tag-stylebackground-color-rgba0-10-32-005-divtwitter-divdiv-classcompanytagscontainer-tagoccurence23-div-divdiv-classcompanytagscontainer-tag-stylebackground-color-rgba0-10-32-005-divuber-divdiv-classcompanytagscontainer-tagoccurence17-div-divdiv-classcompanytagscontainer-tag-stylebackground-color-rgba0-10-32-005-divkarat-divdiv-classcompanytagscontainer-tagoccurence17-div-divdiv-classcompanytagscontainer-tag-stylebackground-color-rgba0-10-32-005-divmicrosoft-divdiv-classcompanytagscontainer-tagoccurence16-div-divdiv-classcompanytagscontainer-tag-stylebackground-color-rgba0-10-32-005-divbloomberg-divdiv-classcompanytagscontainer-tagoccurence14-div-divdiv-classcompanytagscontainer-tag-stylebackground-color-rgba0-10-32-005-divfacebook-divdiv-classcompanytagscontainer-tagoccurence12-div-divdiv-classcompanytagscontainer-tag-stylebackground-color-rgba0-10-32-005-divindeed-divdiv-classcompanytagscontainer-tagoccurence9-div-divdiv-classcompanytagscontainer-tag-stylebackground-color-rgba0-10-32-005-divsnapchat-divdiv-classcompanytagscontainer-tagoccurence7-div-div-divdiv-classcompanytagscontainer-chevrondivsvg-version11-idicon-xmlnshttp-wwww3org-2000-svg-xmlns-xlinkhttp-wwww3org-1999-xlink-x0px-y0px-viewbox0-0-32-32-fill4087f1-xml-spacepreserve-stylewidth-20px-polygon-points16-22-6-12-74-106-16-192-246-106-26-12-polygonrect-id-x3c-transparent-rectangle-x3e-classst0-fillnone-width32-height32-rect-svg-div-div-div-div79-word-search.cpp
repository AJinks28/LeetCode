class Solution {
public:
    bool search(int idx,int i,int j,vector<vector<char>>& board, string word){
        int m=board.size();
        int n=board[0].size();
        
        //BASE CONDITION
        if(idx==word.size()) return true;
        if(i<0 || j<0 || i>=m || j>=n) return false;
        if(board[i][j]=='$' || board[i][j]!=word[idx]) return false;
        
        
        char temp=board[i][j];
        board[i][j]='$';
        
        int di[]={0,1,0,-1};
        int dj[]={1,0,-1,0};
        
        for(int x=0;x<4;x++){
            int _i=i+di[x];
            int _j=j+dj[x];
            
            if(search(idx+1,_i,_j,board,word)) return true;
        }
        
        board[i][j]=temp;
        
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(word[0]==board[i][j] && search(0,i,j,board,word)) return true;
                
            }
        }
        return false;
    }
};