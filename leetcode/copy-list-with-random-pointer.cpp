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




struct RandomListNode {

    int label;

    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}

};

class Solution { //O(n)

public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)return NULL;
        RandomListNode* now = head;
        RandomListNode* tmp;
        while(now){
           tmp = now->next;
           now->next = new RandomListNode(now->label);
           now->next->next = tmp;
           now = tmp;
        }
        now = head;
        while(now)
        {
            now->next->random = (now->random ? now->random->next : NULL);
            now = now->next->next;
        }
        now = head;
        RandomListNode* u = now->next;
        RandomListNode* ans = head->next;
        while(now)
        {
            now->next = u->next;
            u->next =( now->next == NULL ? NULL : now->next->next);
            now = now->next;
            u = u->next;
        }
        return ans;
    }


};

class Solution_nlogn {

public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)return NULL;
        map<RandomListNode* , RandomListNode*> M;
        vector<RandomListNode*> ns;
        RandomListNode* u = head;
        RandomListNode* tmp;
        while(u){
            tmp = new RandomListNode(u->label);
           ns.push_back(tmp);
           M[u] = tmp;
           u = u->next;
        }
        for(int i=0;i+1<ns.size();++i)
        {
            ns[i]->next = ns[i+1];
        }
        u = head;
        RandomListNode* v = ns[0];
        while(u){
            v->random = M[u->random] ;
            v = v->next;
            u = u->next;
        }
        return ns[0];
    }


};
void test(){
    RandomListNode* x = new RandomListNode(1);
    Solution sol;
    RandomListNode* y = sol.copyRandomList(x);
    cout<<y->label<<endl;
}
int main()
{
    test();
	return 0;
}


