class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        vector<pair<int,int>> v;
        int n =  pos.size();
        for(int i = 0; i<n; i++){
            v.push_back({pos[i],sp[i]});
        }
        sort(v.begin(),v.end());
        // reverse(v.begin(),v.end());
        int s1 = 101;
        int d1 = 0;
        int ans = 0;
        for(int i = n - 1; i >=0; i--){
            // cout << "amd" << endl;
            int d2 = target - v[i].first;
            int s2 = v[i].second;
            if(d2*s1 > d1*s2){
                s1 = s2;
                d1 = d2;
                ans++;
            } else {
                continue;
            }
        }
        return ans;
    }
};
