class Solution {
public:
    int help(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s1[i] == s2[j]) ans = max(ans, 1 + help(i+1, j+1, s1, s2, dp));
        else ans = max(ans , max(help(i+1,j,s1,s2,dp),help(i,j+1,s1,s2,dp)));
        return dp[i][j] = ans; 
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return help(0,0,text1,text2,dp);
    }
};
