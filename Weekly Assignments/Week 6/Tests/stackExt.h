# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
    stack<T> normal;
    stack<T> minimum;
public:
	StackExt() {};
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();
};

// a alterar
template <class T> 
bool StackExt<T>::empty() const
{
    return normal.empty();
}

//a alterar
template <class T> 
T& StackExt<T>::top()
{
    return normal.top();
}

//a alterar
template <class T> 
void StackExt<T>::pop()
{
    normal.pop();
}

//a alterar
template <class T> 
void StackExt<T>::push(const T & val)
{
    normal.push(val);
}

//a alterar
template <class T> 
T& StackExt<T>::findMin()
{
    stack<T> new_stack = normal;
    for (int i = 0 ; i < normal.size(); i++)
    {
        if(normal.top() < minimum.top())
        {
            minimum.pop();
            minimum.push(normal.top());
        }
        normal.pop();
    }
    normal = new_stack;
    return minimum.top();
}

