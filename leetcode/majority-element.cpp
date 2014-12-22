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
class Solution { //O(n)time O(1)space ,use the thought of stack
public:
    int majorityElement(vector<int> &num) {
        int s_cnt = 0,s_top;
        for(int i=0;i<num.size();++i){
            if(s_cnt == 0){
                ++s_cnt;
                s_top = num[i];
            }
            else{
                s_cnt += (s_top == num[i] ? 1 : -1);
            }
        }
        return s_top;

    }
};
int main()
{
    Solution sol;
    vector<int> num({6,6,6,7,7});
    cout<<sol.majorityElement(num)<<endl;
	return 0;
}


