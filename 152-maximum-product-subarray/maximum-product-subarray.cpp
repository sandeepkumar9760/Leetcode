class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int ans = INT_MIN;
        int suffix = 1;
        for(int i=0;i<nums.size();i++){
            if(prefix==0)prefix=1;
            prefix *= nums[i];
            ans = max(ans,prefix);
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(suffix==0)suffix=1;
            suffix *= nums[i];
            ans = max(ans,suffix);
        }
        return ans;
    }
};