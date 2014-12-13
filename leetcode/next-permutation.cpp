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
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int p;
        for( p = num.size()-1;p>0 && num[p-1] >= num[p];--p);
        if(p==0){
            reverse(num,0,num.size()-1);
            return;
        }
        reverse(num,p,num.size()-1);
        int  q = p-1;
        //find the first one in [p,num.size()-1] that larger than num[q]
        vector<int>::iterator it = upper_bound(num.begin()+p,num.end(),num[q]);
        swap(*it,num[q]);
    }
    void reverse(vector<int>& num, int l,int r){
        while(l<r){swap(num[l++],num[r--]);}
    }
};
void test()
{
    vector<int> num({2,3,6,4,4,1});
    Solution sol;
    sol.nextPermutation(num);
    for(int i=0;i<num.size();++i)
        cout<<num[i]<<" ";
    cout<<endl;
}
int main()
{
    test();
	return 0;
}


