class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if((mid-1>=0 && mid+1<nums.size() && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) || (mid-1<0 && mid+1<nums.size() && nums[mid]>nums[mid+1]) || (mid+1>=nums.size() && nums[mid]>nums[mid-1])){
                return mid;
            }else if(mid+1<nums.size() && nums[mid]<nums[mid+1]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return -1;
    }
};