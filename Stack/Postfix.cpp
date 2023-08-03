//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <cctype>
//
//int GetStackPriority(const char& StackTopData);
//int GetInFixPriority(const char& StackTopData);
//
//using namespace std;
//
// struct StackNode
//{
//    char Data;
//    StackNode* Next;
//};
//
//class MyStack
//{
//public:
//    MyStack();
//private:
//    StackNode* Head;
//public:
//
//    char Top();
//    char Pop();
//    void Push(const char& NewData);
//    bool IsEmpty();
//    void Clear();
//    void Show();
//};
//
//MyStack::MyStack()
//{
//    Head = new StackNode();
//}
//
//char MyStack::Top()
//{
//    if (!IsEmpty())
//    {
//        if (Head->Next != nullptr)
//        {
//            char Data = Head->Next->Data;
//            return Data;
//        }
//    }
//    return -1;
//}
//
//char MyStack::Pop()
//{
//    if (!IsEmpty())
//    {
//        if (Head->Next != nullptr)
//        {
//            StackNode* RemoveNode = Head->Next;
//            Head->Next = RemoveNode->Next;
//            char Data = RemoveNode->Data;
//            delete RemoveNode;
//            return Data;
//        }
//    }
//    return -1;
//}
//
//void MyStack::Push(const char& NewData)
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
//
//string GetPostfix(const string& InfixExpression)
//{
//	int InfixLength = InfixExpression.length();
//	
//	string PostfixExpression;
//
//    MyStack* Stack = new MyStack();
//
//	for (int i = 0; i < InfixLength; ++i)
//	{
//		if (InfixExpression[i] == ' ')
//		{
//			continue;
//		}
//		char Ch = InfixExpression[i];
//
//		int CheckCh = isdigit(Ch);
//
//		if (CheckCh > 0 || Ch == '.')
//		{
//			PostfixExpression.append(1, Ch);
//		}
//		else
//		{
//            if (!Stack->IsEmpty())
//            {
//                if (Ch == ')')
//                {
//                    while (Stack->Top() != '(')
//                    {
//                        PostfixExpression.append(1, Stack->Pop());
//                    }
//                    Stack->Pop();
//                    continue;
//                }
//
//                char StackPopCh = Stack->Top();
//                int InFixPriority = GetInFixPriority(Ch);
//                int StackPriority = GetStackPriority(StackPopCh);
//
//                if (InFixPriority < StackPriority)
//                {
//                    PostfixExpression.append(1, Stack->Pop());
//                }
//            }
//            Stack->Push(Ch);
//		}
//	}
//
//    while (!Stack->IsEmpty())
//    {
//        PostfixExpression.append(1, Stack->Pop());
//    }
//
//	return PostfixExpression;
//}
//
//int GetStackPriority(const char& StackTopData)
//{
//    switch (StackTopData)
//    {
//    case '(':
//        return 0;
//    case ')':
//        return 4;
//    case '*':
//    case '/':
//        return 2;
//    case '+':
//    case '-':
//        return 1;
//    }
//}
//int GetInFixPriority(const char& StackTopData)
//{
//    switch (StackTopData)
//    {
//    case '(':
//        return 5;
//    case ')':
//        return 4;
//    case '*':
//    case '/':
//        return 2;
//    case '+':
//    case '-':
//        return 1;
//    }
//}
//
//// 3+4*5
//// 345*+
//
//double Calc(const string PostfixExpression)
//{
//    int Value = -1;
//
//    MyStack* Stack = new MyStack();
//
//    int PostfixLength = PostfixExpression.length();
//
//    for (int i = 0; i < PostfixLength; ++i)
//    {
//        char Ch = PostfixExpression[i];
//
//        int CheckCh = isdigit(Ch);
//
//        if (CheckCh > 0 || Ch == '.')
//        {
//            Stack->Push(Ch);
//        }
//        else
//        {
//            if (!Stack->IsEmpty())
//            {
//                int Value1 = (int)Stack->Pop() - 48;
//                int Value2 = (int)Stack->Pop() - 48;
//                switch (Ch)
//                {
//                case '+':
//                    Value = Value2 + Value1;
//                    break;
//                case '-':
//                    Value = Value2 - Value1;
//                    break;
//                case '*':
//                    Value = Value2 * Value1;
//                    break;
//                case '/':
//                    Value = Value2 / Value1;
//                    break;
//                }
//
//                Stack->Push(char(Value + 48));
//            }
//        }
//    }
//
//    return Value;
//}
//
//int main()
//{
//    string Str;
//    cin >> Str;
//    string Postfix = GetPostfix(Str);
//    cout << Postfix << endl;
//    double Value = Calc(Postfix);
//    cout << Value << endl;
//
//}
//
