class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        unordered_map<char,int>map;
        int res = INT_MIN;
        for(int high=0; high<s.length(); high++){
            map[s[high]]++;
            int crr_len = high-low+1;
            while(map.size()<crr_len){
                map[s[low]]--;
                if(map[s[low]]==0){
                    map.erase(s[low]);
                }
                low++;
                crr_len = high-low+1;
            }
            res = max(res,crr_len);
        }
        if(res>INT_MIN){
            return res;
        }else{
            return 0;
        }
    }
};