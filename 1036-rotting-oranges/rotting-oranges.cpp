class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int fresh = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=1;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int time = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                // upper check
                int up_row = row-1;
                int up_col = col;
                if(up_row>=0 && visited[up_row][up_col]==0 && grid[up_row][up_col]==1){
                    visited[up_row][up_col]=1;
                    q.push({up_row,up_col});
                    fresh--;
                }
                //lower check
                int low_row = row+1;
                int low_col = col;
                if(low_row<m && visited[low_row][low_col]==0 && grid[low_row][low_col]==1){
                    visited[low_row][low_col]=1;
                    q.push({low_row,low_col});
                    fresh--;
                }
                //left check 
                int left_row = row;
                int left_col = col-1;
                if(left_col>=0 && visited[left_row][left_col]==0 && grid[left_row][left_col]==1){
                    visited[left_row][left_col]=1;
                    q.push({left_row,left_col});
                    fresh--;
                }
                //right check
                int right_row = row;
                int right_col = col+1;
                if(right_col<n && visited[right_row][right_col]==0 && grid[right_row][right_col]==1){
                    visited[right_row][right_col]=1;
                    q.push({right_row,right_col});
                    fresh--;
                }

            }
            if(!q.empty()) time++;
        }
        if(fresh==0){
            return time;
        }else{
            return -1;
        }
    }
};