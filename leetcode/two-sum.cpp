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
#include<unordered_map>
using namespace std;

class Solution_Onlogn { //sort and two pointer
public:

    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int,int> > ps;
        for(int i =0;i<numbers.size();++i)
            ps.push_back(pair<int,int>(numbers[i],i+1));
        sort(ps.begin(),ps.end());

        int p = 0, q=ps.size()-1;

        vector<int> ans;
        int sum;
        while(p<q){
            sum = ps[p].first + ps[q].first;
            if(sum == target)
            {
                ans.push_back(ps[p].second);
                ans.push_back(ps[q].second);
                if(ans[0]>ans[1])swap(ans[0],ans[1]);
                return ans;
            }
            if(sum < target)
                ++p;
            else
                --q;

        }
        return ans;
    }

};

class Solution_hash_table{ //O(n) hash
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int hash[100010];
        memset(hash,0,sizeof(hash));
        vector<int> ans;
        int tmp;
        int n = numbers.size();
        for(int i=0;i<n;++i)hash[numbers[i]] = i+1;
        for(int i=0;i<n;++i){
            tmp = target-numbers[i];

            if(tmp>=0 && hash[tmp] && hash[tmp]!=i+1)
            {
                ans.push_back(i+1);
                ans.push_back(hash[tmp]);

                return ans;
            }
        }
        return ans;
    }

};

class Solution_stl_hash{ //O(n) stl hash , unordered_multimap
    public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::unordered_map<int,int> M;
        vector<int> ans;
        int tmp;
        int n = numbers.size();
        for(int i=0;i<n;++i)M.insert(std::pair<int,int>(numbers[i],i+1));
        for(int i=0;i<n;++i){
            auto tmp = M.find(target - numbers[i]);
            if(tmp != M.end() && tmp->second != i+1)
            {
                ans.push_back(i+1);
                ans.push_back(tmp->second);
                if(ans[0]>ans[1])swap(ans[0],ans[1]);
                return ans;
            }
        }
        return ans;
    }

};

class Solution_stl_map{ //O(n) stl hash , stl map
    public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> M;
        vector<int> ans;
        int n = numbers.size();
        for(int i=0;i<n;++i)M.insert(std::pair<int,int>(numbers[i],i+1));
        for(int i=0;i<n;++i){
            auto tmp = M.find(target - numbers[i]);
            if(tmp != M.end() && tmp->second != i+1)
            {
                ans.push_back(i+1);
                ans.push_back(tmp->second);
                if(ans[0]>ans[1])swap(ans[0],ans[1]);
                return ans;
            }
        }
        return ans;
    }

};
void test(){
    vector<int> nums({2,1,9,4,4,56,90,3});
    Solution_stl_hash sol;
    vector<int> ans = sol.twoSum(nums,8);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}
int main()
{
    test();
	return 0;
}


