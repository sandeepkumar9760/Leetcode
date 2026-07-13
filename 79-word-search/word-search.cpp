class Solution {
public:
    bool helper(int row, int col , vector<vector<int>>&visited , vector<vector<char>>& board , string word ,int idx){
        
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || visited[row][col]==1 || board[row][col]!=word[idx]){
            return false;
        }
        if(idx==word.size()-1 || idx==word.size()){
            return true;

        }
        visited[row][col]=1;
        bool check = helper(row-1,col,visited,board,word,idx+1) || helper(row,col-1,visited,board,word,idx+1) || helper(row,col+1,visited,board,word,idx+1) || helper(row+1,col,visited,board,word,idx+1);
        visited[row][col]=0;
        return check;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    bool check = helper(i,j,visited,board,word,0);
                    if(!check){
                        continue;
                    }else{
                        return true;
                    }
                }
            }
        }
        return false;
    }
};