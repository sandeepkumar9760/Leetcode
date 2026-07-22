class Solution {
public:
    bool dfs(vector<int>&path_visit , vector<vector<int>>&adj , vector<int>&visited , int node){
        visited[node]=1;
        path_visit[node]=1;
        for(auto i : adj[node]){
            if(!visited[i]){
                if(dfs(path_visit,adj,visited,i)) return true;
            }else if(path_visit[i]){
                return true;
            }
        }
        path_visit[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& grid) {
        
        vector<int>visited(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto it : grid){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>path_visit(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(path_visit,adj,visited,i)){
                    return false;
                }
            }
        }
        return true;
    }
};