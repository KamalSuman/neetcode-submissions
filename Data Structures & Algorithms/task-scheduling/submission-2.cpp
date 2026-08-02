class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int maxi = 0;
        for(int i = 0; i<tasks.size(); i++) {
            freq[tasks[i]-'A']++;
            maxi = max(maxi, freq[tasks[i]-'A']);
        }
        int idle = (maxi-1) * n;
        bool f = false;
        for(int i = 0; i<26; i++) {
            if(freq[i] == maxi && !f){
                f = true;
                continue;
            }
            idle -= min(freq[i],maxi-1);
        }
        
        int ans = 0;
        ans += tasks.size() + max(0,idle);
        return ans;
    }
};
