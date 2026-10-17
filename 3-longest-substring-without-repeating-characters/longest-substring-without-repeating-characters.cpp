class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int low = 0;
        unordered_map<int,int>map;
        int max_len = 0;
        for(int i=0;i<s.size();i++){
            if(map.find(s[i])!=map.end()){
                while(map.find(s[i])!=map.end()){
                    map[s[low]]--;
                    
                    if(map[s[low]]==0){
                        map.erase(s[low]);
                    }
                    low++;
                }
            }
            map[s[i]]++;
            max_len = max(max_len , i-low+1);
        }
        return max_len;
    }
};