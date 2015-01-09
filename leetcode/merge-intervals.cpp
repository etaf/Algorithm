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
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const struct Interval & x,const struct Interval & y){
    return x.start < y.start;
}
class Solution_old {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        if(intervals.empty())return ans;
        sort(intervals.begin(),intervals.end(),cmp);
        int l = intervals[0].start, r = intervals[0].end;

        for(size_t i=1;i<intervals.size();++i){
            if(intervals[i].start > r){
                ans.push_back(Interval(l,r));
                l = intervals[i].start;
                r = intervals[i].end;
            }
            else{
                r = max(r,intervals[i].end);
            }
        }
        ans.push_back(Interval(l,r));
        return ans;
    }
};
class Solution { //save memory
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty())return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        int l = intervals[0].start, r = intervals[0].end;
        vector<Interval>::iterator it = intervals.begin();
        for(size_t i=1;i<intervals.size();++i){
            if(intervals[i].start > it->end){
                ++it;
                it->start = intervals[i].start;
                it->end = intervals[i].end;
            }
            else{
                it->end = max(it->end,intervals[i].end);
            }
        }
        intervals.erase(it+1,intervals.end());
        return intervals;
    }
};
int main()
{
    Solution sol;
    vector<Interval> vs({Interval(1,3),Interval(2,6),Interval(8,10),Interval(15,18)});
    vector<Interval> ans = sol.merge(vs);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i].start<<"-"<<ans[i].end<<endl;
    }
    return 0;
}


