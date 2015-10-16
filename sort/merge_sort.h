#ifndef MERGE_SORT_HH
#define MERGE_SORT_HH

#include "insert_sort.h"
void _merge(int* a, int* buff, int l, int mid, int r){
    int lena = 0;
    for(int i=l; i<mid; ++i){
        buff[lena++] = a[i];
    }
    int p=0, q = mid, cnt = l;
    while(p < lena && q < r){
        if(buff[p]<=a[q]) a[cnt++] = buff[p++];
        else a[cnt++] = a[q++];
    }
    while(p < lena){
        a[cnt++] = buff[p++];
    }
}
void _merge_sort_recursive(int* a, int* buff, int l, int r){
    if(r-l < 2) return;
    int mid = (l+r) >> 1;
    _merge_sort_recursive(a, buff, l, mid);
    _merge_sort_recursive(a, buff, mid, r);
    _merge(a, buff, l, mid, r);
}
void _merge_sort_recursive_with_insert(int* a, int* buff, int l, int r){
    if(r-l < 33){
        insert_sort(a,l,r);
        return;
    }
    int mid = (l+r) >> 1;
    _merge_sort_recursive(a, buff, l, mid);
    _merge_sort_recursive(a, buff, mid, r);
    _merge(a, buff, l, mid, r);

}
void merge_sort_recursive(int* a, int l, int r){
    if(l>=r) return;
    int *buff = new int [r-l];
    _merge_sort_recursive(a, buff, l, r);
    delete [] buff;
}

void merge_sort_recursive_with_insert(int* a, int l, int r){
    if(l>=r) return;
    int *buff = new int [r-l];
    _merge_sort_recursive_with_insert(a, buff, l, r);
    delete [] buff;
}


void merge_sort_iterate(int* a, int l, int r)
{
    if(l>=r) return;
    int *buff = new int [r-l];
    for(int m=1; m < r-l; m <<= 1){
        for(int ll=0; ll + m < r; ll += m + m )
        {
            if(ll+m < r)
                _merge(a, buff, ll, ll+m, (ll+m+m < r ? ll+m+m : r));
        }
    }
    delete [] buff;
}

#endif
