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
using namespace std;
class Solution_nlogn {
public:
    int maximumGap(vector<int> &num) { //nlog(n)
        sort(num.begin(),num.end());
        int ans = 0;
        for(int i=num.size()-1;i>0;--i)
            ans = max(ans,num[i]-num[i-1]);
        return ans;
    }
};
class Solution {
public:
    int maximumGap(vector<int> &num) { //O(n)
        int maxn = INT_MIN, minn  = INT_MAX;
        int n = num.size();
        if(n<=1)return 0;
        for(int i=0;i<n;++i)
        {
            maxn = max(maxn,num[i]);
            minn = min(minn,num[i]);
        }
        int len = (maxn-minn)/(n-1);
        if(len == 0){
            return maxn-minn;
        }
        int ns = (maxn-minn)/len + 1;
        vector< pair<int,int> > buckets(ns);
        for(int i=0;i<ns;++i)buckets[i].first = -1 , buckets[i].second = -1;
        int b;
        for(int i=0;i<n;++i)
        {
           b = (num[i]-minn)/len;
           if(buckets[b].first == -1)buckets[b].first = num[i];
           else buckets[b].first = min(buckets[b].first,num[i]);
           if (buckets[b].second == -1)buckets[b].second = num[i];
           else buckets[b].second = max(buckets[b].second,num[i]);
        }

        int ans = 0;
        for(int i=0,j;i<ns-1;i=j)
        {
            while(i<ns-1 && buckets[i].second == -1)++i;
            j = i+1;
            while(j<ns && buckets[j].first == -1) ++j;
            if(j>=ns)break;
           ans = max(ans,buckets[j].first - buckets[i].second);
        }
        return ans;
    }
};

void test(){
    //vector<int> num({3,4,1,5,7,8,10,1,2});
    vector<int> num({3,6,9,1});
    Solution sol;
    cout<<sol.maximumGap(num)<<endl;
}
int main()
{
    test();
	return 0;
}


