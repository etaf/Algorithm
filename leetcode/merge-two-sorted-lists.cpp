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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode * head = NULL,*now = NULL, *next = NULL;
        while(l1 && l2){
            if(l1->val <= l2->val){
                next = l1;
                l1 = l1->next;
            }else{
                next = l2;
                l2 = l2->next;
            }
            if(now == NULL){
                head = next;
            }
            else{
                now->next = next;
            }
            now = next;
        }
        if(l2)l1 = l2;
        while(l1){
            if(head == NULL){
                head = l1;
            }else{
                now->next = l1;
            }
            now = l1;
            l1 = l1->next;
        }
       return head;
    }
};
int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    //l2 = NULL;
    Solution sol;
    ListNode* ans = sol.mergeTwoLists(l1,l2);
    while(ans){
        cout<<ans->val <<"->";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}


