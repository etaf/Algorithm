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
        ListNode *now = head, *next = head->next,*tmp,*pre = NULL;
        bool flag = false;
        while(next){
            if(now->val == next->val)
            {
                flag = true;
                tmp = next->next;
                now->next = tmp;
                delete next;
                next = tmp;
            }
            else{
                if(flag){
                    //delete now
                    if(pre==NULL){
                        head =  next;
                    }else{
                        pre->next = next;
                    }
                    delete now;
                    flag = false;
                }else{
                    pre = now;
                }
                now = next;
                next = next->next;
            }
        }
        if(flag){
            if(pre == NULL){
                head = next;
            }else{
                pre->next = NULL;
            }
            delete now;
        }
        return head;
    }

};
int main(){
    return 0;
}
