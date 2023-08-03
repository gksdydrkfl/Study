#include <iostream>

int main()
{
    int Array[5] = { 4,3,2,1,5 };

    int Count = 5;

    for (int i = 0; i < Count - 1; ++i)
    {
        for (int j = 0; j < Count - 1; ++j)
        {
            if (Array[j] > Array[j + 1])
            {
                int Temp = Array[j + 1];
                Array[j + 1] = Array[j];
                Array[j] = Temp;
            }
        }
    }

    for (int i = 0; i < Count; ++i)
    {
        std::cout << Array[i] << " ";
    }
}
