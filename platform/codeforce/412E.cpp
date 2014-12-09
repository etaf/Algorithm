#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1000010;
typedef  long long  llong;

char s[N];
int n;
bool isletter(char c)
{
    return ( ('a'<=c && c<='z')||
             ('A'<=c && c<='Z')
           );
}
bool isnum(char c)
{
    return ( '0'<=c && c<='9');
}

llong get_ans(int p)
{
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=p-1;i>=0;--i)
    {
        if(!isletter(s[i]) && !isnum(s[i]) && s[i]!='_')
            break;
        if(isletter(s[i]))
            ++cnt1;
    }
    int q = 0;
    for(int i=p+1;i<n;++i)
    {
        if(s[i] == '.' )
        {
            q = i;
            break;
        }
        if(!isletter(s[i]) && !isnum(s[i]))
        {
            break;
        }
    }
    if(q <= p+1)
    {
        return 0;
    }
    for(int i=q+1;i<n;++i)
    {
        if( isletter( s[i] ) )
            ++cnt2;
        else break;
    }
    llong c1 = cnt1;
    llong c2 = cnt2;
    return c1*c2;
}
int main()
{
    scanf("%s",s);
    n = strlen(s);
    llong ans = 0;
    for(int i=0;i<n;++i)
    {
        if(s[i] == '@')
        {
            ans+= get_ans(i);
        }
    }
    cout<<ans<<endl;
   return 0;
}
