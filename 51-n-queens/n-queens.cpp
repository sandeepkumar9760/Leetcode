class Solution {
public:
    bool is_safe(vector<string>& board , int row ,int col, int size){
        // row wise
        for(int i=0; i<size; i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        //upper left diagonal
        for(int i=row-1 , j=col-1; i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        // upper right diagonal
        for(int i=row-1,j=col+1; i>=0 && j<size ; i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void nqueens(vector<string>& board , vector<vector<string>>& ans , int row , int size){
        if(row==size){
            ans.push_back({board});
            return;
        }
        for(int i=0; i<size; i++){
            if(is_safe(board,row,i,size)){
                board[row][i]='Q';
                nqueens(board,ans,row+1,size);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        nqueens(board,ans,0,n);
        return ans;
    }
};