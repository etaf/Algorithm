#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
  public:
      int largestRectangleArea(vector<int> &height) {
          int n = height.size();
          if(n == 0)return 0;
          int ans = 0;
          stack<int> S;
          S.push(0);
          int l,r;
          for(int i=1;i<n;++i){
              if(height[i]>=height[S.top()]) S.push(i);
              else{
                 r = S.top();
                 while(!S.empty() && height[S.top()] >= height[i]){
                     l = S.top();
                     S.pop();
                     if(!S.empty())
                         ans = max(ans,height[l]*(r-S.top()));
                     else
                         ans = max(ans,height[l]*(r+1));
                 }
                 S.push(i);
              }
          }
          if(S.empty()) return ans;
          r = S.top();
          while(!S.empty()){
                l = S.top();
                S.pop();
                //cout<<height[l]<<endl;
                if(!S.empty())
                ans = max(ans,height[l]*(r-S.top()));
                else
                    ans = max(ans,height[l]*(r+1));
          }
          return ans;
      }
  };
int main(){

    Solution sol;
    //vector<int> hs({2,1,5,6,2,3} );
    //vector<int> hs({1,2,1} );
    //vector<int> hs({0,9} );
    vector<int> hs({4,2,0,3,2,5} );
    cout<<sol.largestRectangleArea(hs)<<endl;
    return 0;
}
