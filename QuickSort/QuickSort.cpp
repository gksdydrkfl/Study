#include <iostream>

void QuickSort(int Arr[], int Start, int End)
{
    int Left = Start + 1;
    int Right = End;
    int Pivot = Start;


    while (Left <= Right)
    {
        while (Arr[Left] < Arr[Pivot] && Left < Right)
        {
            Left++;
        }
        while (Arr[Right] > Arr[Pivot] && Left <= Right)
        {
            Right--;
        }

        if (Left < Right)
        {
            int Temp = Arr[Left];
            Arr[Left] = Arr[Right];
            Arr[Right] = Temp;
        }
        else
        {
            int Temp = Arr[Start];
            Arr[Start] = Arr[Right];
            Arr[Right] = Temp;

            break;
        }
    }


    if (Start < End)
    {
        QuickSort(Arr, Start, Right - 1);
        QuickSort(Arr, Right + 1, End);
    }
    
}

int main()
{
    int N[10] = { 5,7,1,2,8,4,6,9,3, 5};
    //int N[8] = { 80,50,70,10,60,20,40,30 };

    int Start = 0;
    int End = 9;

    QuickSort(N, Start, End);

    for (int i = 0; i < 10; ++i)
    {
        std::cout << N[i] << " ";
    }
}