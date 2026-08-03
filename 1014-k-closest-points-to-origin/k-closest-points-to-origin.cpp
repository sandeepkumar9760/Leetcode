class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>>pq;
        int size = points.size();
        for (int i = 0; i < size; i++) {
            double dist = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            if(pq.size()!=k){
                pq.push({dist,points[i]});
            }else{
                if(pq.top().first>dist){
                    pq.pop();
                    pq.push({dist,points[i]});
                }
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};