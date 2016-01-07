#include<stdio.h>
/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

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
int check(char*, char*);
int getyear(char*);


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL||B==NULL)
		return NULL;
	bank res;
	res = (bank)malloc(sizeof(struct transaction)*(ALen + BLen));
	int k = 0,i=0,j=0;
	while (i<ALen&&j<BLen)
	{
		int n = check(A[i].date, B[j].date);
		if (n>0)
		{
			res[k] = A[i];
			i++;
			k++;
		}
		else if (n< 0)
		{
			res[k] = B[j];
			j++;
			k++;
		}
		else
		{
			res[k] = A[i];
			i++;
			k++;
			res[k] = B[j];
			j++;
			k++;
		}
	}
	while (i < ALen)
	{
		res[k] = A[i];
		k++;
		i++;
	}
	while (j < BLen)
	{
		res[k] = B[j];
		j++;
		k++;
	}
	return res;
}

int check(char *date1, char *date2)
{
	int year1 = getyear(date1);
	int year2 = getyear(date2);
	if (year1 < year2)
		return 1;
	else if (year1>year2)
		return -1;
	return 0;
}

int getyear(char *date)
{
	int year=0,k=1;
	for (int i = 9; i >=6; i--)
	{
		year += (date[i] - 48)*k;
		k = k * 10;
	}
	return year;
}