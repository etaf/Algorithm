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
using namespace std;
class Solution { //O(n)time but O(1)space
public:
    void merge(int A[], int m, int B[], int n) {
        int cnt = n+m-1;
        int p = m-1 , q=n-1;
        while(p>=0 && q>=0)
        {
            if(A[p]>B[q])A[cnt--] = A[p--];
            else A[cnt--] = B[q--];
        }
        while(q>=0) A[cnt--] = B[q--];
    }
};
class Solution_bad { //O(n)time but O(n+m)space
public:
    void merge(int A[], int m, int B[], int n) {
         int *C = new int[n+m];
         int p=0,q=0,cnt = 0;
         while(p<m && q<n){
            if(A[p]<B[q]) C[cnt++] = A[p++];
            else C[cnt++] = B[q++];
         }
        while(p<m)C[cnt++] = A[p++];
        while(q<n)C[cnt++] = B[q++];
        for(int i=0;i<cnt;++i)
            A[i] = C[i];
    }
};
void test(){
    int A[11]  = {1,3,5,10};
    int B[]  = {-1,2,4,9,100,200,300};
    Solution sol;
    sol.merge(A,4,B,7);
    for(int i=0;i<11;++i)cout<<A[i]<<" ";

}
int main()
{
    test();
	return 0;
}


