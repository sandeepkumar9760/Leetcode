class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>count(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            if(count[nums[i]]!=0){
                return nums[i];
            }else{
                count[nums[i]]++;
            }
        }
        return -1;
    }
};