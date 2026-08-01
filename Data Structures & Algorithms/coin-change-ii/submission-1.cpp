class Solution {
public: 
    int help(int i, int amount, vector<vector<int>> &dp, vector<int> &coins){
        if(amount < 0) return 0;
        else if (amount == 0) return 1;
        if(i >= coins.size()) {
            if(amount == 0) return 1;
            return 0;
        }
        if(dp[i][amount] !=-1) return dp[i][amount];
        int ans = 0;
        ans += help(i+1,amount,dp,coins) + help(i,amount-coins[i],dp,coins);
        return dp[i][amount] = ans;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return help(0,amount,dp,coins);   
    }
};
