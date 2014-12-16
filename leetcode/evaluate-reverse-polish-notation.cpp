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
class Solution { //using stack
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int l,r;
        for(int i=0;i<tokens.size();++i)
        {
            if(tokens[i] !="+" && tokens[i] != "-" && tokens[i] !="*" && tokens[i] != "/" )
            {
                s.push(atoi(tokens[i].c_str()));
                continue;
            }
            r = s.top(); s.pop();l = s.top(); s.pop();
            if(tokens[i] == "+" ){
                s.push(l+r);
            }
            else if(tokens[i] == "-" ){
                s.push(l-r);
            }
            else if(tokens[i] == "*" ){
                s.push(l*r);
            }
            else if(tokens[i] == "/" ){
                s.push(l/r);
            }
        }
        return s.top();
    }

};

class Solution_recursive { //recursive version
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.size()==0)return 0;
        int end;
        return recursive(tokens,tokens.size()-1,end);
    }
    int str2num(string s){
        int flag = 1;
        int i=0;
        if(s[0] == '-'){
            flag = -1;
            i = 1;
        }
        else if(s[0] == '+') i=1;

        int res = 0;
        for(;i<s.size();++i)res = res*10+s[i]-'0';
        return res*flag;
    }
    int recursive(vector<string> &tokens,int begin,int& end){
       if( tokens[begin] != "+" && tokens[begin] != "-" && tokens[begin] !="*" && tokens[begin]!="/")
       {
           end = begin-1;
           return str2num(tokens[begin]);
       }
       int r = recursive(tokens,begin-1,end);
       int l = recursive(tokens,end,end);
       //cout<<l<<"-"<<r<<endl;
       if(tokens[begin] == "+") return l+r;
       if(tokens[begin] == "-") return l-r;
       if(tokens[begin] == "*") return l*r;
       if(tokens[begin] == "/") return l/r;
    }

};
void test(){
    Solution sol;
    vector<string> tokens({string("100"),string("100"),string("1"),string("2"),string("+"),string("-"),string("-")});
    cout<<sol.evalRPN(tokens)<<endl;
}
int main()
{

    cout<<stoi("123")<<endl;
    test();
	return 0;
}


