class Solution {
public:
    bool search(int row ,vector<vector<int>>& matrix , int target){
        int start = 0;
        int end = matrix[0].size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(matrix[row][mid]==target){
                return true;
            }else if(target<matrix[row][mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0;
        int end = rows - 1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][cols-1]){
                return search(mid,matrix,target);
            }else if(target<matrix[mid][0]){
                end = mid -1;
            }else{
                start = mid + 1;
            }
        }
        return false;
    }
};