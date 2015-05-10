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
    ListNode* reverseList(ListNode* head) {
        ListNode* now = head, *pre = NULL, *next = NULL;
        while(now){
            next = now->next;
            now->next = pre;
            pre = now;
            now = next;
        }
        head = pre;
        return head;
    }
};
int main()
{
    return 0;
}


