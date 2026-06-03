class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int min_diff = INT_MAX;
        int ans = 0;
        for(int i=0; i<nums.size()-2; i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                int diff = abs(sum-target);
                if(diff<min_diff){
                    min_diff = diff;
                    ans = sum;
                }
                if(sum==target){
                    return sum;
                }
                if(sum<target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return ans;
    }
};