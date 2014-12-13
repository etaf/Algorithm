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
class Solution_recursive {

public:

    vector<vector<int> > permuteUnique(vector<int> &num) { //recursive
        if(num.size()==1) return vector<vector<int> >({{num[0]}});

        vector< vector<int> > ans,ans1;
        sort(num.begin(),num.end());
        vector<int> tmp;

        for(int k=0;k<num.size();++k){
            tmp.clear();
            for(int kk=0;kk<num.size();++kk) if(kk!=k) tmp.push_back(num[kk]);
            ans1 = permuteUnique(tmp);
            for(int i=0;i<ans1.size();++i){
                tmp.clear();
                tmp.push_back(num[k]);
                for(int j=0;j<ans1[i].size();++j)
                {
                    tmp.push_back(ans1[i][j]);
                }
                ans.push_back(tmp);
            }
            while(k+1<num.size() && num[k+1] == num[k])++k;
        }
        return ans;
    }

};

class Solution { //non recursive

public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ans;
        sort(num.begin(),num.end());
        ans.push_back(num);
        while(nextPermutation(num))ans.push_back(num);
        return ans;
    }
    bool nextPermutation(vector<int> &num) {
        int p;
        for( p = num.size()-1;p>0 && num[p-1] >= num[p];--p);
        if(p==0){
            return false;
        }
        reverse(num,p,num.size()-1);
        int  q = p-1;
        //find the first one in [p,num.size()-1] that larger than num[q]
        vector<int>::iterator it = upper_bound(num.begin()+p,num.end(),num[q]);
        swap(*it,num[q]);
        return true;
    }
    void reverse(vector<int>& num, int l,int r){
        while(l<r){swap(num[l++],num[r--]);}
    }

};
void test(){
    vector<int> num({1,1,3});
    Solution sol;
    vector< vector<int> > ans = sol.permuteUnique(num);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    test();
	return 0;
}


