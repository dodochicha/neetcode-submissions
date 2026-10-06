class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (max_heap.size() == 0 || num <= max_heap.top()) {
            max_heap.push(num);
        }
        else {
            min_heap.push(num);
        }
        if (max_heap.size() > min_heap.size() + 1) {
            int item = max_heap.top();
            max_heap.pop();
            min_heap.push(item);
        }
        if (min_heap.size() > max_heap.size()) {
            int item = min_heap.top();
            min_heap.pop();
            max_heap.push(item);
        }
    }
    
    double findMedian() {
        if (min_heap.size() == max_heap.size()) return (min_heap.top() + max_heap.top()) / 2.0;
        else return max_heap.top();
    }
};
