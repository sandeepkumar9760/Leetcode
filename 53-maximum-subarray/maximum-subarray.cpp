class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int crr_sum = nums[0];
        int max_sum = nums[0];
        for(int i=1;i<nums.size();i++){
            crr_sum += nums[i];
            max_sum = max(max_sum , max(crr_sum,nums[i]));
            crr_sum = max(crr_sum , nums[i]);
            
        }
        return max_sum;
    }
};