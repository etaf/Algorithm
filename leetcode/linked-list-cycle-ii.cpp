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
#include<unordered_set>
#include<unordered_map>
using namespace std;



struct ListNode {

    int val;

    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

};
class Solution { //use faster slower to find a ponit X in the circle, then cut the link which is a next poniter point to X.
                //Then the question belong to FIND common node of two links.

    public:
    ListNode *detectCycle(ListNode *head) {

        if(!head)return NULL;
        ListNode* faster = head->next;
        ListNode* slower = head;
        ListNode* h1 = head;
        ListNode* h2 = NULL;
        while(faster && faster->next){
            slower = slower->next;
            if(faster->next->next == slower)
            {
                faster->next->next = NULL;
                h2 = slower;
                break;
            }
            faster = faster->next->next;
        }
        if(h2 == NULL)return NULL;
        faster = h1;
        slower = h2;
        while(faster && slower)
        {
            if(faster == slower)return faster;
            faster = faster->next;
            slower = slower->next;
            if(!faster && slower) faster = h2;
            if(faster && !slower) slower = h1;

        }
        return NULL;
    }
};
class Solution_no_extra_space_but_TLE {

    public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* now = head;
        ListNode* next;
        if(!hasCycle(head))return NULL;
        while(now){
            next = now->next;
            now->next = NULL;
            if(!hasCycle(next)){
                now->next = next;
                return now;
            }
            now->next = next;
            now = next;
        }
        return NULL;
    }
    bool hasCycle(ListNode *head) {
        ListNode* faster = head->next;
        ListNode* slower = head;
        while(faster && faster->next){
            if(faster->next == slower || faster->next->next == slower) return true;
            faster = faster->next->next;
            slower = slower -> next;
        }

        return false;

    }
};


class Solution_extra_space { //have to use a hash map.
    public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)return NULL;
        unordered_set<ListNode*> S;
        ListNode* now = head;
        while(now){
            if(S.find(now)!=S.end())return now;
            else S.insert(now);
            now = now->next;
        }
        return NULL;
    }
};
void test(){
    ListNode* p[10];
    for(int i=0;i<10;++i)p[i] = new ListNode(i);
    for(int i=0;i<9;++i)p[i]->next = p[i+1];
    p[0]->next = p[0];
    Solution sol;
    ListNode* ans = sol.detectCycle(p[0]);
    if(ans)cout<<ans->val<<endl;
    else cout<<"NULL"<<endl;
}
int main()
{
    test();
	return 0;
}


