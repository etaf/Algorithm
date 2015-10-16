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
typedef long long llong;
class Solution {
public:
    string path;
    llong st[1024];
    int cnt;
    llong _target;
    string _num;
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        _num = num;
        _target = target;
       ans.clear();
        cnt = 0;
        path = "";
        st[cnt++] = num[0]-'0';
        path.push_back(num[0]);
        dfs(1);
        if(num[0] == '0') return ans;
        for(int i=1; i<_num.size(); ++i){
            st[cnt-1] = st[cnt-1]*10 + _num[i]-'0';
            path.push_back(num[i]);
            dfs(i+1);
        }

        return ans;
    }
    void dfs(int u){
        if(u == _num.size()){
            //llong bk[cnt];

            //for(int i=0; i<cnt; ++i)bk[i] = st[i];
            llong res = st[0];
            for(int i=0; i+2<cnt; i+=2){
                if(st[i+1] == -1){
                    res += st[i+2];
                }else{
                    res = res - st[i+2];
                }
            }
            if(res == _target){
/*                for(int i=0; i<cnt;++i){*/
                    //cout<<bk[i]<<" ";
                //}
                /*cout<<endl;*/
                ans.push_back(path);
            }
            return;
        }
        llong v = 0;
        string vs ="";
        llong tmp = st[cnt-1];
        string tmp_path = path;
        for(int i=u; i<_num.size(); ++i){
            if(i==u+1 && v ==0)return;
            v= v*10 + _num[i]-'0';
            vs.push_back(_num[i]);
            st[cnt-1] *= v;
            path.push_back('*');
            path+=vs;
            dfs(i+1);
            st[cnt-1] = tmp;
            path = tmp_path;

/*            if(tmp == 1020){*/
                //cout<<"!!"<<endl;
            /*}*/

            st[cnt++] = -1;
            st[cnt++] = v;
            path.push_back('+');
            path+= vs;
            dfs(i+1);
            cnt-=2;
            path = tmp_path;

            st[cnt++] = -2;
            st[cnt++] = v;
            path.push_back('-');
            path+= vs;
            dfs(i+1);
            cnt-=2;
            path = tmp_path;


        }
    }

};
Solution sol;
void test1(){
    cout<<"test1:"<<endl;
    string num("123");
    int target = 6;
    vector<string> ans = sol.addOperators(num,target);
    for(auto & s : ans){
        cout<<s<<endl;
    }
}
void test2(){
    cout<<"test2:"<<endl;
    string num("232");
    int target = 8;
    vector<string> ans = sol.addOperators(num,target);
    for(auto & s : ans){
        cout<<s<<endl;
    }

}
void test3(){
    cout<<"test3:"<<endl;
    string num("105");
    int target = 5;
    vector<string> ans = sol.addOperators(num,target);
    for(auto & s : ans){
        cout<<s<<endl;
    }

}
void test4(){
    cout<<"test4:"<<endl;
    string num("00");
    int target = 0;
    vector<string> ans = sol.addOperators(num,target);
    for(auto & s : ans){
        cout<<s<<endl;
    }

}
void test5(){
    cout<<"test5:"<<endl;
    string num("3456237490");
    int target = 9191;
    vector<string> ans = sol.addOperators(num,target);
    for(auto & s : ans){
        cout<<s<<endl;
    }

}
int main()
{
    std::ios::sync_with_stdio(false);
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}


