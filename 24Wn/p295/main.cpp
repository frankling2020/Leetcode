#include <vector>
#include <queue>
using namespace std;


class MedianFinder {
    priority_queue<int,vector<int>, less<int> > big_heap;
    priority_queue<int,vector<int>, greater<int> > small_heap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        int small_sz = small_heap.size();
        int big_sz = big_heap.size();
        if (small_sz == 0 || num < small_heap.top()) {
            big_heap.push(num);
            if (big_sz > small_sz) {
                small_heap.push(big_heap.top());
                big_heap.pop();
            }
        }
        else {
            small_heap.push(num);
            if (big_sz == small_sz) {
                big_heap.push(small_heap.top());
                small_heap.pop();
            }
        }
    }
    
    double findMedian() {
        double ans = 0.0;
        if (big_heap.size() > small_heap.size()) {
            ans = big_heap.top();
        }
        else {
            ans = (big_heap.top() + small_heap.top()) / 2.0; 
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */