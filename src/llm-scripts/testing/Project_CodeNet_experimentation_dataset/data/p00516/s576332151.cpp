#include <cstdio>
#include <cstring>

#define ZeroMemory(ptr, size)	::memset(ptr, 0, size)

typedef struct
{
	int id;
	int cost;
	int acquired;
} COMPETITION;

typedef struct
{
	int cost;
} COMMITEE;

#define MAX_N	1000

int MaxAcquiredID(COMPETITION *lpCompes, int num)
{
	int id = 0;
	int max = 0;

	for (int i = 0; i < num; i++)
	{
		if (max < lpCompes[i].acquired)
		{
			max = lpCompes[i].acquired;
			id = lpCompes[i].id;
		}
	}

	return(id);
}

int main()
{
	COMPETITION	compes[MAX_N];
	COMMITEE	commits[MAX_N];
	int compesNum, commitsNum;

	// Init
	ZeroMemory(compes, sizeof(compes));
	ZeroMemory(commits, sizeof(commits));

	// Inputs
	::scanf("%i %i", &compesNum, &commitsNum);

	for (int i = 0; i < compesNum; i++)
	{
		compes[i].id = i + 1;
		::scanf("%i", &compes[i].cost);
	}
	for (int i = 0; i < commitsNum; i++)
	{
		::scanf("%i", &commits[i].cost);
	}

	// Vote
	for (int i = 0; i < commitsNum; i++)
	{
		for (int j = 0; j < compesNum; j++)
		{
			//::printf(">>%i, %i\n", compes[j].cost, commits[i].cost);
			if (compes[j].cost <= commits[i].cost)
			{
				compes[j].acquired++;
				break;
			}
		}
	}
	/*
	for (int i = 0; i < compesNum; i++)
	{
		::printf(">%i\n", commits[i].cost);
	}
	*/
	::printf("%i\n", ::MaxAcquiredID(compes, compesNum));
}