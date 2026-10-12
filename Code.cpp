#include <iostream>
using namespace std;


// array stack
class ArrayStack
{
    // fixed size array to hold the values
    int arr[10];
    // index of the top element, -1 means empty
    int top;
public:
    // start empty
    ArrayStack()
    {
        top = -1;
    }

    void push(int v)
    {
        // if array is full
        if (top >= 9)
        {
            cout << "stack full" << endl;
            return;
        }
        // move top up
        top = top + 1;
        // put value at new top
        arr[top] = v;
    }

    int pop()
    {
        // if empty
        if (top == -1)
        {
            // return -1 to show error
            return -1;
        }
        // save the top value
        int r = arr[top];
        // move top down
        top = top - 1;
        // return the saved value
        return r;
    }

    int peek()
    {
        // if empty
        if (top == -1)
        {
            return -1;
        }
        // just look at top without removing
        return arr[top];
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // top starts at -1 so add 1
    int getSize()
    {
        return top + 1;
    }

    void show()
    {
        // if empty
        if (top == -1)
        {
            cout << "[empty]";
            return;
        }
        // print from top to bottom
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }
};

// linked stack
class LinkedStack
{
    // one node in the linked list
    struct Node
    {
        // the data
        int val;
        // pointer to next node
        Node* next;
    };

    // points to the top of the stack
    Node* head;
public:
    // start with no nodes
    LinkedStack()
    {
        head = nullptr;
    }

    // destructor, frees all memory
    ~LinkedStack()
    {
        while (head)
        {
            // save current node
            Node* t = head;
            // move to next
            head = head->next;
            // free the saved one
            delete t;
        }
    }

    void push(int v)
    {
        // make a new node
        Node* n = new Node;
        // set its data
        n->val = v;
        // point it to current head
        n->next = head;
        // new node becomes head
        head = n;
    }

    int pop()
    {
        // if empty
        if (!head)
        {
            return -1;
        }
        // save the top node
        Node* t = head;
        // save its value
        int r = t->val;
        // move head to next
        head = t->next;
        // free the old top
        delete t;
        return r;
    }

    int peek()
    {
        // if empty
        if (!head)
        {
            return -1;
        }
        // just look at top value
        return head->val;
    }

    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void show()
    {
        // if empty
        if (!head)
        {
            cout << "[empty]";
            return;
        }
        // start at top
        Node* cur = head;
        // go through each node
        while (cur)
        {
            cout << cur->val << " ";
            // move to next
            cur = cur->next;
        }
    }
};

// array queue (shifts left on dequeue, so O(n))
class ArrayQueue
{
    // fixed size array
    int arr[10];
    // index of front element
    int front;
    // index one past the last element
    int back;
public:
    ArrayQueue()
    {
        front = 0;
        back = 0;
    }

    void enqueue(int v)
    {
        // if full
        if (back - front >= 10)
        {
            cout << "queue full" << endl;
            return;
        }
        // put value at back
        arr[back] = v;
        // move back forward
        back = back + 1;
    }

