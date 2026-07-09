class Solution {
public:
    long long cool(vector<int> &piles, int k) {
        long long h = 0;
        for (int i = 0; i < piles.size(); i++) {
            h += (piles[i] + k - 1) / k;
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1; 
        int j = 0;
        for (int pile : piles) {
            j = max(j, pile);
        }
        int ans = j;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (cool(piles, mid) <= h) {
                ans = mid;        
                j = mid - 1;      
            } else {
                i = mid + 1;      
            }
        }
        return ans;
    }
};