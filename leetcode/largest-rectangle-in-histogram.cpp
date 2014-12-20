#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      int largestRectangleArea(vector<int> &height) {
          int n = height.size();
          if(n == 0)return 0;
          int ans = 0;
          vector<int> S;
          S.push(0);
          int l,r;
          for(int i=1;i<n;++i){
              if(height[i]>height[S.size()-1]) S.push_back(i);
              else{
                 r = S.top()+1;
                 while(!S.empty() && height[S.top()] >= height[i]){
                     l = S.top();
                      S.pop();
                 }
                 if(S.empty())
                    ans = max(ans,height[l]*(r));
                 else ans = max(ans,height[l]*(r-l));
                 cout<<ans<<endl;
                 S.push(i);
              }
          }
          if(S.empty()) return ans;
          l = S.top();
          r = S.top()+1;

          while(!S.empty()){
              if(height[S.top()])
                l = S.top();
              else break;
              //cout<<"--"<<height[l]<<endl;
              S.pop();
          }
          if(!S.empty()) ans = max(ans,height[l]*(r-l));
          else ans = max(ans,height[l]*(r));
          return ans;
      }
  };
int main(){

    Solution sol;
    //vector<int> hs({2,1,5,6,2,3} );
    vector<int> hs({1,2,2} );
    cout<<sol.largestRectangleArea(hs)<<endl;
    return 0;
}
