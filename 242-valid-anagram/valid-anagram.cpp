class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int>word1(26,0);
        vector<int>word2(26,0);
        for(int i=0;i<s.size();i++){
            word1[s[i]-'a']++;
            word2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(word1[i]!=word2[i]) return false;
        }
        return true;
    }
};