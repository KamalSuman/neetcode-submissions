class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        vector<int> sz;
        for(string s: strs){
            ans += s;
            sz.push_back(s.size());
        }
        // for(int i = 0; i<sz.size(); i++) cout << sz[i] << " ";
        // cout << endl;
        for(int x: sz){
            if(x<=9) ans += ("00" + to_string(x));
            else if(x>9 && x<=100) ans += ("0" + to_string(x));
            else ans += to_string(x);
        }
        ans += "@" + to_string(n);
        // cout << ans;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string s1  = s;
        int n = s1.size();
        // cout << s1 << " ";
        // cout << n << endl;
        vector<int> sz;
        int size;
        int i = n - 1;
        for(; i>=0; ){
            if(s1[i] != '@') i--;
            else {size = stoi(s1.substr(i+1)); i--; break; }
        }
//         cout << size << endl;
// cout << endl << i << endl;
       for(int j = 0; j<size; j++){
            string str = s1.substr(i-2,3); i-=3;
            // cout << str << " ";
            int p = stoi(str);
            // cout << p << " ";
            sz.push_back(p);
       }
    //    for(int j = 0; j<sz.size(); j++) cout << sz[j] << " ";
       reverse(sz.begin(),sz.end());
       int k = 0;
       for(int j = 0; j<size; j++){
           ans.push_back(s1.substr(k,sz[j]));
           k += sz[j];
       }
    return ans;

    }
};
