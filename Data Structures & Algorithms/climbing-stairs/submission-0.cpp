class Solution {
public:
    vector<int> dp;
    int help(int n){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n] != -1) return dp[n]; 
        int ans = help(n-1) + help(n-2);
        return dp[n] = ans;
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return help(n);
    }

};
