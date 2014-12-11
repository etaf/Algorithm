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


struct ListNode {

    int val;
    ListNode *next;
    int x;
    short y;

    ListNode(int x) : val(x), next(NULL) {}

};


class Solution { //merge sort
    public:
    ListNode *sortList(ListNode *head) {
        if(!head)return NULL;
        ListNode* now, *h1,*h2,*pre = NULL,*next= NULL;
        int cnt = 0;
        pair<ListNode*,ListNode*> pn;
        now = head;
        while(now){
            ++cnt;
            now=now->next;
        }
        int m = cnt;
        for(int l = 1;l<m;l<<=1){
            cnt = 0;
            now = head;
            pre = NULL;
            while(now){
                cnt = 1;
                h1 = now;
               while(now && cnt < l)
               {
                   now = now->next;
                   ++cnt;
               }
               if(!now)break;
               h2 = now->next;
               now->next = NULL;
               now = h2;
               cnt = 1;
               if(!h2)break;
               while(now && cnt < l){
                   now = now->next;
                   ++cnt;
               }
               if(now)
               {
                next = now->next;

                now->next = NULL;
               }
               else next = NULL;

               pn = merge(h1,h2);
               if(pre == NULL){
                head = pn.first;
               }
               else{
                pre->next = pn.first;
               }
                pn.second->next = next;
                pre = pn.second;
                now = next;
            }
        }
        return head;
    }
    pair<ListNode*,ListNode*> merge(ListNode* h1,ListNode* h2)
    {
        ListNode* h = new ListNode(0),*p1=h1,*p2=h2;
        ListNode* t = h;
        while(p1 && p2)
        {
            if(p1->val < p2->val)
            {
                t->next = p1;
                t = p1;
                p1 = p1->next;
            }
            else{
                t->next = p2;
                t = p2;
                p2 = p2->next;
            }
        }
        while(p1){t->next = p1;t=p1;p1 = p1->next;}
        while(p2){t->next = p2;t=p2;p2 = p2->next;}
        return pair<ListNode*,ListNode*>(h->next,t);
    }

    void show(ListNode* head){
       while(head){
        cout<<head->val<<" ";
        head = head->next;
       }
    }
};

class Solution_quick_sort { //TLE because of the worst case
public:
    ListNode *sortList(ListNode *head) {//quick sort
        if(!head)return NULL;
        ListNode *h1 = NULL, *h2 = NULL,*t1=NULL,*t2=NULL, *now = head->next, *next;
        while(now){
            next = now->next;
           if(now->val >= head->val){
               if(!h1){
                   h1 = now;
                   t1 = now;
                   t1->next = NULL;
               }
               else{
                   t1->next = now;
                   t1 = now;
                   t1->next = NULL;
               }
           }
           else{
            if(!h2){
                h2 = now;
                t2 = now;
                t2->next = NULL;
            }
            else{
                t2->next = now;
                t2 = now;
                t2->next = NULL;
            }
           }
           now = next;
        }
        h1 = sortList(h1);
        h2 = sortList(h2);
        ListNode* nh = NULL;
        if(h1){
            nh = h1;
            t1 = h1;
            while(t1->next)t1 = t1->next;
            t1->next = head;
            head->next = NULL;
        }else nh = head;
        head->next = h2;
        return nh;
    }

    void show(ListNode* head){
       while(head){
        cout<<head->val<<" ";
        head = head->next;
       }
    }
};
int main()
{
    cout<<"bool:\t\t"<<sizeof(bool)<<endl;
    cout<<"char:\t\t"<<sizeof(char)<<endl;
    cout<<"short:\t\t"<<sizeof(short)<<endl;
    cout<<"int:\t\t"<<sizeof(int)<<endl;
    cout<<"long:\t\t"<<sizeof(long)<<endl;
    cout<<"long long:\t"<<sizeof(long long )<<endl;
    cout<<"float:\t\t"<<sizeof(float)<<endl;
    cout<<"double:\t\t"<<sizeof(double)<<endl;
    cout<<"long double:\t"<<sizeof(long double)<<endl;
    ListNode* p[10];
    for(int i=0;i<10;++i)p[i] = new ListNode(10-i);
    for(int i=0;i<9;++i)p[i]->next = p[i+1];
    Solution  sol;
    //sol.show(p[0]);
    sol.show(sol.sortList(p[0]));
	return 0;
}


