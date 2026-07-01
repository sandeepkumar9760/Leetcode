class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char c : s){
            mp[c]++;
        }
        int count = 0;
        bool odd = false;
        for(auto i : mp){
            if(i.second%2==0){
                count += i.second;
            }else{
                count += (i.second -1);
                odd = true;
            }
        }
        if(odd){
            return count+1;
        }else{
            return count;
        }

    }
};