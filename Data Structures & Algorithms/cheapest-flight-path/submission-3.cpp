class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int,int>>> g(n);
        for(auto &f : flights){
            g[f[0]].push_back({f[1], f[2]});
        }

        // {cost, stops, city}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // val[city] = minimum stops recorded when POPPED
        vector<int> val(n, INT_MAX);

        pq.push({0, 0, src});

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            int cost = node[0];
            int stops = node[1];
            int city = node[2];

            if(city == dest) return cost;
            if(stops > k) continue;

            // If we've already popped this city with fewer or equal stops, skip it
            if(stops >= val[city]) continue;
            val[city] = stops;

            for(auto &[child, wt]: g[city]){
                pq.push({cost + wt, stops + 1, child});
            }
        }

        return -1;
    }
};