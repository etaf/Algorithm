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

int main()
{
    int n;
    scanf("%d",&n);
    int ns[16];
    int len = 0;
    while(n){
        ns[len++] = n%10;
        n/=10;
    }
    int minn,ans=0, tmp;
    vector<pair<int,int> > ansn;
    while(1){
        //find minn in vector
        minn = 10;
        for(int i=0; i<len; ++i){
            if(ns[i])
            minn = min(minn,ns[i]);
        }
        if(minn == 10)break;
        ans+=minn;
        tmp = 0;
        for(int i=len-1; i>=0; --i){
            if(ns[i]){
               tmp=tmp*10+1;
               ns[i] -= minn;
            }else{
                tmp = tmp*10;
            }
        }
        ansn.push_back(pair<int,int>(minn,tmp));
    }
    printf("%d\n", ans);
    for(int i=0;i<ansn.size(); ++i){
        for(int j=0; j<ansn[i].first; ++j){
            printf("%d ",ansn[i].second);
        }
    }
    printf("\n");
    return 0;
}


