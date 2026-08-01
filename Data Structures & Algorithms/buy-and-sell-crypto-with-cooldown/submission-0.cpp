class Solution {
public:
    int help(vector<int>& prices, int i, int b, vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;
        if(dp[i][b] != -1) return dp[i][b];
        int ans = 0;
        if(b == 0) {
            ans = max(help(prices, i+1, !b, dp) - prices[i], help(prices, i+1, b, dp));
        } else {
            ans = max(help(prices, i+2, !b, dp) + prices[i], help(prices, i+1, b, dp));
        }
        return dp[i][b] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return help(prices, 0,0,dp);
    }
};
