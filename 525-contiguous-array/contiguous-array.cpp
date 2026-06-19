class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero_count = 0;
        int one_count = 0;
        unordered_map<int,int>map;
        int res = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zero_count++;
            }else{
                one_count++;
            }
            int diff = zero_count - one_count;
            if(diff==0){
                res = max(res , i+1);
            }
            if(map.find(diff)!=map.end()){
                int len = i-map[diff];
                res = max(res,len);
            }else{
                map[diff]=i;
            }
        }
        return res;
    }
};