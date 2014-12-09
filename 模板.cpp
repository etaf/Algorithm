#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define L(i) (i<<1)
#define R(i) (i<<1|1)
#define Mid(x,y) ((x+y)>>1)
#define eps 1e-9
#define inf 0x3fffffff
bool dy(double x,double y)  {   return x > y + eps;} // x > y   
bool xy(double x,double y)  {   return x < y - eps;} // x < y   
bool dyd(double x,double y) {   return x > y - eps;} // x >= y   
bool xyd(double x,double y) {   return x < y + eps;}     // x <= y   
bool dd(double x,double y)  {   return fabs( x - y ) < eps;}  // x == y 

