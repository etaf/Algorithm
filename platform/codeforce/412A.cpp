#include<iostream>
#include<cstdio>
#include<cstring>
int main()
{
    int n,k;
    char s[128];
    scanf("%d%d",&n,&k);
    scanf("%s",s);

    if(k-1<=n-k)
    {
        for(int i=0;i<k-1;++i)
        {
            printf("LEFT\n");
        }
        printf("PRINT %c\n",s[0]);
        for(int i=1;i<n;++i)
        {
            printf("RIGHT\n");
            printf("PRINT %c\n",s[i]);
        }

    }
    else
    {
        for(int i=0;i<n-k;++i)
        {
            printf("RIGHT\n");
        }
        printf("PRINT %c\n",s[n-1]);
        for(int i=n-2;i>=0;--i)
        {
            printf("LEFT\n");
            printf("PRINT %c\n",s[i]);
        }
    }
    return 0;
}
