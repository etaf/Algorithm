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

bool check(char* s, int n, int x){
    int v;
    int i = n-1, cnt=0;
    char ans[4];
    do{
        v = x%10;
        x/=10;
        while(i>=0 && s[i]!=v+'0') --i;
        if(i<0) {
            return false;
        }
        ans[cnt++] = s[i];
        --i;
    }while(x);
    printf("YES\n");
    for(int j=cnt-1;j>=0;--j){
        printf("%c",ans[j]);
    }
    printf("\n");
    return true;
}
void solve(){
    char s[128];
    scanf("%s", s);
    int n = strlen(s);
    for(int i=0; i*8<1000; ++i){
        if(check(s,n,i*8)){
            return;
        }
    }
    printf("NO\n");
}
int main()
{
    solve();
    return 0;
}


