class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = nums[0];
        int res_sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            int crr_sum = best_sum + nums[i];
            int new_sum = nums[i];
            best_sum = max(crr_sum,new_sum);
            res_sum = max(best_sum,res_sum);
        }
        return res_sum;
    }
};