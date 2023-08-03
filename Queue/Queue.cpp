//#include <iostream>
//
//class MyQueue
//{
//public:
//    MyQueue();
//
//private:
//
//    int Front;
//    int Rear;
//    int Capacity;
//    int* Data;
//
//public:
//
//    void CreateQueue(const int& Size);
//    bool IsEmpty();
//    bool IsFull();
//    int DeQueue();
//    void EnQueue(const int& NewData);
//    int Peek();
//    void Show();
//};
//
//
//int main()
//{
//    MyQueue* Queue = new MyQueue();
//
//    Queue->CreateQueue(5);
//    Queue->EnQueue(1);
//    Queue->EnQueue(2);
//    Queue->EnQueue(3);
//    Queue->EnQueue(4);
//    Queue->EnQueue(5);
//    Queue->DeQueue();
//    Queue->DeQueue();
//    Queue->EnQueue(5);
//    Queue->EnQueue(6);
//    Queue->Show();
//}
//
//int MyQueue::Peek()
//{
//    return IsEmpty() ? -1 : Data[Front + 1];
//}
//
//void MyQueue::Show()
//{
//    for (int i = Front + 1; i != Rear; i = (i + 1) % Capacity)
//    {
//        std::cout << Data[i] << " ";
//    }
//    std::cout << Data[Rear] << " ";
//}
//
//MyQueue::MyQueue()
//{
//    Front = 0;
//    Rear = 0;
//    Capacity = 0;
//    Data = nullptr;
//}
//
//void MyQueue::CreateQueue(const int& Size)
//{
//    Data = new int[Size];
//    Capacity = Size;
//}
//
//bool MyQueue::IsEmpty()
//{
//    return Rear == Front ? true : false;
//}
//
//bool MyQueue::IsFull()
//{
//    return (Rear + 1) % Capacity == Front ? true : false;
//}
//
//int MyQueue::DeQueue()
//{
//    if (IsEmpty())
//    {
//        return -1;
//    }
//    Front = (Front + 1) % Capacity;
//    int Value = Data[Front];
//    return Value;
//}
//
//void MyQueue::EnQueue(const int& NewData)
//{
//    if (!IsFull())
//    {
//        Rear = (Rear + 1) % Capacity;
//        Data[Rear] = NewData;
//    }
//}