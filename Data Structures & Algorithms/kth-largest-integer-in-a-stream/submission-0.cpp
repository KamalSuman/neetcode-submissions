class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0; i<nums.size(); i++){
            if(pq.size() < k) {
                pq.push(nums[i]);
            } else {
                if(pq.top() >= nums[i]) continue;
                else {pq.pop();
                pq.push(nums[i]);}
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < k){
            pq.push(val);
            return pq.top();
        } else{
            if(pq.top() >= val) {}
            else {pq.pop();
            pq.push(val);}
            return pq.top();
        }
    }
};
