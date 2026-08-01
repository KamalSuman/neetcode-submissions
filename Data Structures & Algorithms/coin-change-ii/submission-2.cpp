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
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = 1;
            }
        }
        for(int j = 1; j<n; j++){
            dp[j][0] = 1;
            for(int i = 1; i<=amount; i++){
                dp[j][i] = dp[j-1][i];
                if(i - coins[j] >= 0) dp[j][i] += dp[j][i-coins[j]];
            }
        }
        return dp[n-1][amount];   
    }
};
