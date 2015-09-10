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
class Solution_On_space {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int dpr[ratings.size()];
        dpr[ratings.size()-1] = 0;
        for(int i =ratings.size()-2; i>=0; --i){
            if(ratings[i] > ratings[i+1]) dpr[i] = dpr[i+1] + 1;
            else dpr[i] = 0;
        }
/*        for(int i=0; i<ratings.size(); ++i){*/
            //cout<<dpr[i]<< " ";
        //}
        /*cout<<endl;*/
        int dpl = 0;
        int ans = dpr[0]+1;
        //cout<<dpl<<" ";
        for(int i=1; i<ratings.size(); ++i)
        {
            if(ratings[i] > ratings[i-1]) ++dpl;
            else dpl=0;
            ans += 1 + max(dpr[i], dpl);
            //cout<<dpl<<" ";
        }
        //cout<<endl;
        return ans;
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        int dpl = 0;
        for(int i=0,j; i<ratings.size(); ++i){
            if(i>0 && ratings[i-1] < ratings[i]) ++dpl;
            else dpl = 0;
            for(j=i; j+1<ratings.size() && ratings[j] > ratings[j+1]; ++j);
            ans += 1 + max(dpl,j-i) + (((1+j-i)*(j-i)) >> 1);
            if(j>i)dpl=0;
            i = j;
        }
        return ans;
    }
};
void test(){
    vector<int> r({1,2,4,4,3,2,1});
    //vector<int> r({1,0,2});
    //vector<int> r({4,2,3,4,1});
    Solution sol;
    cout<<sol.candy(r)<<endl;
}

void test1(){
    vector<int> r({1,2,2,2});
    //vector<int> r({1,0,2});
    //vector<int> r({4,2,3,4,1});
    Solution sol;
    cout<<sol.candy(r)<<endl;
}
void test2(){
    vector<int> r({58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89});
    //vector<int> r({4,2,3,4,1});
    Solution sol;
    cout<<sol.candy(r)<<endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    test();
    test1();
    test2();
    return 0;
}


