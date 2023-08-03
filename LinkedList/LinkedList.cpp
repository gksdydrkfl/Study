#include <iostream>

class Node
{
public:
	Node();
private:
	int Data;
	Node* Next;
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
	bool Search(const int& Data);
	void Insert(const int& NewData, const int& Index);
	void Remove(const int& Data);

	Node* GetNodeAt(const int& Index);
	void Show();
};

int main()
{
	LinkedList* List = new LinkedList();

	if (List != nullptr)
	{
		List->Add(5);
		List->Add(8);
		List->Add(1);
		List->Insert(10, 2);
		List->Search(11);
		List->Remove(8);
		List->Remove(55);
		List->Show();
	}
}

LinkedList::LinkedList()
{
	Head = new Node();
	Tail = new Node();
}

void LinkedList::Add(const int& NewData)
{
	Node* NewNode = new Node();

	if (NewNode != nullptr)
	{
		NewNode->Data = NewData;
	}

	if (Head->Next != nullptr)
	{
		Node* CurrentNode = Head;

		if (CurrentNode != nullptr)
		{
			while (CurrentNode->Next != Tail)
			{
				CurrentNode = CurrentNode->Next;
			}

			CurrentNode->Next = NewNode;
			NewNode->Next = Tail;
		}
	}
	else
	{
		Head->Next = NewNode;
		NewNode->Next = Tail;
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

bool LinkedList::Search(const int& Data)
{
	Node* CurrentNode = Head;

	if (CurrentNode != nullptr)
	{
		while (CurrentNode->Next != Tail)
		{
			if (CurrentNode->Next->Data == Data)
			{
				return true;
			}

			CurrentNode = CurrentNode->Next;
		}
		std::cout << "검색 할 노드가 없습니다" << std::endl;
		return false;
	}
	else
	{
		std::cout << "헤드가 없습니다" << std::endl;
		return false;
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
		NewNode->Next = CurrentNode->Next;
		CurrentNode->Next = NewNode;
	}
}

void LinkedList::Remove(const int& Data)
{
	Node* CurrentNode = Head;

	if (CurrentNode != nullptr)
	{
		while (CurrentNode->Next != Tail)
		{
			if (CurrentNode->Next->GetData() == Data)
			{
				Node* RemoveNode = CurrentNode->Next;
				CurrentNode->Next = CurrentNode->Next->Next;
				std::cout << RemoveNode->GetData() << std::endl;
				delete RemoveNode;
				return;
			}
			CurrentNode = CurrentNode->Next;
		}
		std::cout << Data << "가 리스트에 존재하지 않습니다" << std::endl;
	}
}

void LinkedList::Show()
{
	Node* CurrentNode = Head->Next;

	if (CurrentNode != nullptr)
	{
		while (CurrentNode != Tail)
		{
			std::cout << CurrentNode->Data << " ";
			CurrentNode = CurrentNode->Next;
		}
		std::cout << std::endl;
	}
}

Node::Node()
{
	Data = 0;
	Next = nullptr;
}
