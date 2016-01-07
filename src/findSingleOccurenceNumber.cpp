/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include <iostream>

int findSingleOccurenceNumber(int *A, int len) {
	if (A==NULL)
		return -1;
	int n;
	for (int i = 0; i < len; i++)
	{
		n = A[i];
		int k = 0;
		for (int j = 0; j < len; j++)
		{
			if (i == j)
				continue;
			else
			{
				if (A[i] == A[j])
					break;
				else
					k++;
			}
		}
		if (k == len - 1)
			return n;
	}
}