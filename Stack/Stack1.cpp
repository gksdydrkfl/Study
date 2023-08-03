//#include <iostream>
// struct StackNode
//{
//    int Data;
//    StackNode* Next;
//};
//
//class MyStack
//{
//public:
//    MyStack();
//private:
//    StackNode* Head;
//
//public:
//
//    int Pop();
//    void Push(const int& NewData);
//    bool IsEmpty();
//    void Clear();
//    void Show();
//};
//
//int main()
//{
//    MyStack* Stack = new MyStack();
//    Stack->Push(1);
//    Stack->Push(2);
//    Stack->Push(3);
//    Stack->Pop();
//    Stack->Show();
//    Stack->Clear();
//}
//
//MyStack::MyStack()
//{
//    Head = new StackNode();
//}
//
//int MyStack::Pop()
//{
//    if (!IsEmpty())
//    {
//        if (Head->Next != nullptr)
//        {
//            StackNode* RemoveNode = Head->Next;
//            Head->Next = RemoveNode->Next;
//            int Data = RemoveNode->Data;
//            delete RemoveNode;
//            return Data;
//        }
//    }
//    return -1;
//}
//
//void MyStack::Push(const int& NewData)
//{
//    StackNode* NewNode = new StackNode();
//    NewNode->Data = NewData;
//    NewNode->Next = Head->Next;
//    Head->Next = NewNode;
//}
//
//bool MyStack::IsEmpty()
//{
//    return Head->Next == nullptr ? true : false;
//}
//
//void MyStack::Clear()
//{
//    if (IsEmpty())
//    {
//        std::cout << "데이터가 없습니다" << std::endl;
//        return;
//    }
//
//    StackNode* CurrentNode = Head;
//    StackNode* RemoveNode = nullptr;
//
//    while (CurrentNode->Next != nullptr)
//    {
//        RemoveNode = CurrentNode->Next;
//        CurrentNode->Next = RemoveNode->Next;
//
//        int Data = RemoveNode->Data;
//        std::cout << Data << "삭제" << std::endl;
//
//        delete RemoveNode;
//    }
//}
//
//void MyStack::Show()
//{
//    if (IsEmpty())
//    {
//        std::cout << "데이터가 없습니다" << std::endl;
//        return;
//    }
//
//    StackNode* CurrentNode = Head;
//    while (CurrentNode->Next != nullptr)
//    {
//        std::cout << CurrentNode->Next->Data << std::endl;
//        CurrentNode = CurrentNode->Next;
//    }
//}
