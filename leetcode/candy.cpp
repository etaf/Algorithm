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
class Solution{
public:
    int candy(vector<int> &ratings) { //O(1)space O(n) time
        int sum = 0;
        int l,r,fl;
        for(size_t i=0;i<ratings.size();++i){
            l=0;
            r=0;
            if(i>0 && ratings[i]>ratings[i-1])fl = 2;
            else fl = 1;
            while( i+1 < ratings.size() && ratings[i] < ratings[i+1] ){
                ++i;
                ++l;
            }
            while(i+1<ratings.size() && ratings[i] > ratings[i+1]){
                ++i;
                ++r;
            }
            sum+=max(fl+l-1,r)+1 + l*(fl+fl+l-1)/2 + r*(r+1)/2;
        }
        return sum;
    }
};
class Solution_On_space {
public:
    int candy(vector<int> &ratings) {
        vector<int> rank(ratings.size(),0);
        for(size_t i=0;i<ratings.size();++i){
           rank[i] = 1;
           while(i+1<ratings.size() && ratings[i] < ratings[i+1]){
                ++i;
                rank[i] = rank[i-1]+1;
           }
        }
        int cnt = 1;
        int sum = 0;
        for(int i=ratings.size()-1;i>=0;--i){
            rank[i] = max(rank[i],1);
            sum+=rank[i];
            cnt = 1;
            while(i-1>=0 && ratings[i]<ratings[i-1]){
                --i;
                rank[i] = max(rank[i],++cnt);
                sum+=rank[i];
            }
        }
        return sum;
    }
};
void test(){
    vector<int> r({1,2,4,4,3,2,1});
    //vector<int> r({1,0,2});
    //vector<int> r({4,2,3,4,1});
    Solution sol;
    cout<<sol.candy(r)<<endl;
}
int main()
{
    test();
	return 0;
}


