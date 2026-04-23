#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";
        int i = 0;

        while (i < s.length()) {
            // skip spaces
            while (i < s.length() && s[i] == ' ') i++;

            string word = "";

            // build word
            while (i < s.length() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            if (word.length() > 0) {
                reverse(word.begin(), word.end());
                
                if (!ans.empty()) ans += " ";
                ans += word;
            }
        }

        return ans;
    }
};