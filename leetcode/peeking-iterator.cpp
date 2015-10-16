
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
typedef long long llong;
using namespace std;
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    int cnt;
    int d;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    cnt = 0;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(cnt) return d;
        else {
            cnt=1;
            d = Iterator::next();
            return d;
        }
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(cnt){
	        cnt = 0;
	        return d;
	    }else{
	        return Iterator::next();
	    }
	}

	bool hasNext() const {
	    if(cnt) return true;
	    return Iterator::hasNext();
	}
};
int main()
{
    std::ios::sync_with_stdio(false);
    return 0;
}


