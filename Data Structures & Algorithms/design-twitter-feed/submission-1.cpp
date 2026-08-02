class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int t = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({t++,tweetId});     
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_set<int> followee = following[userId];
        int sz = 0;
        for(int i = tweets[userId].size() - 1; i >= 0 && sz < 10; i--){
            pq.push(tweets[userId][i]);
            sz++;
        }
        
        for(auto s: followee){
            vector<pair<int,int>> t = tweets[s];
            sz = 0;
            for(int i = t.size() -1; i>=0 && sz < 10; i--){
                if(pq.size() < 10){
                    pq.push(t[i]);
                } else{
                    int top = pq.top().first;
                    if(t[i].first > top) {
                        pq.pop();
                        pq.push(t[i]);
                    }
                }
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].erase(followeeId);
    }
};
