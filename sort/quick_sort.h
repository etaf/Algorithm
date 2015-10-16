#ifndef QUICK_SORT_HH
#define QUICK_SORT_HH
#include<iostream>
#include<stack>
#include "insert_sort.h"
int partition(int* a, int l, int r){
    int pivot = a[(l+r)>>1];
    while(l<r){
        while(l<r && a[l] < pivot) ++l;
        while(l<r && a[r] > pivot) --r;
        if(l<r){
            std::swap(a[l],a[r]);
        }
    }
    return l;
}

void quick_sort(int* a, int l, int r){
    std::stack<std::pair<int,int> > st;
    st.push(std::make_pair(l,r-1));
    while(!st.empty()){
        std::pair<int,int> now = st.top();
        st.pop();
        if(now.second - now.first < 33) {
            insert_sort(a,now.first,now.second+1);
        }else{
            int p = partition(a,now.first,now.second);
            if(p-now.first>1) st.push(std::make_pair(now.first,p));
            if( now.second-p>1) st.push(std::make_pair(p,now.second));
        }
    }
}
#endif
