class Solution {
public:
    double distance(vector<int>& point) {
        int a = pow(point[0], 2);
        int b = pow(point[1], 2);
        return sqrt(a + b);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>,
                       greater<pair<double, vector<int>>>>
            pq;
        int size = points.size();
        for (int i = 0; i < size; i++) {
            double dist = distance(points[i]);
            pq.push({dist, points[i]});
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
            if (ans.size() == k) {
                return ans;
            }
        }
        return ans;
    }
};