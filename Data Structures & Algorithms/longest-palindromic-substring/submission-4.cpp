class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> dp,dp1;
        int n = s.size();
        dp.resize(n,0);
        dp1.resize(n,0);
        int ans = 1;
        int l = 0, k = 0;
        for(int i = 0; i<n; i++){
            for(int j = i ; j >= 0; j--){
                int temp = 0;
                if( j == i) temp = true;
                else if(j+1 >= i-1) temp = (s[j]==s[i]);
                else temp = (dp[j+1] & (s[j]==s[i]));
                if((temp == 1) && (ans < i-j+1)){
                    ans = i-j+1;
                    l = j;
                    k = i;
                }
                dp1[j] = temp;
            }
            for(int j = 0; j<n; j++) dp[j] = dp1[j];
        }
        string res = "";
        for(int i = l; i<=k; i++){
            res += s[i];
        }
        return res;
    }
};
