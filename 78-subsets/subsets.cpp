class Solution {
public:
    void subsets2(vector<int>& nums , vector<int>crr , vector<vector<int>>&ans , int i){
        if(i==nums.size()){
            ans.push_back({crr});
            // for(int val : crr) cout<<val<<" ";
            return;
        }
        crr.push_back(nums[i]);
        subsets2(nums,crr,ans,i+1);
        crr.pop_back();
        subsets2(nums,crr,ans,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>crr;
        subsets2(nums,crr,ans,0);
        return ans;
    }
};