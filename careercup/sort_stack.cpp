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

void move_top_to_bottom(stack<int>& st){
    if(st.size()<2) return;
    int tp1 = st.top();
    st.pop();
    int tp2 = st.top();
    st.pop();
    st.push(tp1);
    move_top_to_bottom(st);
    st.push(tp2);
}
void reverse_stack(stack<int>& st){
    if(st.empty()) return;
    int tp = st.top();
    st.pop();
    reverse_stack(st);
    st.push(tp);
    move_top_to_bottom(st);
}

void ordered_insert(stack<int>& st){
    if(st.size()<2) return;
    int tp1 = st.top();
    st.pop();
    if(tp1<st.top()){
        int tp2 = st.top();
        st.pop();
        st.push(tp1);
        tp1 = tp2;
        ordered_insert(st);
    }
    st.push(tp1);
}
void sort_stack(stack<int> &st){
    if(st.empty()) return;
    int tp = st.top();
    st.pop();
    sort_stack(st);
    st.push(tp);
    ordered_insert(st);
}

int main()
{
    //stack<int> st({1,4,3,2});
    stack<int> st({2,4,1,5,67,1,12,21,1});
    sort_stack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}


