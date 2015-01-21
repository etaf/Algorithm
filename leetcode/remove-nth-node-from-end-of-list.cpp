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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* pre = NULL,*nth,*now = head;
        while(--n){
            now = now->next;
        }
        nth = head;
        while(now->next){
            pre = nth;
            nth = nth->next;
            now = now->next;
        }
        if(pre){
            pre->next = nth->next;
        }else{
            head = nth->next;
        }
        delete nth;
        return head;
    }
};
int main()
{
    return 0;
}


