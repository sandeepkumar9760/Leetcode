class Solution {
public:
    void solve(vector<string>&ans , string &temp , int open , int close , int n){
        if(open==n && close==n){
            ans.push_back(temp);
            return;
        }
        if(open<n){
            temp.push_back('(');
            solve(ans,temp,open+1,close,n);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            solve(ans,temp,open,close+1,n);
            temp.pop_back();

        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        solve(ans,temp,0,0,n);
        return ans;
    }
};