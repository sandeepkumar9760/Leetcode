class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        int max_len = 0;
        for(auto i : map){
            if(map.find(i.first-1)==map.end()){
                int start_seq = i.first;
                int len = 1;
                while(map.find(start_seq + 1)!=map.end()){
                    start_seq++;
                    len++;
                }
                max_len = max(len,max_len);
            }
        }
        return max_len;
    }
};