class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int low = 0;
        unordered_map<char,int>map;
        int res = INT_MIN;
        for(int high=0;high<=s.size()-1;high++){
            map[s[high]]++;
            int crr_length = high-low+1;
            while(map.size()<crr_length){
                map[s[low]]--;
                if(map[s[low]]==0){
                    map.erase(s[low]);
                }
                low++;
                crr_length = map.size();
            }
            
            res = max(crr_length,res);
        }
        if(res>INT_MIN){
            return res;
        }
        return 0;
    }
};