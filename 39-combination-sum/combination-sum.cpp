class Solution {
public:
    void solve(vector<int>& candidates , int target , int crr_sum , vector<int>&crr_arr , vector<vector<int>>&ans, int idx){
        if(crr_sum==target){
            ans.push_back(crr_arr);
            return;
        }
        if(idx>=candidates.size() || crr_sum>target){
            return;
        }
        crr_arr.push_back(candidates[idx]);
        solve(candidates,target,crr_sum+candidates[idx],crr_arr,ans,idx);
        crr_arr.pop_back();
        solve(candidates,target,crr_sum,crr_arr,ans,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>crr_arr;
        vector<vector<int>>ans;
        solve(candidates,target,0,crr_arr,ans,0);
        return ans;

    }
};