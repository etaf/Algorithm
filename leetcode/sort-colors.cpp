#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int f[3] = {0,0,0};
        for(int i=0;i<n;++i)  ++f[A[i]];
        int cnt = 0;
        for(int i=0;i<3;++i){
            while(f[i]){
                A[cnt++] = i;
                --f[i];
            }
        }
    }
};

int main(){
    int A[] = {2,1,0,1,2,0,0,1,1,0,2};
    int n = sizeof(A)/sizeof(int);
    Solution sol;
    sol.sortColors(A,n);
    for(int i=0;i<n;++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
