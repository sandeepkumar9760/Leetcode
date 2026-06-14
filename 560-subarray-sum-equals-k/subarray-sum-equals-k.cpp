class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        unordered_map<long long , int>map;
        map[0] = 1;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int target = sum - k;
            if(map.find(target)!=map.end()){
                count+=map[target];
            }
            map[sum]++;
        }
        return count;
    }
};