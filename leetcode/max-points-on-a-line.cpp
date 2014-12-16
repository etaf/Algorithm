#include<iostream>
#include<cstdlib>
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
#include<cmath>
using namespace std;
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };
class Solution {

public:
class PairHash {
public:
        size_t operator()(std::pair<int, int> x) const {
              return (x.first+x.second)*(x.first+x.second+1)/2 + x.second;
        }
};

    int maxPoints(vector<Point> &points) {
        int a,b;
        int ans = 0;
        for(int i=0;i<points.size();++i){
            unordered_map<pair<int,int>,int,PairHash> M;
            int local_ans = 0;
            int h=0,v=0,g;
            for(int j=i+1;j<points.size();++j){
                a = points[i].x-points[j].x;
                b = points[i].y-points[j].y;
                if(a==0 && b==0)++h;
                else{
                    g= __gcd(a,b);
                    a/=g;
                    b/=g;
                    M[pair<int,int>(a,b)]++;
                    local_ans = max(local_ans,M[pair<int,int>(a,b)]);
                }
            }
            ans = max(ans,local_ans+1+h);
        }
        return ans;
    }
};
void test(){
    Solution sol;
    vector<Point> ps({Point(0,0),Point(1,0),Point(0,0),Point(100,0)});
    cout<<sol.maxPoints(ps)<<endl;
}
int main()
{
    test();
	return 0;
}


