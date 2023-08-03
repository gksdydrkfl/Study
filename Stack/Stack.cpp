//#include <iostream>
//class MyStack
//{
//public:
//    MyStack();
//private:
//
//    int Capacity;
//    int* Data;
//    int Top;
//
//public:
//
//    int Pop();
//    void Push(const int& NewData);
//    bool IsEmpty();
//    void Create(const int& Size);
//    bool IsFull();
//    void Show();
//};
//
//int main()
//{
//    MyStack* Stack = new MyStack();
//    Stack->Create(5);
//    Stack->Pop();
//    Stack->Push(1);
//    Stack->Push(2);
//    Stack->Pop();
//    Stack->Push(3);
//    Stack->Push(4);
//    Stack->Push(5);
//    Stack->Push(6);
//    Stack->Show();
//}
//
//MyStack::MyStack()
//{
//    Capacity = 0;
//    Data = nullptr;
//    Top = -1;
//}
//
//int MyStack::Pop()
//{
//    if (!IsEmpty())
//    {
//        return Data[Top--];
//    }
//    std::cout << "꺼낼 데이터가 없습니다" << std::endl;
//    return -1;
//}
//
//void MyStack::Push(const int& NewData)
//{
//    if (!IsFull())
//    {
//        Data[++Top] = NewData;
//    }
//    else
//    {
//        std::cout << "데이터가 꽉 차 있습니다." << std::endl;
//    }
//}
//
//bool MyStack::IsEmpty()
//{
//    return Top == -1 ? true : false;
//}
//
//void MyStack::Create(const int& Size)
//{
//    Capacity = Size;
//    Data = new int[Capacity];
//}
//
//bool MyStack::IsFull()
//{
//    return Top == Capacity - 1 ? true : false;
//}
//
//void MyStack::Show()
//{
//    for (int i = 0; i <= Top; ++i)
//    {
//        std::cout << Data[i] << std::endl;
//    }
//}
