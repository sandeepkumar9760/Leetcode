class Solution {
public:
    struct comp {
        bool operator()(const pair<vector<int>,int>&a , const pair<vector<int>,int>&b){
            return a.second < b.second;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<vector<int>,int>,vector<pair<vector<int>,int>>,comp>pq;
        // priority_queue<pair<vector<int>, int>,vector<pair<vector<int>, int>>,comp>pq;
        for(int i=0;i<points.size();i++){
            int a = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            if(!pq.empty() && pq.top().second>a){
                pq.push({points[i],a});
            }else{
                pq.push({points[i],a});
            }
            while(!pq.empty() && pq.size()>k){
                pq.pop();
            }
            
        }
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};