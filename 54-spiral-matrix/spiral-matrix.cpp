class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int start_row = 0;
        int start_col = 0;
        int end_row = m-1;
        int end_col = n-1;
        while(start_row<=end_row && start_col<=end_col){
            //upper row
            for (int i=start_col ; i<=end_col; i++){
                ans.push_back(matrix[start_row][i]);
            }

            //right side
            for(int i=start_row+1; i<=end_row; i++){
                ans.push_back(matrix[i][end_col]);
            }

            //lower side
            for(int i=end_col-1; i>=start_col; i--){
                if(start_row==end_row){
                    break;
                }
                ans.push_back(matrix[end_row][i]);
            }

            //left side
            for(int i=end_row-1; i>=start_row+1; i--){
                if(start_col == end_col){
                    break;
                }
                ans.push_back(matrix[i][start_col]);
            }
            
            
            start_row++;
            start_col++;
            end_row--;
            end_col--;
        }
        return ans;
    }
};