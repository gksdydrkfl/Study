#include <iostream>

struct Node
{
    int Data;
    Node* Next;
};

class MyQueue
{
public:
    MyQueue();

private:

    Node* Front;
    Node* Rear;
    int Capacity;

public:

    bool IsEmpty();
    int DeQueue();
    void EnQueue(const int& NewData);
    Node* Peek();
    void Show();
};


int main()
{
    MyQueue* Queue = new MyQueue();

    Queue->EnQueue(1);
    Queue->EnQueue(2);
    Queue->EnQueue(3);
    Queue->EnQueue(4);
    Queue->EnQueue(5);
    Queue->DeQueue();
    Queue->DeQueue();
    Queue->EnQueue(6);
    Queue->EnQueue(7);
    Queue->Show();
}

Node* MyQueue::Peek()
{
    return IsEmpty() ? nullptr : Front;
}

void MyQueue::Show()
{
    //for (int i = Front + 1; i != Rear; i = (i + 1) % Capacity)
    //{
    //    std::cout << Data[i] << " ";
    //}
    //std::cout << Data[Rear] << " ";
    Node* Node = Front;
    while (Node != nullptr)
    {
        std::cout << Node->Data << " ";
        Node = Node->Next;
    }
}

MyQueue::MyQueue()
{
    Front = nullptr;
    Rear = nullptr;
    Capacity = 0;
}

bool MyQueue::IsEmpty()
{
    return Rear == nullptr ? true : false;
}

int MyQueue::DeQueue()
{
    if (IsEmpty())
    {
        return -1;
    }

    int Value = Front->Data;

    Node* RemoveNode = Front;
    Front = Front->Next;
    delete RemoveNode;
    return Value;
}

void MyQueue::EnQueue(const int& NewData)
{
    Node* NewNode = new Node();
    NewNode->Data = NewData;

    if (Front == nullptr)
    {
        Front = Rear = NewNode;
    }

    Rear->Next = NewNode;
    Rear = NewNode;
}