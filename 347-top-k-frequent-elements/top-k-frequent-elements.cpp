class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        vector<vector<int>>bucket(nums.size()+1);
        for(auto &it : map){
            bucket[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int i=bucket.size()-1; i>=1 && ans.size()<k; i--){
            for(auto &it : bucket[i]){
                ans.push_back(it);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};