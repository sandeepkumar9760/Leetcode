class Solution {
public:
    void helper(int idx,vector<vector<int>>&ans , vector<int>&crr_arr ,  int size , int sum , int crr_sum){
        if(crr_arr.size()==size){
            if(crr_sum==sum){
                ans.push_back(crr_arr);
            }
            return;
        }

        for(int i=idx;i<10;i++){
            crr_arr.push_back(i);
            helper(i+1,ans,crr_arr,size,sum,crr_sum+i);
            crr_arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>crr_arr;
        helper(1,ans,crr_arr,k,n,0);
        return ans;
    }
};