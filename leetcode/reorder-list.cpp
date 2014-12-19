#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_old {//O(n)time O(1)space
public:
    void reorderList(ListNode *head) {
        if(NULL == head) return;
        ListNode* h1 = head,*h2 = NULL;
        int n = 0;
        while(h1){
            h1 = h1->next;

            ++n;
        }
        n = (n+1)/2-1;
        h1 = head;
        for(int i=0;i<n && h1;++i,h1=h1->next);
        h2 = h1->next;
        if(h2 == NULL)return;
        h1->next = NULL;
        h1 = h2;
        h2 = h2->next;
        h1->next = NULL;
        ListNode* next = NULL;
        while(h2){
           next = h2->next;
           h2->next = h1;
           h1 = h2;
           h2 = next;
        }
        h2 = h1;
        h1 = head;
        ListNode* next2;
        while(h1 && h2){
            next = h1->next;
            next2 = h2->next;
            h1->next = h2;
            h2->next = next;
            h2 = next2;
            h1 = next;
        }
    }
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if(NULL == head) return;
        ListNode* h1 ,*h2;
        h1 = head;
        h2 = head;
        while(h2->next != NULL  && h2->next->next != NULL){
            h1 = h1->next;
            h2 = h2->next->next;
        }
        h2 = h1->next;
        if(h2 == NULL) return;
        h1->next = NULL;

        h1 = h2;
        h2 = h2->next;
        h1->next = NULL;
        ListNode* next = NULL;
        while(h2){
           next = h2->next;
           h2->next = h1;
           h1 = h2;
           h2 = next;
        }
        h2 = h1;
        h1 = head;
        ListNode* next2;
        while(h1 && h2){
            next = h1->next;
            next2 = h2->next;
            h1->next = h2;
            h2->next = next;
            h2 = next2;
            h1 = next;
        }
    }
};
void show(ListNode* h){
    ListNode* now = h;
    while(now){
        cout<<now->val<<" ";
        now = now->next;
    }
}
int main(){

    Solution sol;
    ListNode* p[10];
    for(int i=0;i<10;++i){
        p[i] = new ListNode(i);
    }
    for(int i=0;i<9;++i){
        p[i]->next = p[i+1];
    }
    p[0]->next = NULL;
    sol.reorderList(p[0]);
    show(p[0]);
    return 0;
}
