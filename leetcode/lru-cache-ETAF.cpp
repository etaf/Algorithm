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
class LRUCache{
    private:
        class ListNode{
            public:
                ListNode(int k, int v):key(k),val(v),pre(NULL),next(NULL){};
                friend class LRUCache;
            private:
                int key,val;
                ListNode* pre,*next;
        };
    ListNode* head, *tail;
    int cap, size;
    unordered_map<int, ListNode*> M;
    void move2tail(ListNode* now){
        if(now == tail) return;
        if(now == head){
            head = head->next;
            head->pre = NULL;
        }else{
            now->pre->next = now->next;
            now->next->pre = now->pre;
        }
        tail->next = now;
        now->pre = tail;
        now->next = NULL;
        tail = now;
    }
    void push2tail(ListNode* now){
        if(size == cap){
            if(!head)return;
            pop_head();
        }
        if(!tail) head = tail = now;
        else{
            tail->next = now;
            now->pre = tail;
            tail = now;
        }
        ++size;
    }
    void pop_head(){
        M.erase(M.find(head->key));
        if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            head = head->next;
            delete head->pre;
            head->pre = NULL;
        }
        --size;
    }
public:
    LRUCache(int capacity) {
        M.clear();
        head = tail = NULL;
        cap = capacity;
        size = 0;
    }
    ~LRUCache(){
        ListNode* next = NULL;
        while(head){
            next = head ->next;
            delete head;
            head = next;
        }
    }
    int get(int key) {
        auto it = M.find(key);
        if(it != M.end())
        {
            move2tail(it->second);
            return it->second->val;
        }else{
            return -1;
        }
    }

    void set(int key, int value) {
        auto it = M.find(key);
        if(it != M.end()){
            it->second->val = value;
            move2tail(it->second);
        }else{
            ListNode* now = new ListNode(key,value);
            push2tail(now);
            M.insert(pair<int,ListNode*>(key,now));
        }
    }
    void show(){
        ListNode* now = head;
        while(now){
            cout<<now->val<<endl;
            now = now->next;
        }
    }

};
void test(){
   LRUCache cache(2);
   cache.set(2,1);
   cache.set(1,1);
   cout<<cache.get(2)<<endl;
   cache.set(4,1);
   cout<<cache.get(1)<<endl;
   cout<<cache.get(2)<<endl;
   //cache.show();
}
int main()
{
    test();
	return 0;
}




