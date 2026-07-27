class Solution {
public:
    bool is_possible(int mid , int t , vector<int>&nums){
        int sum = 0;
        for(int i=0;i<nums.size(); i++){
            int ceil = (nums[i]+mid-1)/mid;
            sum+=ceil;
        }
        return sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin() , nums.end());
        int ans = INT_MAX;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(is_possible(mid,threshold,nums)){
                ans = mid; 
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};