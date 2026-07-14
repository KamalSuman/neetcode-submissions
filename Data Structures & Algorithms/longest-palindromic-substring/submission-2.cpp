class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp;
        int n = s.size();
        dp.resize(n,vector<int>(n,-1));
        int ans = 1;
        int l = 0, k = 0;
        for(int i = 0; i<n; i++){
            for(int j = i ; j >= 0; j--){
                if( j == i) dp[j][i] = true;
                else if(j+1 >= i-1) dp[j][i] = (s[j]==s[i]);
                else dp[j][i] = (dp[j+1][i-1] & (s[j]==s[i]));
                if((dp[j][i] == 1) && (ans < i-j+1)){
                    ans = i-j+1;
                    l = j;
                    k = i;
                }
            }
        }
        string res = "";
        for(int i = l; i<=k; i++){
            res += s[i];
        }
        return res;
    }
};
