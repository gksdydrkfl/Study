#include<iostream>

int main()
{
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int S[10] = {};

	S[0] = A[0];
	std::cout << S[0] << " ";
	for (int i = 1; i < 10; ++i)
	{
		S[i] = S[i  - 1] + A[i];
		std::cout << S[i] << " ";
	}

	std::cout << std::endl;
	// 1 ~ 4 에서 부분합
	// PrefixSum = 14
	int PrefixSum = S[4] - S[1 - 1];
	std::cout << PrefixSum << std::endl;

	// 2 ~ 7 에서 부분합
	// PrefixSum = 33
	PrefixSum = S[7] - S[2 - 1];
	std::cout << PrefixSum;
}