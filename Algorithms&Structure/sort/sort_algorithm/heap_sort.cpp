#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template<typename T>
inline void my_swap(T& first, T& second) {
    if (first != second){
        T temp = first;
        first = second;
        second = temp;
    }
}

template<class T, typename Compare = std::less<T>>
void siftDown(vector<T> &heap, const int start, const int end, Compare comp = Compare()) {
    int i = start;
    int j = 2*i+1; // left child
    T temp = heap[i];
    while (j <= end){
        if (j < end && comp(heap[j], heap[j+1])) j++;
        if (comp(heap[j], temp)) break;
        else {
            my_swap(heap[i], heap[j]);
            i = j;
            j = 2*i + 1;
        }
    }
}

template<class T, typename Compare = std::less<T>>
void siftUp(vector<T> &heap, const int start, Compare comp = Compare()) {
    int i = start;
    int j = (i-1)/2;
    T temp = heap[i];
    while (i > 0){
        if (comp(temp, heap[j])) break;
        else {
            my_swap(heap[i], heap[j]);
            i = j;
            j = (i-1)/2;
        }
    }
}

template<class T, typename Compare = std::less<T>>
void heap_enqueue(vector<T> &heap, const T& val, Compare comp = Compare()) {
    heap.push_back(val);
    siftUp(heap, heap.size() - 1, comp);
}

template<class T, typename Compare = std::less<T>>
T heap_dequeueMax(vector<T> &heap, Compare comp = Compare()) {
    T val = heap[0];
    size_t sz = heap.size();
    my_swap(heap[0], heap[sz-1]);
    heap.pop_back();
    siftDown(heap, 0, heap.size() - 1, comp);
    return val;
}


template<class T, typename Compare = std::less<T>>
void heap_setup(vector<T> &H, Compare comp = Compare()) {
    int currentSize = H.size();
    for (int i = currentSize/2 - 1; i >= 0; i--){
        siftDown(H, i, currentSize - 1, comp);
    }
}


template<class T, typename Compare = std::less<T>>
void Heapsort(vector<T> &H, Compare comp = Compare()) {
    int currentSize = H.size();
    heap_setup(H, comp);
    for (int i = currentSize-1; i >= 0; i--){
        my_swap(H[0], H[i]);
        siftDown(H, 0, i-1, comp);
    }
}

template<class T, typename Compare = std::less<T>>
void Heapsort(vector<T> &H, Compare comp = Compare()) {
    int currentSize = H.size();
    heap_setup(H, comp);
    for (int i = currentSize-1; i >= 0; i--){
        my_swap(H[0], H[i]);
        siftDown(H, 0, i-1, comp);
    }
}

int main(){
    vector<int> vec = {5, 2, 4, 3, 1, 7, 10, 2, 3, 6, 4};
    heap_setup(vec, std::less<int>());
    vector<int> vec1 = vec;
    Heapsort(vec1, std::less<int>());
    for (unsigned int i = 0; i < vec.size(); ++i) cout << vec1[i] << " ";
    cout << '\n';
    heap_enqueue(vec, 8, std::less<int>());
    heap_enqueue(vec, -1, std::less<int>());
    vector<int> vec2 = vec;
    Heapsort(vec2, std::less<int>());
    for (unsigned int i = 0; i < vec2.size(); ++i) cout << vec2[i] << " ";
    cout << '\n';
    heap_enqueue(vec, 11, std::less<int>());
    heap_setup(vec, std::less<int>());
    vector<int> vec3 = vec;
    Heapsort(vec3, std::less<int>());
    for (unsigned int i = 0; i < vec3.size(); ++i) cout << vec3[i] << " ";
    cout << '\n';
    cout << heap_dequeueMax(vec, std::less<int>()) << "\n";
    cout << heap_dequeueMax(vec, std::less<int>()) << "\n";
    vector<int> vec4 = vec;
    Heapsort(vec4, std::less<int>());
    for (unsigned int i = 0; i < vec4.size(); ++i) cout << vec4[i] << " ";
    cout << '\n';
    cout << heap_dequeueMax(vec, std::less<int>()) << "\n";
    vector<int> vec5 = vec;
    Heapsort(vec5, std::less<int>());
    for (unsigned int i = 0; i < vec5.size(); ++i) cout << vec5[i] << " ";
    cout << '\n';
    return 0;
}