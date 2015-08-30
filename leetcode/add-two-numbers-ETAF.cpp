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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* now1 = l1, *now2 = l2, *pre_now1=NULL;
        int len1=0, len2=0;
        while(now1){
            ++len1;
            now1=now1->next;
        }
        while(now2){
            ++len2;
            now2=now2->next;
        }
        if(len2>len1)swap(l1,l2);
        now1 = l1;
        now2 = l2;
        int c = 0;
        int tmp;
        while(now2){
            tmp = now1->val + now2->val + c;
            now1->val = tmp%10;
            c = tmp/10;
            pre_now1 = now1;
            now1 = now1->next;
            now2 = now2->next;
        }
        while(c && now1){
            tmp = now1->val + c;
            now1->val = tmp%10;
            c = tmp/10;
            pre_now1 = now1;
            now1 = now1->next;
        }
        if(c){
            pre_now1->next = new ListNode(c);
        }
        return l1;
    }
};
int main()
{
    ListNode* l1 = new ListNode(3);
    l1->next = new ListNode(7);
    //l1->next->next = new ListNode(9);
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(2);
    Solution sol;
    ListNode* ans = sol.addTwoNumbers(l1,l2);
    while(ans){
        cout<<ans->val<<"->";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}


