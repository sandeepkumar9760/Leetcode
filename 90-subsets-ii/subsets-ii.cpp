class Solution {
public:
    void subsets2(vector<int>& nums , vector<vector<int>>&ans , vector<int>crr , int i){
        if(i==nums.size()){
            ans.push_back({crr});
            return;
        }
        crr.push_back(nums[i]);
        subsets2(nums,ans,crr,i+1);
        crr.pop_back();
        int index = i+1;
        while(index<nums.size() && nums[i]==nums[index]) index++;
        subsets2(nums,ans,crr,index);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>crr;
        subsets2(nums,ans,crr,0);
        return ans;
    }
};