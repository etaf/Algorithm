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
    int st[1024], cnt;
    const char* s;
    vector<int> ans;
    int n;
    vector<int> diffWaysToCompute(string input) {
        cnt = 0;
        s = input.c_str();
        n = input.size();
        ans.clear();
        dfs(0);
        return ans;
    }
    void dfs(int u){
        if(u == n){
            return;
        }
        if(s[u] == '+'){
            st[cnt++] = -1;
            dfs(u+1);
            --cnt;
            return;
        }
        if(s[u] == '-'){
            st[cnt++] = -2;
            dfs(u+1);
            --cnt;
            return;
        }
        if(s[u] == '*'){
            st[cnt++] = -3;
            dfs(u+1);
            --cnt;
            return;
        }
        int v = s[u] - '0';
        while(u+1<n && s[u+1]>='0' && s[u+1] <='9'){
            v = v*10 + s[++u] - '0';
        }
        int tmp = cnt;
        int bk[1024];
        for(int i=0;i<cnt;++i){
            bk[i] = st[i];
        }
        st[cnt++] = v;
        dfs(u+1);
        while(cnt>2){
            if(st[cnt-2] == -1){
                st[cnt-3] +=  st[cnt-1];
            }else if(st[cnt-2] == -2){
                st[cnt-3] -=  st[cnt-1];
            }else{
                st[cnt-3] *= st[cnt-1];
            }
            cnt-=2;
            dfs(u+1);
        }
        if(u == n-1 && cnt == 1) ans.push_back(st[0]);

        cnt = tmp;
        for(int i=0;i<cnt;++i){
            st[i] = bk[i];
        }
    }
};
class Solution_old {
public:
    stack<int> st;
    vector<int> ans;
    int len;
    const char * s;
    vector<int> diffWaysToCompute(string input) {
        s = input.c_str();
        len = input.size();
        dfs(0);
        return ans;
    }
    void dfs(int u){
        if(u >= len) return;
        if(s[u] == '+' || s[u] == '-' || s[u] == '*')
        {
            if(s[u] == '+')
                st.push(-1);
            else if(s[u] == '-')
                st.push(-2);
            else
                st.push(-3);
            dfs(u+1);
            st.pop();
            return;
        }
        int x = 0;
        while(u<len && s[u]!='+' && s[u]!='-' && s[u]!='*')
        {
            x = x*10 + s[u] - '0';
            ++u;
        }
        --u;

        stack<int> st_bk = st;
        st.push(x);
        dfs(u+1);
        int res;
        while(st.size()>2)
        {
            int r = st.top();
            st.pop();
            int op = st.top();
            st.pop();
            int l = st.top();
            st.pop();
            if(op == -1){
                //cout<<l<<"+"<<r<<endl;
                res = l + r;
            }else if(op == -2){
                //cout<<l<<"-"<<r<<endl;
                res = l - r;
            }
            else if(op == -3){
                //cout<<l<<"*"<<r<<endl;
                res = l * r;
            }
            else{
                cout<<"!!! wrong op:"<< op<<endl;
            }
            st.push(res);
            dfs(u+1);
        }
        if(st.size() == 1 && u == len-1)
        {
            //cout<<"!!!"<<res<<endl;
            ans.push_back(st.top());
        }
        st = st_bk;
    }
};

class Solution_other_throught {
public:
    class Node{
        public:
            int v;
            int l,r;
            Node(int v1, int l1, int r1 ): v(v1), l(l1), r(r1){}
            Node(int v1): v(v1), l(-1), r(-1){}
    };
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
    int clc(const vector<int>& ops, vector<Node> ns){
        int res;
        int op, pre, next;
                for(uint32_t i=0; i<ops.size(); ++i){
            op = ops[i];
            pre = ns[op].l;
            next = ns[op].r;
            if(ns[op].v == 0){
                res = ns[pre].v + ns[next].v;
            }
            else if(ns[op].v == 1){
                res = ns[pre].v - ns[next].v;
            }
            else{
                res = ns[pre].v * ns[next].v;
            }
            if(ns[pre].l != -1){
                ns[ns[pre].l].r = op;
            }
            if(ns[next].r != -1){
                ns[ns[next].r].l = op;
            }
            ns[op].v = res;
            ns[op].l = ns[pre].l;
            ns[op].r = ns[next].r;
        }
        return res;
    }

    vector<int> diffWaysToCompute(string input) {
        vector<Node> ns;
        vector<int> ops;
        int x;
        for(uint32_t i=0; i<input.size();++i){
            if(input[i] != '+' && input[i] !='-' && input[i]!='*')
            {
                x = input[i]-'0';
                while(i+1<input.size() && input[i+1] != '+' && input[i+1] !='-' && input[i+1]!='*'){
                    x = x*10 + input[i+1] -'0';
                    ++i;
                }
                ns.push_back(Node(x));
            }
            else{
                ops.push_back(ns.size());
                if(input[i] == '+'){
                    ns.push_back(Node(0));
                }else if(input[i] == '-'){
                    ns.push_back(Node(1));
                }else {
                    ns.push_back(Node(2));
                }
            }
        }
        if(ns.size()==0) return vector<int>({0});
        if(ns.size()==1){
            ns[0].l = ns[0].r = -1;
        }else{
            ns[0].l = -1;
            ns[0].r = 1;
            ns[ns.size()-1].r = -1;
            ns[ns.size()-1].l = ns.size()-2;
        }
        ns[0].l = -1;
        ns[ns.size()-1].r = -1;
        for(uint32_t i=1; i<ns.size()-1; ++i){
            ns[i].l = i-1;
            ns[i].r = i+1;
        }

        vector<int> ans;
        ans.push_back(clc(ops, ns));
        while(nextPermutation(ops)){
            ans.push_back(clc(ops, ns));
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    freopen("in", "r", stdin);
    string s;
    while(cin>>s){
    Solution sol;
    vector<int> ans = sol.diffWaysToCompute(s);
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); ++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    }
    return 0;
}


