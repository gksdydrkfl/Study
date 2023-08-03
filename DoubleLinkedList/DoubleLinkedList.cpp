#include <iostream>

class Node
{
public:
	Node();
private:
	int Data;
	Node* Next;
	Node* Prev;
	friend class LinkedList;

public:

	int GetData()
	{
		return Data;
	}
};

class LinkedList
{
public:
	LinkedList();
private:
	Node* Head;
	Node* Tail;

public:

	void Add(const int& NewData);
	Node* Search(const int& Data);
	void Insert(const int& NewData, const int& Index);
	void Remove(Node* InRemoveNode);

	Node* GetNodeAt(const int& Index);
	void Show();
};

int main()
{
	LinkedList* List = new LinkedList();

	if (List != nullptr)
	{
		List->Add(5);
		List->Add(9);
		List->Add(7);
		List->Insert(3, 1);
		std::cout << "==제거 하기전 출력==" << std::endl;
		List->Show();
		Node* RemoveNode = List->Search(9);
		if (RemoveNode != nullptr)
		{
			List->Remove(RemoveNode);
		}
		std::cout << "==제거 후 출력==" << std::endl;
		List->Show();
	}
}

LinkedList::LinkedList()
{
	Head = new Node();
	Tail = new Node();
	Head->Next = Tail;
	Tail->Prev = Head;
}

void LinkedList::Add(const int& NewData)
{
	Node* NewNode = new Node();

	if (NewNode != nullptr)
	{
		NewNode->Data = NewData;
	}
	if (Tail != nullptr)
	{
		NewNode->Prev = Tail->Prev;
		NewNode->Next = Tail;
		Tail->Prev->Next = NewNode;
		Tail->Prev = NewNode;
	}
}

Node* LinkedList::GetNodeAt(const int& Index)
{
	Node* CurrentNode = Head;

	if (CurrentNode != nullptr)
	{
		for (int i = 0; i < Index; ++i)
		{
			if (CurrentNode != nullptr)
			{
				CurrentNode = CurrentNode->Next;
			}
			else
			{
				std::cout << Index << "번째의 노드가 없습니다" << std::endl;
				return nullptr;
			}
		}
		if (CurrentNode != nullptr)
		{
			return CurrentNode;
		}
	}
}

Node* LinkedList::Search(const int& Data)
{
	Node* CurrentNode = Head;

	if (CurrentNode != nullptr)
	{
		while (CurrentNode->Next != Tail)
		{
			if (CurrentNode->Next->Data == Data)
			{
				return CurrentNode->Next;
			}

			CurrentNode = CurrentNode->Next;
		}
		std::cout << "검색 할 노드가 없습니다" << std::endl;
		return nullptr;
	}
	else
	{
		std::cout << "헤드가 없습니다" << std::endl;
		return nullptr;
	}
}

void LinkedList::Insert(const int& NewData, const int& Index)
{
	Node* CurrentNode = Head;

	if (CurrentNode != nullptr)
	{
		for (int i = 0; i < Index; ++i)
		{
			if (CurrentNode != nullptr)
			{
				CurrentNode = CurrentNode->Next;
			}
			else
			{
				std::cout << Index << "번째의 노드가 없습니다" << std::endl;
				return;
			}
		}
	}

	if (CurrentNode == nullptr)
	{
		std::cout << Index << "번째의 노드가 없습니다" << std::endl;
		return;
	}

	Node* NewNode = new Node();
	if (NewNode != nullptr)
	{
		NewNode->Data = NewData;

		CurrentNode->Next->Prev = NewNode;
		NewNode->Next = CurrentNode->Next;
		NewNode->Prev = CurrentNode;
		CurrentNode->Next = NewNode;
	}
}

void LinkedList::Remove(Node* InRemoveNode)
{
	Node* CurrentNode = Head->Next;
	if (CurrentNode != nullptr && InRemoveNode != nullptr)
	{
		if (CurrentNode == InRemoveNode)
		{
			Head->Next = InRemoveNode->Next;
			InRemoveNode->Next->Prev = Head;
		}
		else
		{
			InRemoveNode->Prev->Next = InRemoveNode->Next;
			InRemoveNode->Next->Prev = InRemoveNode->Prev;
		}
		std::cout << InRemoveNode->Data << "제거" << std::endl;
		delete InRemoveNode;
	}
}

void LinkedList::Show()
{
	Node* CurrentNode = Head->Next;

	if (CurrentNode != nullptr)
	{
		while (CurrentNode != Tail)
		{
			std::cout << "현재 : " << CurrentNode->Data << " " << " 이전 : " << CurrentNode->Prev->Data << " 다음 : " << CurrentNode->Next->Data << std::endl;;
			CurrentNode = CurrentNode->Next;
		}
		std::cout << std::endl;
	}
}

Node::Node()
{
	Data = 0;
	Next = nullptr;
	Prev = nullptr;
}
