#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstdlib>
#include<random>
#include<chrono>
#include<time.h>
#include "insert_sort.h"
#include "merge_sort.h"
#include "select_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"
//  Windows
#ifdef _WIN32

#include <intrin.h>
uint64_t rdtsc(){
    return __rdtsc();
}

//  Linux/GCC
#else

uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

#endif
using namespace std;
// randomly generate integer

void generate_random_integers(int* data, int n){
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    uniform_int_distribution<int> distribution(-(1<<30), (1<<30));
    for(int i=0; i<n; ++i)
        data[i] = distribution(generator);
}


void unit_test(void (*sorter)(int*, int, int), string sort_name, int* data, int n, int* sorted_data){ int* data4sort = new int[n];
    std::copy(data,data+n, data4sort);
    //clock_t tStart = clock();
    auto start_time = std::chrono::high_resolution_clock::now();
    uint64_t start_cycle = rdtsc();
    (*sorter)(data4sort, 0, n);
    auto elapsed = std::chrono::high_resolution_clock::now() - start_time;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    long long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
    printf("================\n");
    printf("Algorithm: %-25s\tScalar: %-12d\tTime Elapsed: %-12lldms\tCpu cycle: %-12llu\n", sort_name.c_str(), n, milliseconds, rdtsc() - start_cycle);
    for(int i=0; i<n; ++i){
        if(data4sort[i] != sorted_data[i]){
            printf("Uncorrected sorted result!!\n");
            break;
        }
    }
/*    for(int i=0; i<10; ++i){*/
        //printf("%d ", data4sort[i]);
    //}
    //printf("\n");
    //for(int i=0; i<10; ++i){
        //printf("%d ", sorted_data[i]);
    //}
    /*printf("\n");*/
    delete [] data4sort;
}

void test(){
    vector<int> data_scalars({1000000, 10000000});
    for(unsigned long i=0; i < data_scalars.size(); ++i){
        int n = data_scalars[i];
        int* data = new int[n];
        int* sorted_data = new int[n];
        generate_random_integers(data, n);
        std::copy(data,data+n, sorted_data);
        sort(sorted_data,sorted_data + n);
        unit_test(merge_sort_recursive, "merge sort recursive", data, n, sorted_data);
        unit_test(merge_sort_recursive_with_insert, "merge sort insert", data, n, sorted_data);
        unit_test(merge_sort_iterate, "merge sort iterate", data, n, sorted_data);
        unit_test(heap_sort, "my heap sort", data, n, sorted_data);
        unit_test(stl_heap_sort, "stl heap sort", data, n, sorted_data);
        unit_test(quick_sort, "my quick sort", data, n, sorted_data);
        //unit_test(select_sort, "select_sort", data, n, sorted_data);
        //unit_test(insert_sort, "insert_sort", data, n, sorted_data);
        delete [] data;
        delete [] sorted_data;
    }
}
int main()
{
    test();
    return 0;
}


