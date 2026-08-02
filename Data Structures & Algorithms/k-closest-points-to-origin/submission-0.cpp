class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int d = x*x + y*y;
            if(pq.size() < k){
                pq.push({d,i});
            } else {
                if(pq.top().first > d) {
                    pq.pop();
                    pq.push({d,i});
                } else continue;
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};
