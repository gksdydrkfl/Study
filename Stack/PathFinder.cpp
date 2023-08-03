#include <iostream>

using namespace std;
struct Position
{
    int X;
    int Y;
    int Dir;
};

 struct StackNode
{
	Position Pos;
    StackNode* Next;
};

class MyStack
{
public:
    MyStack();
private:
    StackNode* Head;
    //StackNode* CurNode;
public:

    Position Top();
    Position Pop();
    void Push(const Position& NewPos);
    bool IsEmpty();
    void Clear();
    void Show();
};

MyStack::MyStack()
{
    Head = new StackNode();
}

Position MyStack::Top()
{
    if (!IsEmpty())
    {
        if (Head->Next != nullptr)
        {
            Position Pos = Head->Next->Pos;
            return Pos;
        }
    }
    return Position();
}

Position MyStack::Pop()
{
    if (!IsEmpty())
    {
        if (Head->Next != nullptr)
        {
            StackNode* RemoveNode = Head->Next;
            Head->Next = RemoveNode->Next;
            Position Pos = RemoveNode->Pos;
            delete RemoveNode;
            return Pos;
        }
        //if (CurNode != nullptr)
        //{
        //    StackNode* RemoveNode = CurNode;
        //}
    }
    return Position();
}

void MyStack::Push(const Position& NewPos)
{
    StackNode* NewNode = new StackNode();
    NewNode->Pos = NewPos;
    //if (Head->Next == nullptr)
    //{
    //    Head->Next = NewNode;
    //    CurNode = NewNode;
    //}
    //else
    //{
    //    CurNode->Next = NewNode;
    //    CurNode = NewNode;
    //}
    
    NewNode->Next = Head->Next;
    Head->Next = NewNode;

    //    StackNode* NewNode = new StackNode();
//    NewNode->Data = NewData;
//    NewNode->Next = Head->Next;
//    Head->Next = NewNode;
}

bool MyStack::IsEmpty()
{
    return Head->Next == nullptr ? true : false;
}

void MyStack::Clear()
{
    if (IsEmpty())
    {
        std::cout << "데이터가 없습니다" << std::endl;
        return;
    }

    StackNode* CurrentNode = Head;
    StackNode* RemoveNode = nullptr;

    while (CurrentNode->Next != nullptr)
    {
        RemoveNode = CurrentNode->Next;
        CurrentNode->Next = RemoveNode->Next;

        Position Pos = RemoveNode->Pos;
        std::cout << Pos.X << " " << Pos.Y << "삭제" << std::endl;

        delete RemoveNode;
    }
}

void MyStack::Show()
{
    if (IsEmpty())
    {
        std::cout << "데이터가 없습니다" << std::endl;
        return;
    }

    StackNode* CurrentNode = Head;
    while (CurrentNode->Next != nullptr)
    {
        std::cout << "(" << CurrentNode->Next->Pos.Y << " " << CurrentNode->Next->Pos.X << ")";
        CurrentNode = CurrentNode->Next;
    }
}

const int Width = 10;
const int Height = 10;
int Map[Height][Width] =
{
	0,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,1,1,
	1,1,1,0,1,1,1,1,1,1,
	1,1,1,0,1,1,1,1,0,1,
	1,1,1,0,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,1,1,1,
	0,0,1,1,1,0,0,0,0,1,
	0,1,1,1,1,0,1,1,0,1,
	0,0,0,0,0,0,1,1,0,3
};

int DirectionOffset[4][2] =
{
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
};

MyStack* PathFinder()
{
    MyStack* Stack = new MyStack();

    Position Pos;
    Pos.X = 0;
    Pos.Y = 0;
    Pos.Dir = 0;

    int Dir = Pos.Dir;
    Stack->Push(Pos);

    while (1)
	{   
        Pos = Stack->Top();
        Dir = Pos.Dir;

		while (Dir < 4)
		{
			int NewX = Pos.X + DirectionOffset[Dir][0];
			int NewY = Pos.Y + DirectionOffset[Dir][1];

			if (NewX >= 0 && NewX < Width &&
				NewY >= 0 && NewY < Height &&
				Map[NewY][NewX] != 1 && Map[NewY][NewX] != 2)
			{
				Map[Pos.Y][Pos.X] = 2;

				Pos.X = NewX;
				Pos.Y = NewY;
				Pos.Dir = Dir + 1;
				Stack->Push(Pos);

				Dir = 0;

				if (Pos.X == 9 && Pos.Y == 9)
				{
                    return Stack;
				}
			}
			else
			{
				Dir++;
			}
		}
		Stack->Pop();
	}

    return nullptr;
}

int main()
{
    MyStack* Stack = PathFinder();
    Stack->Show();
}