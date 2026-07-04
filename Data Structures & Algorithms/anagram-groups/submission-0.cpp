class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> strs1 = strs;
        for(int i = 0; i<n; i++){
            sort(strs1[i].begin(), strs1[i].end());
        }
        vector<vector<int>> ans;
        // sort(strs1.begin(),strs1.end());
        // for(int i = 0; i<n; i++) cout << strs1[i] <<" "; 
        vector<int> vis(n,0);
        for(int i = 0; i<n; i++){
            if(vis[i]) continue;
            vis[i] = 1;
            vector<int> temp;
            temp.push_back(i);
            for(int j = 0; j<n ; j++){
                if(i == j) continue;
                if(strs1[i] == strs1[j]){
                    temp.push_back(j);
                    vis[j] = 1;
                }
            }
            ans.push_back(temp);
        }
        // cout << ans.size() << endl;
        vector<vector<string>> s;
        for(int i = 0; i < ans.size(); i++){
            // cout << i << endl;
            vector<string> s1;
            for(int x: ans[i]){
                // cout << x << " ";
                s1.push_back(strs[x]);
            }
            s.push_back(s1);
        }
        return s;
    }
};
