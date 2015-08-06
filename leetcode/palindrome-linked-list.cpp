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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n =0;
        ListNode* now = head, *pre, *next;
        while(now){
            ++n;
            now = now->next;
        }
        if(n < 2) return true;
        now = head;
        pre = NULL;
        for(int i=0; i<(n+1)/2; ++i){
            next = now->next;
            now->next = pre;
            pre = now;
            now = next;
        }
        if(n&1){
            pre = pre->next;
        }
        //cout<<pre->val<<" -> "<<now->val<<endl;
        while(pre && now){
            if(pre->val != now->val) return false;
            pre=pre->next;
            now=now->next;
        }
        return true;
    }
};
int main()
{
    Solution sol;
    int n = 10;
    ListNode* p[n];
    for(int i=0; i<n; ++i){
        p[i] = new ListNode(i);
    }
    for(int i=0; i<n-1; ++i){
        p[i]->next = p[i+1];
    }
    p[n-1]->next = NULL;
    p[0]->val = 1;
    p[1]->val = 2;
    p[2]->val = 1;
    p[2]->next = NULL;
    cout<<sol.isPalindrome(p[0])<<endl;
    return 0;
}


