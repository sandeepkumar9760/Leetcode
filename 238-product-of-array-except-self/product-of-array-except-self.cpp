class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>prefix(size,1);
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        int suffix = 1;
        for(int i=size-1;i>=0;i--){
            prefix[i] = suffix * prefix[i];
            suffix = nums[i] * suffix;
        }
        return prefix;
    }
};