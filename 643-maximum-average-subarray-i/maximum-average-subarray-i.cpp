class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int>prefix(nums.size(),1);
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        double ans = double(prefix[k-1])/k;
        for(int i=k;i<nums.size();i++){
            double crr_ans = double(prefix[i]-prefix[i-k])/k;
            ans = max(ans,crr_ans);
        }
        return ans;
    }
};