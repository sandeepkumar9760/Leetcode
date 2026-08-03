

class Solution {
public:
    struct cmp {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        int size = words.size();
        unordered_map<string,int>map;
        for(int i=0;i<size;i++){
            map[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto &it : map){
            pq.push({it.second,it.first});
        }
        vector<string>ans;
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