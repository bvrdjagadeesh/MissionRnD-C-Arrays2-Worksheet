/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
typedef struct transaction *bank;
bool check(char*, char*);
int length(char*);
int min(int, int);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL||B==NULL)
		return NULL;
	int k[5];
	int n=0;
	for (int i = 0; i < ALen; i++)
	{
		for (int j = 0; j < BLen; j++)
		{
			if (A[i].amount == B[j].amount)
			{
				if (check(A[i].description, B[j].description))
				{
					if (check(A[i].date, B[j].date))
					{
						k[n] = i;
						n++;
					}
				}
			}
		}
	}
	if (n != 0)
	{
		bank res;
		res = (bank)malloc(sizeof(struct transaction)*n);
		for (int i = 0; i < n; i++)
		{
			res[i] = A[i];
		}
		return res;
	}
	else
		return NULL;
}
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
bool check(char *s1, char *s2)
{
	for (int i = 0; i < length(s1); i++)
	{
		if (s1[i] != s2[i])
			return false;
	}
	return true;
}

int length(char *s)
{
	int i;
	for (i = 0;s[i] != '\0'; ++i);
	return i;
}