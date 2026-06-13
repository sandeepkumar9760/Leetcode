class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int best_sum = nums[0];
        int res = nums[0];
        int min_sum = nums[0];
        int best_min = nums[0];
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            int crr_sum = best_sum + nums[i];
            best_sum = max(crr_sum , nums[i]);
            int crr_min_sum = min_sum + nums[i];
            min_sum = min(crr_min_sum , nums[i]);
            best_min = min(best_min , min_sum);
            res = max(res,best_sum);
            sum += nums[i];
        }
        if(sum==best_min){
            return res;
        }else{
            res = max(res,(sum-best_min));
        }
        return res;
        
    }
};