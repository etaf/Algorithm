#ifndef INSERT_SORT_HH
#define INSERT_SORT_HH

void insert_sort(int* a, int l, int r){
    int key,i,j;
    for(i = l; i < r; ++i){
        key = a[i];
        for(j = i-1; j >= 0 && key < a[j]; --j){
            a[j+1] = a[j];
        }
        a[j+1] = key;
    }
}
#endif
