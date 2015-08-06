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
class Queue {
    private:
        stack<int> st1, st2;
        void func(){
            int tmp;
            while(!st1.empty()){
                tmp = st1.top();
                st1.pop();
                st2.push(tmp);
            }
        }
    public:
        // Push element x to the back of queue.
        void push(int x) {
            st1.push(x);
        }

        // Removes the element from in front of queue.
        void pop(void) {
            if(st2.empty()){
                func();
            }
            st2.pop();
        }

        // Get the front element.
        int peek(void) {
            if(st2.empty()){
                func();
            }
            return st2.top();
        }

        // Return whether the queue is empty.
        bool empty(void) {
            return st1.empty() && st2.empty();
        }
};
int main()
{
    Queue q;
    for(int i=1;i<5; ++i) q.push(i);
    for(int i=1;i<5; ++i) {
        cout<<q.peek()<<" "<<endl;
        q.pop();
    }
    cout<<endl;
    return 0;
}


