class Solution {
public:
    bool is_palindrome(string str , int start , int end){
        while(start<=end){
            if(str[start]!=str[end]) return false;
            start++ ; end--;
        }
        return true;
    }
    void solve(int idx , vector<vector<string>>&ans , vector<string>&temp , string str){
        if(idx==str.size()){
            ans.push_back({temp});
            return;
        }
        for(int i=idx;i<str.size();i++){
            if(is_palindrome(str,idx,i)){
                temp.push_back(str.substr(idx,i-idx+1));
                solve(i+1,ans,temp,str);
                temp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,ans,temp,s);
        return ans;
    }
};