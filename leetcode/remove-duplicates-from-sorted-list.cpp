#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)return NULL;
        ListNode *now = head, *next = head->next,*tmp;
        while(next){
            if(now->val == next->val)
            {
                tmp = next->next;
                now->next = tmp;
                delete next;
                next = tmp;
            }
            else{
                now = next;
                next = next->next;
            }
        }
        return head;
    }

};
int main(){

    return 0;
}
