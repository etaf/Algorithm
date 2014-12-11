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

class Solution {

public:

    ListNode *insertionSortList(ListNode *head) {
        if(!head)return NULL;
        ListNode* now = head,*t = head->next,*nt = NULL,*pret = head, *npre;
        while(t){
            now = head;
            nt = t->next;
            pret->next = nt;
            while(now != nt){
                if(now->val > t->val){
                    if(now == head){
                        t->next = head;
                        head = t;
                    }else{
                       npre->next = t;
                       t->next = now;
                    }
                    break;
                }
                npre = now;
                now  = now->next;
            }
            if(now == nt){
                pret->next = t;
                t->next = nt;
                pret = t;
            }
            t=nt;
        }
        return head;
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
    ListNode* p[10];
    for(int i=0;i<10;++i)p[i] = new ListNode(10-i);
    for(int i=0;i<9;++i)p[i]->next = p[i+1];
    Solution  sol;
    sol.show(p[0]);
    cout<<endl;
    sol.show(sol.insertionSortList(p[0]));
	return 0;
}


