class Solution {
public:
    int possible(unordered_map<char,int>map , int wd_size){
        int len = INT_MIN;
        for(auto &it : map){
            len = max(len , it.second);
        }
        return wd_size-len;
    }
    int characterReplacement(string s, int k) {
        int size = s.size();
        unordered_map<char,int>map;
        int low = 0;
        int max_len = 0;
        for(int high=0;high<size;high++){
            map[s[high]]++;
            if(map.size()>1){
                int len = possible(map , high-low+1);
                if(len<=k){
                    max_len = max(max_len , high-low+1);
                }else{
                    map[s[low]]--;
                    low++;
                }
            }else{
                max_len = max(max_len , high-low+1);
            }
        }
        return max_len;
    }
};