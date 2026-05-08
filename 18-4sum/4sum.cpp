class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for (int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for (int j=i+1; j<nums.size();){
                int first = j+1;
                int last = nums.size()-1;
                while(first<last){
                    long long sum = (long long) nums[i]+(long long) nums[j]+(long long) nums[first]+(long long) nums[last];

                    if(sum>target){
                        last--;
                    }else if(sum<target){
                        first++;
                    }else{
                        ans.push_back({nums[i],nums[j],nums[first],nums[last]});
                        first++;
                        last--;
                        while(first<last && nums[first]==nums[first-1]) first++;
                        while(first<last && nums[last] == nums[last+1]) last--;
                        
                    }
                }
                j++;
                while(j<nums.size() && nums[j]==nums[j-1]) j++;
            }
        }
        return ans;
    }
};