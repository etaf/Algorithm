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
    int a = 1;
    int b = 2;
    swap(a,b);
    cout<<"a="<<a<<"\t"<<"b="<<b<<endl;
    int *p = &a;
    int *q = &b;
    int c[2] ={1,2};
    cout<<c[0]<<" "<<c[1]<<endl;
    swap(c[0],c[1]);
    cout<<c[0]<<" "<<c[1]<<endl;
    cout<<"p="<<p<<"\t"<<"q="<<q<<endl;
    swap(*p,*q);
    cout<<"p="<<p<<"\t"<<"q="<<q<<endl;
    cout<<"a="<<a<<"\t"<<"b="<<b<<endl;
    /*iter_swap(p,q);*/
    //cout<<"a="<<a<<"\t"<<"b="<<b<<endl;
    ////test(a);
    //test(p);
    //cout<<"a="<<a<<endl;
    /*cout<<p<<endl;*/
    return 0;
}


