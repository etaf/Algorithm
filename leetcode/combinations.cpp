#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
   public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        if(k==0)return ans;
        for(int i=1;i+k-1<=n;++i){
            ans.push_back(vector<int>({i}));
        }
        int tmp_size;
        for(int i=1;i<k;++i){
            tmp_size = ans.size();
            for(int j=0;j<tmp_size;++j){
                vector<int> tmp  = ans[j];
                for(int c = ans[j].back()+2; c + k -1- ans[j].size()<=n; ++c){
                    tmp.push_back(c);
                    ans.push_back(tmp);
                    tmp.pop_back();
                }
                ans[j].push_back(ans[j].back()+1);
            }
        }
        return ans;
    }
    
};
int main(){
    Solution sol;
    vector<vector<int> > ans=sol.combine(1,2);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    } 

    return 0;
}
