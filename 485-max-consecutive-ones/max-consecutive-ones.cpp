class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int crr_ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                crr_ans++;
                ans = max(ans,crr_ans);
            }else{
                ans = max(ans,crr_ans);
                crr_ans = 0;
            }
        }
        return ans;
    }
};