class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if((mid-1>=0 && mid+1<n && nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]) || (mid-1<0 && nums[mid]<nums[mid+1]) || (mid+1>=n && nums[mid]<nums[mid-1])){
                return nums[mid];
            }else if(nums[mid]>nums[end]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return -1;
    }
};