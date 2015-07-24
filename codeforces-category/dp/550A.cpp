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
const int N = 100001;
char s[N];
int main()
{
    scanf("%s",s);
    int p1=-1,q1=-1,p2=-1,q2=-1;
    int n = strlen(s);
    for(int i=1; i<n; ++i){
        if(s[i]=='B' && s[i-1] =='A' && p1 == -1)
        {
            p1 = i;
            if(q1!=-1)break;
        }
        if(s[i]=='A' && s[i-1] =='B' && q1 == -1){
            q1 = i;
            if(p1!=-1)break;
        }
    }
    for(int i=n-2; i>=0; --i){
        if(s[i] == 'A' && s[i+1] == 'B' && p2 == -1){
            p2 = i+1;
            if(q2!=-1)break;
        }
        if(s[i] == 'B' && s[i+1] =='A' && q2 == -1){
            q2 = i+1;
            if(p2!=-1)break;
        }
    }
    //cout<<p1<<" "<<p2<<" "<<endl;
    //cout<<q1<<" "<<q2<<" "<<endl;
    if((p1!=-1 && q1!=-1) && (abs(p1-q2)>1 || abs(p2-q1)>1))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}


