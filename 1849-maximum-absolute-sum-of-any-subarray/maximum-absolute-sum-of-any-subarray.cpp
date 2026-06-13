class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = abs(nums[0]);
        int min_sum = INT_MAX;
        int res = abs(nums[0]);
        int crr_max_sum = nums[0];
        int crr_min_sum = nums[0];
        for(int i=1; i<nums.size(); i++){
           crr_max_sum = max(nums[i] , crr_max_sum + nums[i]);
           max_sum = max(max_sum , crr_max_sum);

           crr_min_sum = min(nums[i], crr_min_sum + nums[i]);
           min_sum = min(crr_min_sum , min_sum);
           res = max(max_sum , abs(min_sum));
        }
        return res;
        
    }
};