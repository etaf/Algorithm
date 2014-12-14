#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<limits.h>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> hash_table;
        for(int i=0;i<num.size();++i) hash_table.insert(num[i]);
        int ans = 0;
        int now,tmp,cnt;
        unordered_set<int>::iterator it;
        while(!hash_table.empty())
        {
            it = hash_table.begin();
            cnt = 1;
            tmp = now = *it;
            hash_table.erase(it);
            while( (it = hash_table.find(++tmp)) != hash_table.end()) hash_table.erase(it),++cnt;
            tmp = now;
            while( (it= hash_table.find(--tmp)) != hash_table.end()) hash_table.erase(it) , ++cnt;
            ans = ans > cnt ? ans : cnt;
        }
        return ans;
    }
};
class Solution_old {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> hash_table;
        for(int i=0;i<num.size();++i) hash_table.insert(num[i]);
        int ans = 0;
        int tmp,cnt;
        unordered_set<int>::iterator it;
        for(int i=0;i<num.size();++i){
            if(hash_table.find(num[i])!=hash_table.end()){
               cnt =1;
               tmp = num[i];
               while( (it = hash_table.find(++tmp))!=hash_table.end()){
                    hash_table.erase(it);
                    ++cnt;
               }
               tmp = num[i];
               while((it = hash_table.find(--tmp))!=hash_table.end()){
                    hash_table.erase(it);
                    ++cnt;
               }
               ans = ans > cnt ? ans : cnt;
            }
        }
        return ans;
    }
};
void test(){
    vector<int> num({100,4,200,1,3,2});
    Solution sol;
    cout<<sol.longestConsecutive(num)<<endl;
}
int main()
{
    test();
    int  a;
    int i = 0;
    while(a = 0){
        cout<<i<<endl;
        ++i;
    }
	return 0;
}


