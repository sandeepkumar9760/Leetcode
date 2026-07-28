class Solution {
public:
    bool bst(int start_row , vector<vector<int>>&matrix , int target){
        int start = 0;
        int end = matrix[0].size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(matrix[start_row][mid]==target){
                return true;
            }else if(matrix[start_row][mid]>target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start_row = 0;
        int end_row = m-1;
        while(start_row<=end_row){
            if(target>=matrix[start_row][0] && target<=matrix[start_row][n-1]){
                return bst(start_row,matrix,target);
            }else{
                start_row++;
            }
        }
        return false;
    }
};