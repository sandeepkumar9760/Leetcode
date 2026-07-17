class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_val = nums.size();
        for(int i=0;i<nums.size();i++){
            xor_val ^= i;
            xor_val ^= nums[i];
        }
        return xor_val;
    }
};