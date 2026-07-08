class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<pair<int,int>> st;
        int n = h.size();
        vector<int> r(n,0);
        vector<int> l(n,0);
        st.push({-1,n-1});
        for(int i = n - 1; i >= 0; i--){
            int l = i;
            while(h[i] <= st.top().first) {
                l = st.top().second;
                st.pop();
            }
            r[i] = l;
            st.push({h[i],l});
        }
        while(!st.empty()) st.pop();
        st.push({-1,0});
        for(int i = 0; i<n; i++){
            int l1 = i;
            while(h[i] <= st.top().first) {
                l1 = st.top().second;
                st.pop();
            }
            l[i] = l1;
            st.push({h[i],l1});
        }
        
        int ans = -1;
        for(int i = 0; i<n; i++){
            ans = max(ans, h[i] * (r[i]-l[i]+1));
        }
        return ans;
    }
};
