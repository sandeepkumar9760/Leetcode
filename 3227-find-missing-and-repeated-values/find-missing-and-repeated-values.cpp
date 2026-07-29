class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n*n;
        vector<int>arr(size+1,0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                arr[grid[i][j]]++;
            }
        }
        vector<int>ans(2);
        for(int i=1;i<arr.size();i++){
            if(arr[i]>1){
                ans[0]=i;
            }
            if(arr[i]==0){
                ans[1]=i;
            }
        }
        return ans;
    }
};