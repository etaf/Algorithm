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
using namespace std;
/*problem:
 * https://codility.com/programmers/challenges/aluminium2014
*/

int single_run(vector<int> &A) {
    // write your code in C++11
    int n = A.size();
    int f[n],g[n];
    f[0] = A[0];
    g[n-1] = A[n-1];
    int ans = g[n-1];
    int maxn = A[0];
    for(int i=1; i<n; ++i){
        maxn = max(A[i],maxn);
        f[i] = max(f[i-1]+A[i], maxn);
    }
    for(int i=n-2; i>=0; --i){
        g[i] = A[i] + (g[i+1] > 0 ? g[i+1] : 0);
        ans = max(ans,g[i]);
    }
    for(int i=1; i<n; ++i){
        ans = max(ans, f[i-1]+g[i]-A[i]);
    }
    return ans;
}
int solution(vector<int> &A) {
    int ans = single_run(A);
    reverse(A.begin(),A.end());
    return max(ans, single_run(A));
}
int help(vector<int> &a) {
    int n = a.size();
    vector<int> f,g;
    f.resize(n);
    f[0] = a[0];
    int now = a[0];
    for (int i = 1; i < n; ++i) {
        now = max(now, a[i]);
        f[i] = max(a[i] + f[i - 1], now);
    }
    g.resize(n);
    g[n - 1] = a[n - 1];
    int answer = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        g[i] = max(g[i + 1], 0) + a[i];
        answer = max(answer, g[i]);
    }
    for (int i = 1; i < n; ++i) {
        answer = max(answer, g[i] - a[i] + f[i - 1]);
    }
    return answer;
}

int solution_other(vector<int> &A) {
    // write your code in C++11
    int answer = help(A);
    reverse(A.begin(),A.end());
    answer = max(answer,help(A));
    return answer;
    
}
int main()
{
    vector<int> A = { 1, -1,3, 2,-6, 3, 1};
    //vector<int> A = {-1,1,4,9,2,1,-2,3,4};
    cout<<solution(A)<<endl;
    cout<<solution_other(A)<<endl;
    return 0;
}


