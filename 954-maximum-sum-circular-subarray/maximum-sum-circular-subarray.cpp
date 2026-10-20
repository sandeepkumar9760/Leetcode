class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum = nums[0];
        int best_min_sum = nums[0];
        int min_sum = nums[0];
        int crr_sum = nums[0];
        int total_sum = nums[0];
        for(int i=1;i<nums.size();i++){
            crr_sum += nums[i];
            crr_sum = max(crr_sum , nums[i]);
            min_sum += nums[i];
            min_sum = min(min_sum , nums[i]);
            total_sum += nums[i];
            max_sum = max(max_sum , crr_sum);
            best_min_sum = min(best_min_sum , min_sum);
        }
        if(max_sum<0){
            return max_sum;
        }else{
            return max(max_sum , (total_sum - best_min_sum));
        }
    }
};