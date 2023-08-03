#include <iostream>

int main()
{
    int Array[5] = { 4,3,2,1,5 };

    int Count = 5;

    for (int i = 1; i < Count; ++i)
    {
        int Key = Array[i];
        int j = i - 1;
        while (j >= 0 && Key < Array[j])
        {
            Array[j + 1] = Array[j];
            --j;
        }
        Array[j + 1] = Key;
    }


    for (int i = 0; i < Count; ++i)
    {
        std::cout << Array[i] << " ";
    }
}





//int Array[5] = { 1,2,3,4,5 };


//for (int i = 1; i < Count; ++i)
//{
//    int Key = Array[i];
//    int j = i - 1;
//    while (j >= 0 && Key < Array[j])
//    {
//        Array[j + 1] = Array[j];
//        --j;
//    }
//    Array[j] = Key;
//}
