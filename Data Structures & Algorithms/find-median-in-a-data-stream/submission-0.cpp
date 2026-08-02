class MedianFinder {
public:
    priority_queue<int> p1;
    priority_queue<int, vector<int>, greater<int>>p2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int x = p1.size();
        int y = p2.size();
        if(x > y) {
            p2.push(num);
        }
        else {
            p1.push(num);    
        }
        int x1 = p1.top();
        int y1 = 1e9;
        if(!p2.empty()) y1 = p2.top();
        if(x1 > y1) {
            p1.pop();
            p2.pop();
            p1.push(y1);
            p2.push(x1);
        }
    }
    
    double findMedian() {
        int x = p1.size();
        int y = p2.size();
        if(x>y) return p1.top();
        return (p1.top() + p2.top()) / 2.0;
    }
};