    int dequeue()
    {
        // if empty
        if (front == back)
        {
            return -1;
        }
        // save front value
        int r = arr[front];
        // shift everything left by 1
        for (int i = front; i < back - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        // shrink by 1
        back = back - 1;
        return r;
    }

    int peek()
    {
        // if empty
        if (front == back)
        {
            return -1;
        }
        // look at front without removing
        return arr[front];
    }

    bool isEmpty()
    {
        if (front == back)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {
        return back - front;
    }

    void show()
    {
        // if empty
        if (front == back)
        {
            cout << "[empty]";
            return;
        }
        // print front to back
        for (int i = front; i < back; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

// linked queue
class LinkedQueue
{
    struct Node
    {
        int val;
        Node* next;
    };

    // points to front of queue
    Node* front;
    // points to back of queue
    Node* back;
public:
    LinkedQueue()
    {
        front = nullptr;
        back = nullptr;
    }

    // free all nodes
    ~LinkedQueue()
    {
        while (front)
        {
            Node* t = front;
            front = t->next;
            delete t;
        }
    }

    void enqueue(int v)
    {
        // make new node
        Node* n = new Node;
        // set data
        n->val = v;
        // new node is last
        n->next = nullptr;
        // if queue was empty
        if (!front)
        {
            // set front too
            front = n;
        }
        else
        {
            // link after current back
            back->next = n;
        }
        // new node is now back
        back = n;
    }

    int dequeue()
    {
        // if empty
        if (!front)
        {
            return -1;
        }
        // save front node
        Node* t = front;
        // save its value
        int r = t->val;
        // move front forward
        front = t->next;
        // if we removed the last one
        if (!front)
        {
            back = nullptr;
        }
        // free old front
        delete t;
        return r;
    }

    int peek()
    {
        // if empty
        if (!front)
        {
            return -1;
        }
        return front->val;
    }

    bool isEmpty()
    {
        if (front == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void show()
    {
        // if empty
        if (!front)
        {
            cout << "[empty]";
            return;
        }
        // start at front
        Node* cur = front;
        // go through each node
        while (cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
    }
};

// array deque (shifts for front ops, so O(n))
class ArrayDeque
{
    // fixed size array
    int arr[10];
    // number of elements in the deque
    int back;
public:
    // start empty
    ArrayDeque()
    {
        back = 0;
    }

    void pushFront(int v)
    {
        // if full
        if (back >= 10)
        {
            cout << "deque full" << endl;
            return;
        }
        // shift everything right by 1 to make room
        for (int i = back; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        // put new value at front
        arr[0] = v;
        // one more element
        back = back + 1;
    }

    void pushBack(int v)
    {
        // if full
        if (back >= 10)
        {
            cout << "deque full" << endl;
            return;
        }
        // put value at end
        arr[back] = v;
        back = back + 1;
    }

    int popFront()
    {
        // if empty
        if (back == 0)
        {
            return -1;
        }
        // save front value
        int r = arr[0];
        // shift everything left by 1
        for (int i = 0; i < back - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        back = back - 1;
        return r;
    }

    int popBack()
    {
        // if empty
        if (back == 0)
        {
            return -1;
        }
        // shrink
        back = back - 1;
        // return the last element
        return arr[back];
    }

    int peekFront()
    {
        // if empty
        if (back == 0)
        {
            return -1;
        }
        return arr[0];
    }

    int peekBack()
    {
        // if empty
        if (back == 0)
        {
            return -1;
        }
        return arr[back - 1];
    }

    bool isEmpty()
    {
        if (back == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {
        return back;
    }

    void show()
    {
        // if empty
        if (back == 0)
        {
            cout << "[empty]";
            return;
        }
        // print front to back
        for (int i = 0; i < back; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

// linked deque (doubly linked, all O(1))
class LinkedDeque
{
    struct Node
    {
        int val;
        // pointer to previous node
        Node* prev;
        // pointer to next node
        Node* next;
    };

    // points to front
    Node* front;
    // points to back
    Node* back;
public:
    LinkedDeque()
    {
        front = nullptr;
        back = nullptr;
    }

    // free all nodes
    ~LinkedDeque()
    {
        while (front)
        {
            Node* t = front;
            front = t->next;
            delete t;
        }
    }

    void pushFront(int v)
    {
        // make new node
        Node* n = new Node;
        // set data
        n->val = v;
        // new node has no prev
        n->prev = nullptr;
        // point to current front
        n->next = front;
        if (front)
        {
            // old front now points back to new
            front->prev = n;
        }
        else
        {
            // was empty so set back too
            back = n;
        }
        // new node is now front
        front = n;
    }

    void pushBack(int v)
    {
        // make new node
        Node* n = new Node;
        // set data
        n->val = v;
        // new node has no next
        n->next = nullptr;
        // point to current back
        n->prev = back;
        if (back)
        {
            // old back now points forward to new
            back->next = n;
        }
        else
        {
            // was empty so set front too
            front = n;
        }
        // new node is now back
        back = n;
    }

    int popFront()
    {
        // if empty
        if (!front)
        {
            return -1;
        }
        // save front node
        Node* t = front;
        // save its value
        int r = t->val;
        // move front forward
        front = t->next;
        if (front)
        {
            // new front has no prev
            front->prev = nullptr;
        }
        else
        {
            // removed last node
            back = nullptr;
        }
        delete t;
        return r;
    }

    int popBack()
    {
        // if empty
        if (!back)
        {
            return -1;
        }
        // save back node
        Node* t = back;
        // save its value
        int r = t->val;
        // move back backward
        back = t->prev;
        if (back)
        {
            // new back has no next
            back->next = nullptr;
        }
        else
        {
            // removed last node
            front = nullptr;
        }
        delete t;
        return r;
    }

    int peekFront()
    {
        // if empty
        if (!front)
        {
            return -1;
        }
        return front->val;
    }

    int peekBack()
    {
        // if empty
        if (!back)
        {
            return -1;
        }
        return back->val;
    }

    bool isEmpty()
    {
        if (front == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void show()
    {
        // if empty
        if (!front)
        {
            cout << "[empty]";
            return;
        }
        // start at front
        Node* cur = front;
        // go through each node
        while (cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
    }
};

int main()
{
    // array stack demo
    cout << "===== ARRAY STACK =====" << endl;
    // make a stack
    ArrayStack s;
    // check if empty first
    if (s.isEmpty())
    {
        cout << "Pop: passed" << endl;
    }
    // add 3 items
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top -> ";
    s.show();
    cout << endl;
    // add one more
    s.push(40);
    // remove top
    cout << "Popped: " << s.pop() << endl;
    cout << "Top -> ";
    s.show();
    cout << endl;
    // remove rest
    s.pop();
    s.pop();
    s.pop();
    // check empty again
    if (s.isEmpty())
    {
        cout << "Pop: passed" << endl;
    }
    cout << "Top -> ";
    s.show();
    cout << endl;

    // linked stack demo
    cout << "===== LINKED STACK =====" << endl;
    LinkedStack ls;
    if (ls.isEmpty())
    {
        cout << "Pop: passed" << endl;
    }
    ls.push(100);
    ls.push(200);
    ls.push(300);
    cout << "Top -> ";
    ls.show();
    cout << endl;
    ls.push(400);
    cout << "Popped: " << ls.pop() << endl;
    cout << "Top -> ";
    ls.show();
    cout << endl;
    ls.pop();
    ls.pop();
    ls.pop();
    if (ls.isEmpty())
    {
        cout << "Pop: passed" << endl;
    }
    cout << "Top -> ";
    ls.show();
    cout << endl;

    // array queue demo
    cout << "===== ARRAY QUEUE =====" << endl;
    ArrayQueue q;
    if (q.isEmpty())
    {
        cout << "Dequeue: passed" << endl;
    }
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front -> ";
    q.show();
    cout << " <- Back" << endl;
    q.enqueue(40);
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front -> ";
    q.show();
    cout << " <- Back" << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    if (q.isEmpty())
    {
        cout << "Dequeue: passed" << endl;
    }
    cout << "Front -> ";
    q.show();
    cout << " <- Back" << endl;

    // linked queue demo
    cout << "===== LINKED QUEUE =====" << endl;
    LinkedQueue lq;
    if (lq.isEmpty())
    {
        cout << "Dequeue: passed" << endl;
    }
    lq.enqueue(100);
    lq.enqueue(200);
    lq.enqueue(300);
    cout << "Front -> ";
    lq.show();
    cout << " <- Back" << endl;
    lq.enqueue(400);
    cout << "Dequeued: " << lq.dequeue() << endl;
    cout << "Front -> ";
    lq.show();
    cout << " <- Back" << endl;
    lq.dequeue();
    lq.dequeue();
    lq.dequeue();
    if (lq.isEmpty())
    {
        cout << "Dequeue: passed" << endl;
    }
    cout << "Front -> ";
    lq.show();
    cout << " <- Back" << endl;

    // array deque demo
    cout << "===== ARRAY DEQUE =====" << endl;
    ArrayDeque d;
    if (d.isEmpty())
    {
        cout << "Pop front: passed" << endl;
    }
    d.pushBack(10);
    d.pushBack(20);
    d.pushFront(5);
    cout << "Front -> ";
    d.show();
    cout << " <- Back" << endl;
    d.pushFront(1);
    cout << "Popped front: " << d.popFront() << endl;
    cout << "Front -> ";
    d.show();
    cout << " <- Back" << endl;
    d.popBack();
    d.popBack();
    d.popBack();
    if (d.isEmpty())
    {
        cout << "Pop back: passed" << endl;
    }
    cout << "Front -> ";
    d.show();
    cout << " <- Back" << endl;

    // linked deque demo
    cout << "===== LINKED DEQUE =====" << endl;
    LinkedDeque ld;
    if (ld.isEmpty())
    {
        cout << "Pop front: passed" << endl;
    }
    ld.pushBack(100);
    ld.pushBack(200);
    ld.pushFront(50);
    cout << "Front -> ";
    ld.show();
    cout << " <- Back" << endl;
    ld.pushFront(10);
    cout << "Popped front: " << ld.popFront() << endl;
    cout << "Front -> ";
    ld.show();
    cout << " <- Back" << endl;
    ld.popBack();
    ld.popBack();
    ld.popBack();
    if (ld.isEmpty())
    {
        cout << "Pop back: passed" << endl;
    }
    cout << "Front -> ";
    ld.show();
    cout << " <- Back" << endl;

    return 0;
}