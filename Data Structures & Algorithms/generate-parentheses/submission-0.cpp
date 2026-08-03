class Solution {
public:
    vector<string> ans;
    void help(int o, int c, string s){
        if(c == 0) ans.push_back(s);
        if(o) help(o-1,c,s+'(');
        if(c>o) help(o,c-1,s+')');

    }
    vector<string> generateParenthesis(int n) {
        string s="";
        help(n,n,s);
        return ans;
    }
};
