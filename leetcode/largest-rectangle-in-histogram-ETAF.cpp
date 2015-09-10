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
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.empty()) return 0;
        stack<int> st;
        int l,r, ans=0, h;
        st.push(-1);
        for(int i=0; i<height.size(); ++i){
            if(height[i] >= height[st.top()]) st.push(i);
            else{
                l = r = h = st.top();
                while(st.top()>-1 &&  height[i] < height[st.top()]){
                    st.pop();
                    l = st.top();
                    ans = max(ans, (r-l)*height[h]);
                    h = l;
                }
                st.push(i);
            }
        }
        if(st.top() == -1) return ans;
        h = l = r = st.top();
        while(st.top() > -1)
        {
            st.pop();
            l = st.top();
            ans = max(ans, (r-l) * height[h]);
            h = l;
        }
        return ans;
    }
};
class Solution_dp {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.empty()) return 0;
        int l[height.size()], r[height.size()];
        l[0] = -1;
        int t;
        for(int i=1; i<height.size(); ++i){
            t = i-1;
            while(t>-1 && height[t]>=height[i]){
                t = l[t];
            }
            l[i] = t;
        }
        r[height.size()-1] = height.size();
        for(int i=height.size()-2; i>=0; --i){
            t = i+1;
            while(t<height.size() && height[t] >= height[i])
            {
                t = r[t];
            }
            r[i] = t;
        }
        int ans = 0;
        for(int i=0; i<height.size(); ++i){
            ans = max(ans, height[i] * (r[i]-1-l[i]));
        }
        return ans;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    //vector<int> hs({2,1,5,6,2,3} );
    //vector<int> hs({1,2,1} );
    //vector<int> hs({0,9} );
    //vector<int> hs({4,2,0,3,2,5} );
    //vector<int> hs({} );
    //vector<int> hs({2,1,2} );
    cout<<sol.largestRectangleArea(hs)<<endl;

    return 0;
}


