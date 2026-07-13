class Solution {
public:
    vector<int> dp;
    int help(vector<int> &cost, int i){
        if( i >= cost.size() ) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = cost[i] + min(help(cost,i+1),help(cost,i+2));
        return dp[i] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize((int)cost.size(),-1);
        help(cost,0);
        return min(dp[0],dp[1]);
    }
};
