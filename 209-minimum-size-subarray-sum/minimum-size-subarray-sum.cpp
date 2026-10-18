class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int low = 0;
        int high = 0;
        int min_len = INT_MAX;
        int crr_sum = 0;
        while (high < size) {
            crr_sum += nums[high];
            while (crr_sum >= target) {
                min_len = min(min_len , high-low+1);
                crr_sum -= nums[low];
                low++;
            }
            high++;
        }
        if(min_len<INT_MAX){
            return min_len;
        }else{
            return 0;
        }
    }
};