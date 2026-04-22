class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>count1(26,0);
        vector<int>count2(26,0);
        if(s1.length()>s2.length()) return false;
        for(int i=0; i<s1.length(); i++){
            count1[s1[i]-'a']++;
        }
        int k = s1.length();
        for(int i=0; i<s1.length(); i++){
            count2[s2[i]-'a']++;
        }
        if(count1==count2) return true;
        for(int i=k; i<s2.length(); i++){
            count2[s2[i]-'a']++;
            count2[s2[i-k]-'a']--;

            if(count1==count2) return true;
        }
        return false;
    }
   
};