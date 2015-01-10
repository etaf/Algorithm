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

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }
        int l=0,r=intervals.size(),mid;
        while(l+1<r){
            mid = (l+r)>>1;
            if(intervals[mid].start > newInterval.start) r = mid;
            else l = mid;
        }
        if(intervals[l].start > newInterval.end || (intervals[l].end<newInterval.start && (l+1 ==intervals.size() || intervals[l+1].start > newInterval.end) ) ){
            intervals.push_back(newInterval);
            int k = intervals[l].start > newInterval.end ? 0 : l+1;
            for(int j=intervals.size()-1;j>k;--j){
                intervals[j].start = intervals[j-1].start;
                intervals[j].end = intervals[j-1].end;
            }
            intervals[k].start = newInterval.start;
            intervals[k].end = newInterval.end;
            return intervals;
        }
        vector<Interval>::iterator it;
        if(newInterval.start <= intervals[l].end){
            it = intervals.begin()+l;
            it->start = min(newInterval.start,it->start);
            it->end = max(newInterval.end,it->end);
        }else{
            ++l;
            it = intervals.begin()+l;
            it->start = newInterval.start;
            it->end = max(newInterval.end,it->end);
        }
        for(int i=l+1;i<intervals.size();++i){
            if(intervals[i].start <= it->end){
                it->end = max(it->end,intervals[i].end);
            }
            else{
                ++it;
                it->start = intervals[i].start;
                it->end = intervals[i].end;
            }
        }
        intervals.erase(it+1,intervals.end());
        return intervals;
    }
};
int main()
{
    Solution sol;
    vector<Interval> vs({Interval(1,2),Interval(3,5),Interval(6,7),Interval(8,10),Interval(12,16)});
    vector<Interval> ans = sol.insert(vs,Interval(18,20));
    for(int i=0;i<ans.size();++i){
        cout<<ans[i].start<<"-"<<ans[i].end<<endl;
    }
    return 0;
}


