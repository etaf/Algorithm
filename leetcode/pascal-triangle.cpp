#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans(numRows);
        if(numRows == 0) return ans;
        ans[0].push_back(1);
        for(int i=1;i<numRows;++i){
            for(int j=0;j<=i;++j){
                if(j-1 >=0 && j<i)
                    ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
                else {
                    ans[i].push_back(1);
                }
            }
        }

        return ans;
    }
};
Solution solution;
void test(){
    vector< vector<int> > ans =  solution.generate(2);
    for(int i=0;i<ans.size();++i)
    {
        for(int j=0;j<ans[i].size();++j) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    test();
    return 0;
}
