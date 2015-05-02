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
    ListNode* removeElements(ListNode* head, int val) {
        if(NULL == head) return NULL;
        ListNode* pre = NULL;
        ListNode* now = head;
        while(now){
            if(now->val == val){
                if(NULL == pre){
                    head = now->next;
                }
                else{
                    pre->next = now->next;
                }
            }else{
                pre = now;
            }
            now = now->next;
        }
        return head;
    }

};
int main()
{
    return 0;
}


