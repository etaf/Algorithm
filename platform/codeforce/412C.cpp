#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 100001;

char s1[N];
char s2[N];
bool f[N];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s1);
    for(int i=1;i<n;++i)
    {
        scanf("%s",s2);
        for(int j=0;s2[j];++j)
        {
            if(f[j])continue;

            if(s1[j] == '?')
            {
                if(s2[j] != s1[j])
                    s1[j] = s2[j];
            }
            else
            {
                if(s1[j] != s2[j] && s2[j]!= '?')
                {
                    s1[j] = '?';
                    f[j] = 1;
                }
            }
        }
    }
    for(int i=0;s1[i];++i)
        if(s1[i] == '?' && !f[i])s1[i] = 'x';
    printf("%s\n",s1);
    return 0;
}
