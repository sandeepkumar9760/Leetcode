class Solution {
public:
    struct compare {
        bool operator()(const pair<int,int>&a , const pair<int,int>&b){
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        for(auto &it : map){
            pq.push({it.first , it.second});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};