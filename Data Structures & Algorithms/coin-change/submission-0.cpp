class Solution {
public:

    vector<vector<int>> dp;
    int help(vector<int> &coins, int i, int amount){
        if(amount < 0 || i >= coins.size()) return 1e9;
        if(amount == 0) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        int ans = 1e9; 
        ans = min(1 + help(coins, i, amount - coins[i]), min(1 + help(coins, i+1, amount - coins[i]), help(coins, i+1, amount)));
        return dp[i][amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return help(coins, 0, amount) == 1e9 ? -1 : help(coins,0,amount);
    }
};
