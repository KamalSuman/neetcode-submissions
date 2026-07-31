class Solution {
public:
    vector<int> dp;
    bool help(string &s, int i, vector<string>& dict){
        if(i >= (int)s.size()) return true;
        if(dp[i] != -1) return dp[i];
        bool ans = false;
        for(int j = 0; j < (int)dict.size(); j++){
            int l = dict[j].size();
            string temp = "";
            for(int k = i; k < i +l && k < (int)s.size(); k++){
                temp += s[k];
            }
            if(dict[j] == temp) ans = ans | help(s, i+l,dict);
        }
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        dp.resize(n,-1);
        return help(s,0,wordDict);
    }
};
