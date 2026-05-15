class Solution {
public:
    set<vector<int>>s;
    void helper(vector<int>& candidates , vector<int>& comb, vector<vector<int>>& ans , int index , int target){
        if(target==0){
            if(s.find(comb)==s.end()){
                ans.push_back({comb});
                s.insert(comb);
                return;
            }
        }
        if(target<0 || index==candidates.size()){
            return;
        }
        comb.push_back(candidates[index]);
        helper(candidates , comb , ans , index+1 , target-candidates[index]);
        helper(candidates , comb , ans , index , target-candidates[index]);
        comb.pop_back();
        helper(candidates , comb , ans , index+1 , target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>comb;
        helper(candidates , comb ,ans , 0 , target);
        return ans;
    }
};