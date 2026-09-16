class Solution {
public:
    void solve(string digits , vector<string>&map , int idx , vector<string>&ans , string crr_str){
        if(crr_str.size()==digits.size()){
            ans.push_back(crr_str);
            return;
        }
        string s = map[digits[idx]-'0'];
        for(int i=0;i<s.size();i++){
            crr_str.push_back(s[i]);
            solve(digits,map,idx+1,ans,crr_str);
            crr_str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>map{" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        solve(digits,map,0,ans,"");
        return ans;
    }
};