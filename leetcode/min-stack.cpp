#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
using namespace std;
class MinStack{
    private:
        stack<int> s;
        stack<int> mins;
    public:

    void push(int x){
        s.push(x);
        if(mins.empty())mins.push(x);
        else mins.push( min(mins.top(),x) );
    }
    void pop(){
        mins.pop();
        s.pop();
    }
    int top(){
        return s.top();
    }
    int getMin(){
        return mins.top();
    }
};

class MinStack_optimized{
    private:
        stack<int> s;
        stack<int> mins;
    public:

    void push(int x){
        s.push(x);
        /*if(mins.empty())mins.push(x);*/
        /*else mins.push( min(mins.top(),x) );*/
        if(mins.empty() || mins.top()>=x)
            mins.push(x);
    }
    void pop(){
        if(!mins.empty() && s.top() == mins.top() )mins.pop();
        s.pop();
    }
    int top(){
        return s.top();
    }
    int getMin(){
        return mins.top();
    }
};

void test(){
    MinStack s;
    s.push(3);
    s.push(4);
    s.push(-1);
    s.push(2);
    s.push(5);
    cout<<s.top()<<" "<<s.getMin()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.top()<<" "<<s.getMin()<<endl;
/*    s.pop();*/
    //s.pop();
    /*cout<<s.top()<<" "<<s.getMin()<<endl;*/
   }
int main()
{
    test();
	return 0;
}


