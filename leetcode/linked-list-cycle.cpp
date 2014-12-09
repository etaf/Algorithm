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

    ListNode(int x) : val(x), next(NULL) {}

};


class Solution { //two pointer ,faster and slower if has cycle the faster can catch slower one .
public:

    bool hasCycle(ListNode *head) {
        //if(!head)return false;
        ListNode* faster = head;
        ListNode* slower = head;
        while(faster && faster->next){
            faster = faster->next->next;
            slower = slower -> next;
            if(faster == slower) return true;
        }
        return false;
    }

};

class Solution_link_back { //modified the original struct , but can be modified back.

public:

    bool hasCycle(ListNode *head) {
        if(!head)return false;
        ListNode* now = head->next;
        ListNode* next;
        ListNode* pre = head;
        while(now){
            next = now->next;
            if(next == NULL) return false;
            if(next == head) return true;
            now->next  = pre;
            pre = now;
            now = next;
        }
        return false;
    }

};
void test(){
ListNode* p[10];
for(int i=0;i<10;++i)p[i] = new ListNode(i);
    Solution  sol;
    p[0]->next = p[1];
    p[1]->next = p[2];
    p[2]->next = p[0];
    cout<<sol.hasCycle(p[0])<<endl;
}
int main()
{
    test();
	return 0;
}


