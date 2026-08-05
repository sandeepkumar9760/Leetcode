class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int> &a , const pair<int,int>&b) const{
            if(a.first==b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(int i=0;i<m;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    break;
                }
                sum+=mat[i][j];
            }
            pq.push({sum,i});
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            if(ans.size()==k){
                return ans;
            }
        }
        return ans;
    }
};