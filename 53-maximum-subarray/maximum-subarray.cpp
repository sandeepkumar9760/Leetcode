class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int crr_sum = nums[0];
        int max_sum = nums[0];
        for(int i=1;i<nums.size();i++){
            crr_sum = max(nums[i] , crr_sum+nums[i]);
            max_sum = max(max_sum , crr_sum);
        }
        return max_sum;
    }
};