#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
class Solution {
    public:
    int compareVersion(string version1, string version2) {
        vector<int> vs1 = split(version1,'.');
        vector<int> vs2 = split(version2,'.');
        /*for(size_t i=0;i<vs1.size();++i)cout<<vs1[i]<<" ";*/
        //cout<<endl;
        //for(size_t i=0;i<vs2.size();++i)cout<<vs2[i]<<" ";
        /*cout<<endl;*/
        size_t n = max(vs1.size(),vs2.size());
        for(size_t i = vs1.size();i<n;++i) vs1.push_back(0);
        for(size_t i = vs2.size();i<n;++i) vs2.push_back(0);
        size_t i;
        for(i = 0; i<n && vs1[i]==vs2[i] ;++i);
        if(i == n){
            return 0;
        }
        if(vs1[i]>vs2[i])return 1;
        if(vs1[i]<vs2[i]) return -1;
        return 0;
    }
    vector<int> split(string s, char c){
        vector<int> res;
        string tmp;
        for(size_t i=0;i<s.size();++i){
            tmp = "";
            while(i<s.size() && s[i] == c) ++i;
            if(i==s.size())break;
            while(i<s.size() && s[i] !=c && s[i] == '0') ++i;
            while(i<s.size() && s[i] !=c)tmp.push_back(s[i++]);
            if(tmp.size() == 0)res.push_back(0);
            res.push_back(std::atoi(tmp.c_str()));
        }
        return res;
    }
};
int main(){
    Solution sol;
    string v1("01.10.2");
    string v2("1.10.2.0.0");
    cout<<sol.compareVersion(v1,v2)<<endl;
    return 0;
}
