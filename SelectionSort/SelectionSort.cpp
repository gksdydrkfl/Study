#include <iostream>

int main()
{
    int Array[5] = { 4,3,2,1,5 };

    int Count = 5;

    int Index = 0;

    for (int i = 0; i < Count; ++i)
    {
        Index = i;
        for (int j = i + 1; j < Count; ++j)
        {
            if (Array[Index] > Array[j])
            {
                Index = j;
            }
        }
        int Temp = Array[Index];
        Array[Index] = Array[i];
        Array[i] = Temp;
    }


    for (int i = 0; i < Count; ++i)
    {
        std::cout << Array[i] << " ";
    }
}