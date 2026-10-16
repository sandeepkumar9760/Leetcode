class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        int max_len = 0;
        for(auto it : map){
            if(map.find(it.first-1)==map.end()){
                int start_ele = it.first;
                int len = 1;
                while(map.find(start_ele+1)!=map.end()){
                    len++;
                    start_ele++;
                }
                max_len = max(max_len,len);
            }
        }
        return max_len;
    }
};