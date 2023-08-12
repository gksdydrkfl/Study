#include <iostream>

void QuickSort(int Arr[], int Left, int Right)
{
    int Start = Left;

    while (Start < End)
    {
        while (N[Start] < Pivot && Start < End)
        {
            ++Start;
        }
        while (N[End] < Pivot && Start < End)
        {
            --End;
        }

        int Temp = N[Start];
        N[Start] = N[End];
        N[End] = Temp;

        QuickSort(&Arr, Start, End);
    }
}

int main()
{
    int N[10] = { 5,7,1,2,8,4,6,9,3, 10 };

    int Pivot = N[4];

    int Start = 0;
    int End = 9;



    


}
