class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int sum = 0;
        map[0] = 1;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int ans = sum - k;
            if(map.find(ans)!=map.end()){
                count+=map[ans];
            }
            map[sum]++;
        }
        return count;
    }
};