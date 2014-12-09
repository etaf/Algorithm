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

class Solution {
public:
    class mycmp{
        public:
        bool operator() (const ListNode* x,const ListNode* y) const{
            return x->val > y->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*,vector<ListNode* > , mycmp> Q;
        int m = lists.size();
        for(int i=0;i<m;++i){
            if(lists[i])Q.push(lists[i]);
        }
        ListNode* u;
        ListNode* merged_head = NULL;
        ListNode* merged_tail = NULL;
        while(!Q.empty()){
           u = Q.top();
           Q.pop();
           if(u->next)
               Q.push(u->next);
            if(merged_head == NULL) merged_head = merged_tail = u;
            else{
                merged_tail ->next  = u;
                merged_tail = u;
                merged_tail->next = NULL;
            }
        }
        return merged_head;

    }
};

void test(){
    vector<ListNode*> ls;
    for(int i=0;i<10;++i){
        ls.push_back(new ListNode(i));
    }
    for(int i=0;i<10;++i){
        ls[i]->next = new ListNode(i+10);
    }
    Solution sol;
    ListNode *now = sol.mergeKLists(ls);
    while(now){
        cout<<now->val<<" ";
        now = now->next;
    }
    cout<<endl;
    
}
int main()
{
    test();
	return 0;
}


