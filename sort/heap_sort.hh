#ifndef HEAP_SORT_HH
#define HEAP_SORT_HH
#include<algorithm>
void maxheapify_iter(int* a, int l, int r, int p)
{
    int lc,rc, maxp = p;
    while(maxp < r){
        p = maxp;
        lc = (maxp << 1) + 1;
        rc = (maxp << 1) + 2;
        if(lc < r && a[maxp] < a[lc])
            maxp = lc;
        if(rc < r && a[maxp] < a[rc])
            maxp = rc;
        if(maxp == p){
            break;
        }
        else{
            std::swap(a[p], a[maxp]);
        }
    }
}
void heap_sort(int* a, int l, int r){
    if(r-l<2) return;
    //build
    for(int i=(r-2)/2; i>=0; --i){
        maxheapify_iter(a, l, r, i);
    }
    //sort
    for(int i=1; i<r; ++i){
        std::swap(a[0], a[r-i]);
        maxheapify_iter(a, l, r-i, 0);
    }
}

void stl_heap_sort(int*a, int l, int r){
    std::make_heap(a+l, a+r);
    std::sort_heap(a+l, a+r);
}
#endif
