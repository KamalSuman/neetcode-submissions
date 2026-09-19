class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& word) {
        unordered_set<string> s1(word.begin(),word.end());
        s1.erase(beginWord);
        int ans = 0;
        queue<string> q;
        q.push(beginWord);
        bool f = false;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            for(int i = 0; i<sz; i++){
                string node = q.front();
                q.pop();
                for(int j = 0; j < node.size(); j++){
                    char original = node[j];
                    for(char c = 'a' ; c <= 'z' ; c++){
                        node[j] = c;
                        auto it  = s1.find(node);
                        if(it == s1.end()) continue;
                        else {
                            if(node == endWord) return ans+1;
                            s1.erase(it);
                            q.push(node);
                        }
                    }
                    node[j] = original;
                }
            }
        }
        return 0;
    }
};
