class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero_count = 0;
        int one_count = 0;
        unordered_map<int,int>map;
        int res = 0;
        map[0] = -1;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zero_count++;
            }else{
                one_count++;
            }
            int diff = zero_count - one_count;
            if(map.find(diff)!=map.end()){
                int len = i-map[diff];
                res = max(res,len);
                continue;
            }else{
                map[diff]=i;
            }
        }
        return res;
    }
};