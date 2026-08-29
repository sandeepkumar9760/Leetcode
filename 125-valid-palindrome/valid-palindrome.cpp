class Solution {
public:
    bool isvalid(string s , int start){
        return (s[start] >= 'a' && s[start] <= 'z' || s[start]>='A' && s[start]<='Z' || s[start]>='0' && s[start]<='9');
    }
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start<=end){
            if(!isvalid(s,start)){
                start++;
                continue;
            }
            if(!isvalid(s,end)){
                end--;
                continue;
            }
            if(tolower(s[start])!=tolower(s[end])) return false;
            start++;
            end--;
        }
        return true;
    }
};