/*Dequeue is a doubly ended queue
operations/ function of deque in STL
1 size()
2 empty()
3 push_front()
4 push_back()
5 pop_front()
6 pop_back()
7 clear()
etc */

//STACK USING DEQUE
void push(int x)
{
    dq.push_back(x);
}
void pop()
{
    dq.pop_back();
}

//Queue using deque
void push(int x)
{
    dq.push_back(x);
}
void pop()
{
    dq.pop_front();
}
