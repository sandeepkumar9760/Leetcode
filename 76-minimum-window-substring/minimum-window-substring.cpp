class Solution {
public:
    bool is_possible(vector<int>&want , vector<int>&have){
        for(int i=0;i<256;i++){
            if(have[i]>want[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        // if(t==s) return s;
        vector<int>have(256,0);
        vector<int>want(256,0);
        for(int i=0;i<t.size();i++){
            have[t[i]-'A']++;
        }
        int low = 0 , high = 0;
        int ans_low = 0;
        int ans_high = 0;
        bool possible = false;
        int final_length = INT_MAX;
        while(high<s.size()){
            want[s[high]-'A']++;
            while(is_possible(want,have)){
                possible = true;
                int crr_length = high - low + 1;
                if(crr_length<final_length){
                    ans_low = low;
                    ans_high = high;
                    final_length = crr_length;
                }
                want[s[low]-'A']--;
                low++;
            }
            high++;
        }
        if(possible){
            return s.substr(ans_low,ans_high-ans_low+1);
        }else{
            return "";
        }
    }
};