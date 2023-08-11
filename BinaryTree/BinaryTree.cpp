#include <iostream>

class BinaryTree
{
public:
    BinaryTree();

private:

    BinaryTree* Left;
    BinaryTree* Right;

    char Ch;
public:
    char GetCh() const
    {
        return Ch;
    }
    BinaryTree* GetLeft() const
    {
        return Left;
    }
    BinaryTree* GetRight() const
    {
        return Right;
    }
    void SetCh(const char& Char)
    {
        Ch = Char;
    }
    void SetLeft(BinaryTree* InTree)
    {
        Left = InTree;
    }
    void SetRight(BinaryTree* InTree)
    {
        Right = InTree;
    }
};

void PreOrder(BinaryTree* Tree);
void PostOrder(BinaryTree* Tree);
void InerOrder(BinaryTree* Tree);

int main()
{

    BinaryTree* TreeA = new BinaryTree();
    BinaryTree* TreeB = new BinaryTree();
    BinaryTree* TreeC = new BinaryTree();
    BinaryTree* TreeD = new BinaryTree();
    BinaryTree* TreeE = new BinaryTree();
    BinaryTree* TreeF = new BinaryTree();
    BinaryTree* TreeG = new BinaryTree();

    TreeA->SetCh('A');
    TreeB->SetCh('B');
    TreeC->SetCh('C');
    TreeD->SetCh('D');
    TreeE->SetCh('E');
    TreeF->SetCh('F');
    TreeG->SetCh('G');

    TreeA->SetLeft(TreeB);
    TreeA->SetRight(TreeE);
    TreeB->SetLeft(TreeC);
    TreeB->SetRight(TreeD);
    TreeE->SetLeft(TreeF);
    TreeE->SetRight(TreeG);

    //PreOrder(TreeA);
    //InerOrder(TreeA);
    PostOrder(TreeA);

}

BinaryTree::BinaryTree()
{
}

void PreOrder(BinaryTree* Tree)
{
    if (Tree == nullptr)
    {
        return;
    }

    std::cout << Tree->GetCh() << " ";
    PreOrder(Tree->GetLeft());
    PreOrder(Tree->GetRight());
}

void PostOrder(BinaryTree* Tree)
{
    if (Tree == nullptr)
    {
        return;
    }

    PostOrder(Tree->GetLeft());
    PostOrder(Tree->GetRight());
    std::cout << Tree->GetCh() << " ";
}

void InerOrder(BinaryTree* Tree)
{
    if (Tree == nullptr)
    {
        return;
    }

    InerOrder(Tree->GetLeft());
    std::cout << Tree->GetCh() << " ";
    InerOrder(Tree->GetRight());
}
