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
class Solution { //O(n*n without a hash map
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<int>::iterator it;
        int p,q;
        int ans,d=INT_MAX,tmp;
        for(size_t i=0;i+2<num.size();++i){ // for(int i=0;i<num.size()-2;++i) or for(unsigned int i=0;i<num.size()-2;++i), when num.size() == 0 , (i<num.size()-2) == True
            p = i+1;
            q=num.size()-1;
            while(p<q){
                tmp = num[p] + num[q] + num[i] - target;
                if(tmp == 0) return target;
                else if(tmp < 0){
                    if(-tmp < d ) d = -tmp , ans = num[p]+num[q]+num[i];
                    ++p;
                }else{
                    if(tmp<d) d = tmp , ans = num[p]+num[q]+num[i];
                    --q;
                }
            }
            while(i+1<num.size()-2 && num[i] == num[i+1])++i;
        }
        return ans;
    }
};
class Solution_bsearch { //O(n*n*log(n) without a hash map
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<int>::iterator it;

        int ans,d=INT_MAX,tmp;
        for(size_t i=0;i+2<num.size();++i){ // for(int i=0;i<num.size()-2;++i) or for(unsigned int i=0;i<num.size()-2;++i), when num.size() == 0 , (i<num.size()-2) == True
            for(size_t j=i+1;j<num.size()-1;++j){
                it = lower_bound(num.begin()+j+1,num.end(),target-num[i]-num[j]);
                //cout<<num[i]<<"+"<<num[j]<<"+"<<*it<<endl;
                if(it==num.end() ) it = --it;
                tmp = abs(*it+num[i]+num[j]-target);
                if( tmp < d)
                {
                    d = tmp;
                    ans = *it+num[i]+num[j];
                }
                while(j+1<num.size()-1 && num[j] == num[j+1])++j;
            }
            while(i+1<num.size()-2 && num[i] == num[i+1])++i;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> num({-1,0,});
    int ans = sol.threeSumClosest(num,-10);
    cout<<ans<<endl;
    return 0;
}


