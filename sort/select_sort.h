#ifndef SELECT_SORT_HH
#define SELECT_SORT_HH

void select_sort(int* a, int l, int r){
    int minn, minp;
    for(int i=l; i< r; ++i){
        minn = a[i];
        minp = i;
        for(int j=i+1; j<r; ++j){
            if(minn > a[j]){
                minn = a[j];
                minp = j;
            }
        }
        std::swap(a[i], a[minp]);
    }
}
#endif
