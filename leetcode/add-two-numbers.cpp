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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* now = l1;
        int len1 = 0;
        while(now){
            now = now->next;
            ++len1;
        }
        int len2 = 0;
        now = l2;
        while(now){
            now = now->next;
            ++len2;
        }
        if(len1<len2)swap(l1,l2);
        if(len1==0)return NULL;
        ListNode* now2 = l2;
        now = l1;
        int c = 0,tmpc;
        ListNode* pre_now = NULL;
        while(now && now2){
            tmpc = c;
            c = (now->val+now2->val + c)/10;
            now->val = (now->val + now2->val + tmpc)%10;
            pre_now = now;
            now = now->next;
            now2 = now2->next;
        }
        while(now && c){
            tmpc = c;
            c = (now->val+c)/10;
            now->val = (now->val+tmpc)%10;
            pre_now = now;
            now = now->next;
        }
        if(c){
            pre_now->next = new ListNode(c);
        }
        return l1;
    }
};
int main()
{
    ListNode* l1 = new ListNode(8);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    ListNode* l2 = new ListNode(2);
    Solution sol;
    ListNode* ans = sol.addTwoNumbers(l1,l2);
    while(ans){
        cout<<ans->val<<"->";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}


