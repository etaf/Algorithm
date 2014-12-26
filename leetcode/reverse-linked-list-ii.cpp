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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n)return head;
        ListNode* lpre=NULL,*pre = NULL, *now = head, *next,*start;
        n-=m;
        while(--m)
        {
            lpre = now;
            now = now->next;
        }
        start = now;
        pre = now;
        now = now->next;
        while(n--){
            next = now->next;
            now->next = pre;
            pre = now;
            now = next;
        }
        start->next = now;
        if(lpre == NULL){
            head = pre;
        }else{
            lpre->next = pre;
        }
        return head;
    }
};
void show(ListNode* head){
while(head){
        cout<<head->val<<"->";
        head=head->next;
    }
cout<<endl;
}
int main()
{
    ListNode* p[10];
    for(int i=1;i<=5;++i)p[i] = new ListNode(i);
    for(int i=1;i<5;++i)p[i]->next = p[i+1];
    show(p[1]);
    Solution sol;
    ListNode* head = sol.reverseBetween(p[1],2,4);
    show(head);
    return 0;
}


