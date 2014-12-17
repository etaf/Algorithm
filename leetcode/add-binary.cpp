#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
    string addBinary(string a, string b) {
        string c = "";
        int d=0,sum;
        int i,j;
        for( i=a.size()-1,j=b.size()-1;i>=0 && j>=0;--i,--j){
            sum = a[i]-'0'+b[j]-'0'+d;
            d = sum/2;
            c.push_back(sum%2 + '0');
        }
        while(i>=0){
            sum = a[i--] - '0'+d;
            d = sum/2;
            c.push_back(sum%2 + '0');
        }
        while(j>=0){
            sum = b[j--] - '0' + d;
            d = sum/2;
            c.push_back(sum%2 + '0');
        }
        if(d)c.push_back(d+'0');
        j = c.size()-1;
        while(c[j]=='0' && j>0){
            c.pop_back();
            --j;
        }
        i=0;
        while(i<j) swap(c[i++],c[j--]);
        return c;
    }
};
int main(){

    string a("1");
    string b("1");
    Solution sol;
    cout<<sol.addBinary(a,b)<<endl;

}
