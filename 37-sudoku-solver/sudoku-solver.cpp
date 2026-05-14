class Solution {
public:
    bool is_possible(vector<vector<char>>&board , int row , int col , int dig){
        // search row and col wise;
        for(int i=0; i<9; i++){
            if(board[row][i]==dig) return false;
            if(board[i][col]==dig) return false;
        }

        //search in the 3*3 grid 
        int start_row = (row/3) * 3;
        int start_col = (col/3) * 3;
        for(int i=start_row; i<start_row+3; i++){
            for(int j=start_col; j<start_col+3; j++){
                if(board[i][j]==dig) return false;
            }
        }
        return true;
    }
    bool helper (vector<vector<char>>&board , int row , int col ){
        if(row == 9){
            return true;
        }
        int next_row = row;
        int next_col = col+1;
        if(col==9){
            next_row = row+1;
            next_col = 0;
            return helper(board , next_row , next_col);
        }
        if(board[row][col]!='.'){
            return helper(board , next_row , next_col);
        }
        for(char dig='1'; dig<='9'; dig++){
            if(is_possible(board , row , col , dig)){
                board[row][col]=dig;
                if(helper(board , next_row , next_col)) return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
          helper(board , 0,0);
         
    }
};