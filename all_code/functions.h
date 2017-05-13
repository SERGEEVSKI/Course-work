#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct {
	char name[50];
	int wins;
	int draws;
	int loses;
	int scored;
	int missed;
	int points;
} commanddata;

void one_match(commanddata data[], int **teams, int lines, int columns, int oneteam, int twoteam);
