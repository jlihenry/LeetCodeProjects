#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> minStack;
    stack<int> min;
    stack<int> index;
    
public:
    void push(int x) {
        if (minStack.empty())
        {
            min.push(x);
            index.push(0);
        }
        else if (x < min.top())
        {
            min.push(x);
            index.push(minStack.size());
        }
        minStack.push(x);
    }

    void pop() {
        minStack.pop();
        if (minStack.size() == index.top()) 
        {
            min.pop();
            index.pop();
        }
    }

    int top() {
        return minStack.top();
    }

    int getMin() {
        return min.top();
    }
};


int main()
{
	MinStack s;
	s.push(2);
	s.push(0);
	s.push(3);
	s.push(0);
	cout << s.getMin() << endl;
	s.pop();
	cout << s.getMin() << endl;
	s.pop();
	cout << s.getMin() << endl;
	s.pop();
	cout << s.getMin() << endl;
	return 0;
} 
