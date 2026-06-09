class Solution {
public:
    bool check(vector<int>have , vector<int>want){
        for(int i=0; i<256; i++){
            if(have[i]<want[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        string res = "";
        if(s.length()<t.size()) return res;
        vector<int>have(256,0);
        vector<int>want(256,0);
        for(int i=0; i<t.length(); i++){
            want[t[i]]++;
        }
        int low = 0;
        int start = 0;
        int res_len = INT_MAX;
        for(int high=0; high<s.size(); high++){
            have[s[high]]++;
            while(check(have,want)){
               int len = high - low + 1;
               if(res_len>len){
                res_len = len;
                start = low;
               }
               have[s[low]]--;
               low++;
            }

        }
        if(res_len==INT_MAX){
            return "";
        }else{
            return s.substr(start,res_len);
        }
    }
};