#include<stdio.h>
#include<stdbool.h>
/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
typedef struct transaction bank;
bool checkdate(char*, char*);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int count = 0,c=0;
	for (int i = 0; i < len; i++)
	{
		if (checkdate(Arr[i].date,date))
			c++;
		if (!(checkdate(Arr[i].date,date)) && c != 0)
		{
			count++;
		}
	}
	if (count != 0)
		return count;
	return 0;
}

bool checkdate(char *date1, char *date2)
{
	for (int i = 0; i < 10; i++)
	{
		if (date1[i] != date2[i])
			return false;
	}
	return true;
}
