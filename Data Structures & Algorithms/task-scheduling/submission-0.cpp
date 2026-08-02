class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i = 0; i<tasks.size(); i++) freq[tasks[i]-'A']++;
        priority_queue<int> pq;
        for(int i = 0; i<26; i++) {
            if(freq[i] != 0) pq.push(freq[i]);
        }
        int ans = 0;
        while(pq.size() > n+1){
            ans += n+1;
            for(int i = 0; i <=n; i++){
                int x = pq.top();
                pq.pop();
                x--;
                if(x){
                    pq.push(x);
                }
            }
        }
        int y = pq.top();
        int z = 0;
        while(!pq.empty()){
            if(pq.top() == y) z++;
            pq.pop();
        }
        ans += (y-1)*(n+1) + z;
        return ans;
    }
};
