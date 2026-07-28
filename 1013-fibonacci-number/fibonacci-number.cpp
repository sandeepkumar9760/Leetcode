class Solution {
public:
    int find_dp(int n , vector<int>&dp){
        if(n==0 || n==1) return n;
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=find_dp(n-1,dp)+find_dp(n-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return find_dp(n,dp);
    }
};