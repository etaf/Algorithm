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
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution { // the two list have same end! once meet, the rest is the same.
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* pa = headA;
       ListNode* pb=  headB;
       bool fa = true,fb= true;
       while(pa && pb)
       {
            if(pa == pb)return pa;
            pa = pa->next;
            pb = pb->next;
            if(pa == NULL && fa){
                pa = headB;
                fa = false;
            }
            if(pb == NULL && fb){
                pb = headA;
                fb = false;
            }
       }
       return NULL;
    }
};

class Solution_etaf_force {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int maxa=-0x3fffffff;
        ListNode* tmp= headA;
        while(tmp)
        {
            maxa = max(maxa,tmp->val);
            tmp = tmp->next;
        }
        int minb = 0x3fffffff;
        tmp = headB;
        while(tmp)
        {
            minb = min(minb,tmp->val);
            tmp = tmp->next;
        }
        tmp = headB;
        minb-=1;
        while(tmp)
        {
            tmp->val += maxa - minb;
            tmp = tmp->next;
        }
        ListNode* ans = NULL;
        tmp = headA;
        while(tmp){
            if(tmp->val > maxa)
            {
                ans = tmp;
                break;
            }
            tmp = tmp->next;
        }
        tmp = headB;
        while(tmp){
            tmp->val += minb - maxa;
            tmp = tmp->next;
        }
        return ans;
    }
};
void test()
{
    ListNode* a[10];
    ListNode* b[10];
    for(int i=0;i<10;++i)
    {
        a[i] = new ListNode(i);
        if(i-1>=0)a[i-1]->next = a[i];
    }
    for(int i=0;i<5;++i)
    {
        b[i] = new ListNode(i+10);
        if(i-1>=0) b[i-1]->next = b[i];

    }
    b[4]->next = a[9];
    Solution sol;
    ListNode* ans = sol.getIntersectionNode(a[0],a[2]);
    if(ans)
        cout<<ans->val<<endl;
    else
        cout<<"NULL"<<endl;

}
int main()
{
    test();
    return 0;
}

