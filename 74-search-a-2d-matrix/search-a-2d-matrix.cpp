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
            int mid = start_row + (end_row-start_row)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][n-1]){
                return bst(mid,matrix,target);
            }else if(target<matrix[mid][0]){
                end_row = mid - 1;
            }else{
                start_row = mid + 1;
            }
        }
        return false;
    }
};