#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <iostream>

template<typename T>
using vecT_itr = typename std::vector<T>::iterator;

template<typename T>
inline void mySwap(T& first, T& second) {
    T temp = first;
    first = second;
    second = temp;
}

template<typename T, typename Compare>
vecT_itr<T> partition_inplace(const vecT_itr<T>& left, const vecT_itr<T>& right, Compare comp = Compare()){
    vecT_itr<T> mid = left+(right-left)/2;
    if (comp(*right, *left)) mySwap(*left, *right);
    if (comp(*right, *mid)) mySwap(*mid, *right);
    if (comp(*left, *mid)) mySwap(*left, *mid);
    vecT_itr<T> begin = left + 1, end = right;
    while (true) {
        while (begin < end && comp(*begin, *left)) ++begin;
        while (begin <= end && comp(*left, *end)) --end;
        if (begin < end) {mySwap(*begin, *end); ++begin; --end;}
        else break;
    }
    mySwap(*left, *end);
    return end;
}

template<typename T, typename Compare>
void quick_sort_inplace_helper(const vecT_itr<T> &left, const vecT_itr<T> &right, Compare comp = Compare()){
    if (left >= right) return;
    vecT_itr<T> pivot, l, r;
    std::vector<vecT_itr<T>> record = {right, left};
    while (!record.empty()) {
        l = record.back();
        record.pop_back();
        if (!record.empty()){
            r = record.back();
            pivot = partition_inplace<T>(l, r, comp);
            if (r > pivot + 1) record.push_back(pivot + 1);
            else record.pop_back();
            if (l < pivot - 1) {
                record.push_back(pivot - 1);
                record.push_back(l);
            }
        }
        else break;
    }
}

template<typename T, typename Compare>
void quick_sort_inplace(std::vector<T> &vector, Compare comp = std::less<T>()) {
    quick_sort_inplace_helper<T>(vector.begin(), vector.end()-1, comp);
}


int main(){
    std::vector<int> vec = {5, 2, 4, 3, 5, 6, 7, 11, 10, 12, 2, 1, 2};
    std::vector<int> vec1 = vec;
    quick_sort_inplace(vec1, std::less<int>());
    for (unsigned int i = 0; i < vec1.size(); ++i) std::cout << vec1[i] << " ";
    std::cout << "\n";
    sort(vec.begin(), vec.end());
    for (unsigned int i = 0; i < vec.size(); ++i) std::cout << vec[i] << " ";
    std::cout << "\n";
    return 0;
}