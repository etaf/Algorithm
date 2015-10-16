#ifndef HEAP_SORT_HH
#define HEAP_SORT_HH
#include<algorithm>
#define M(x) (x+l)
void maxheapify_recursive(int* a, int l, int r, int i)
{
    int lc,rc, maxp = i;
    lc = i*2+1;
    rc = i*2+2;
    if(M(lc) < r && a[M(maxp)] < a[M(lc)])
        maxp = lc;
    if(M(rc) < r && a[M(maxp)] < a[M(rc)])
        maxp = rc;
    if(maxp != i){
        std::swap(a[M(i)], a[M(maxp)]);
        maxheapify_recursive(a, l, r, maxp);
    }

}

void maxheapify_iter(int* a, int l, int r, int p)
{
    int lc,rc, maxp = p;
    while(maxp < r){
        p = maxp;
        lc = (maxp << 1) + 1;
        rc = (maxp << 1) + 2;
        if(M(lc) < r && a[M(maxp)] < a[M(lc)])
            maxp = lc;
        if(M(rc) < r && a[M(maxp)] < a[M(rc)])
            maxp = rc;
        if(maxp == p){
            break;
        }
        else{
            std::swap(a[M(p)], a[M(maxp)]);
        }
    }
}
void heap_sort(int* a, int l, int r){
    if(r-l<2) return;
    //build
    for(int i=(r-l-2)/2; i>=0; --i){
        maxheapify_iter(a, l, r, i);
    }
    //sort
    for(int i=1; i+l<r; ++i){
        std::swap(a[l], a[r-i]);
        maxheapify_iter(a, l, r-i, 0);
    }
}

void stl_heap_sort(int*a, int l, int r){
    std::make_heap(a+l, a+r);
    std::sort_heap(a+l, a+r);
}
#endif
