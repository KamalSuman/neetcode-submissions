class Solution {
public:
    bool creategraph(string word1, string word2, vector<vector<int>> &graph, vector<int> &vis){
        int i = 0, j=0;
        while(i<word1.size() && j<word2.size()){
            if(word1[i] != word2[j]) {
                break;
            }
            i++; j++;
        }
        if(j == word2.size() && word2.size() < word1.size()) return false;
        if(i == word1.size()) return true;
        graph[word1[i]-'a'].push_back(word2[j]-'a');
        vis[word2[j]-'a']++;
        return true;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> graph(26);
        vector<int> vis(26,-1);
        for(int i = 0; i<n; i++){
            for(char c: words[i]){
                vis[c-'a'] = 0;
            }
        }
        for(int i = 0; i<n-1; i++){
            if(!creategraph(words[i],words[i+1],graph,vis)) return "";
        }
        // cout << "debug1 " << endl;
        queue<int> q;
        string ans = "";
        for(int i = 0; i<26; i++){
            if(vis[i] == 0) {
                q.push(i);
                ans += i + 'a';
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                int par = q.front();
                q.pop();
                for(auto &child : graph[par]) {
                    vis[child]--;
                    if(vis[child] == 0) {
                        ans += child + 'a';
                        q.push(child);
                    }
                }
            }
        }
        for(int i = 0; i<26; i++) {
            if(vis[i] > 0) return "";
        }
        return ans;
    }
};
