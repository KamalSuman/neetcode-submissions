class Solution {
public:
    int help(string s, string t, int i, int j, vector<vector<int>> &dp){
        if(i == s.size()) return t.size() - j ;
        if(j == t.size()) return s.size() - i ;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1000;
        if(s[i] == t[j]) ans = min(ans,help(s,t,i+1,j+1,dp));
        else {
            ans = min(ans,1 + min(help(s,t,i+1,j,dp),min(help(s,t,i,j+1,dp),help(s,t,i+1,j+1,dp))));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return help(s,t,0,0,dp);
    }
};
