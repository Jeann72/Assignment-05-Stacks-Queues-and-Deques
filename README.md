# Assignment-05-Stacks-Queues-and-Deques

# Structure: ArrayStack

0(1) operations:
Push
Pop
Peek
isEmpty
getSize

O(n) operations:
none

Why:
Just reading and writing one index

# Structure: LinkedStack

0(1) operations:
Push
Pop
Peek
isEmpty

O(n) operations:
none

Why:
Just moving the head pointer

# Structure: ArrayQueue
+0(1) operations:
Enqueue
Peek
isEmpty
getSize

O(n) operations:
dequeue

Why:
Has to shift every element left to fill the gap

# Structure: LinkedQueue
+0(1) operations:
Enqueue
Dequeue
Peek
isEmpty

O(n) operations:
none

Why:
Front and back pointers, no shifting


# Structure: ArrayDeque

0(1) operations:
PushBack
popBack
PeekFront
PeekBack
isEmpty
getSize

O(n) operations:
pushFront,popFront

Why:
Front ops shift every element to make room

# Structure: LinkedDeque

0(1) operations:
PushFront
pushBack
popFront
popBack
peekFront
peekBack
isEmpty

O(n) operations:
none

Why
Doubly linked, both ends reachable directly


