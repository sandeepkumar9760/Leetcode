class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best_prod = nums[0];
        int res_prod = nums[0];
        int min_prod = nums[0];

        for(int i=1; i<nums.size(); i++){
            int crr_prod = nums[i];
            int prod = best_prod * nums[i];
            int prod_min = nums[i] * min_prod;
            min_prod = min(crr_prod,min(prod,prod_min));
            best_prod = max(crr_prod,max(prod,prod_min));
            res_prod = max(res_prod,max(best_prod,min_prod));
        }
        return res_prod;
    }
};