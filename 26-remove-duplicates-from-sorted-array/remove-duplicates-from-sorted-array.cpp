class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0;
        int size = 1;
        for(int high=1;high<nums.size();high++){
            if(nums[high]!=nums[low]){
                low++;
                size++;
                swap(nums[low],nums[high]);
            }
        }
        return size;
    }
};