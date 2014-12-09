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
#include<unordered_map>
using namespace std;

class LRUCache{

private:
    class ListNode{
    public:

        int key,val;
        ListNode * pre;
        ListNode * next;
        ListNode(int k,int v):key(k),val(v),pre(NULL),next(NULL){}
    };

    int size,c;
    ListNode* head;
    ListNode* tail;

    ListNode* hash_table[100001];

    void pop_back(){
        if(tail == head)return;
        ListNode* ntail = tail->pre;
        ntail ->next = NULL;
        hash_table[tail->key] = NULL;
        delete tail;
        tail = ntail;
        --size;
    }
    void detach(ListNode* x){
        ListNode* pre_x = x->pre;
        pre_x ->next = x->next;
        if(x->next)x->next->pre = pre_x;
        else tail = pre_x;
        --size;
    }
    void push_front(ListNode* x){
        if(size == c)pop_back();
        //capacity must be large than zero.
        ++size;
        ListNode* nh = head->next;
        head->next = x;
        x->pre = head;
        x->next = nh;
        if(nh)nh->pre = x;
        else tail = x;
    }
    void move2head(ListNode* x){
        if(x == head->next)return ;
        detach(x);
        push_front(x);
    }

    public:
    LRUCache(int capacity) {
        size = 0;
        c = capacity;
        head = new ListNode(0,0);
        tail = head;
        memset(hash_table,0,sizeof(hash_table));
    }

    int get(int key) {
        ListNode* it = hash_table[key];
        if(it == NULL) return -1;
        move2head(it);
        return it->val;
    }



    void set(int key, int value) {
        if(c<1)return;
        ListNode* it = hash_table[key];
        if(it != NULL){
            it->val = value;
            move2head(it);
        }
        else{
            ListNode * newNode = new ListNode(key,value);
            push_front(newNode);
            hash_table[key] = newNode;
        }


    }
    void show(){
        ListNode* now = head;
        while(now->next){
            now = now->next;
            cout<<now->key<<"->"<<now->val<<endl;
        }
    }

};

class LRUCache_stl_hash{

private:
    class ListNode{
    public:

        int key,val;
        ListNode * pre;
        ListNode * next;
        ListNode(int k,int v):key(k),val(v),pre(NULL),next(NULL){}
    };

    int size,c;
    ListNode* head;
    ListNode* tail;

    unordered_map<int,ListNode* > M;

    void pop_back(){
        if(tail == head)return;
        ListNode* ntail = tail->pre;
        ntail ->next = NULL;
        M.erase(tail->key);
        delete tail;
        tail = ntail;
        --size;
    }
    void detach(ListNode* x){
        ListNode* pre_x = x->pre;
        pre_x ->next = x->next;
        if(x->next)x->next->pre = pre_x;
        else tail = pre_x;
        --size;
    }
    void push_front(ListNode* x){
        if(size == c)pop_back();
        //capacity must be large than zero.
        ++size;
        ListNode* nh = head->next;
        head->next = x;
        x->pre = head;
        x->next = nh;
        if(nh)nh->pre = x;
        else tail = x;
    }
    void move2head(ListNode* x){
        if(x == head->next)return ;
        detach(x);
        push_front(x);
    }

public:

    LRUCache_stl_hash(int capacity) {
        size = 0;
        c = capacity;
        head = new ListNode(0,0);
        tail = head;
    }

    int get(int key) {
        unordered_map< int, ListNode* >::iterator it = M.find(key);
        if(it == M.end()) return -1;
        move2head(it->second);
        return it->second->val;
    }



    void set(int key, int value) {
        if(c<1)return;
        unordered_map< int, ListNode* >::iterator it = M.find(key);
        if(it != M.end()){
            it->second->val = value;
            move2head(it->second);
        }
        else{
            ListNode * newNode = new ListNode(key,value);
            push_front(newNode);
            M.insert(std::pair< int,ListNode* >(key,newNode));
        }


    }
    void show(){
        ListNode* now = head;
        while(now->next){
            now = now->next;
            cout<<now->key<<"->"<<now->val<<endl;
        }
    }

};
void test(){
   LRUCache cache(1);
   cache.get(0);
   cache.show();
    /*for(int i=0;i<1000;++i){*/
        //cache.set(i,i);
        //cache.get(i-1);
    /*}*/
   /*cache.get(1);*/
   //cache.set(1,1);
   //cache.set(2,2);
   //cache.set(3,3);
   //cache.set(4,4);
   //cache.get(3);
   //cache.get(2);
   /*cache.show();*/
}
int main()
{
    test();
	return 0;
}


