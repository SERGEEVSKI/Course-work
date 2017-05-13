#include "functions.h"

int main(void)
{
	setlocale(LC_ALL, "Rus");
	
	commanddata data[32];
	
	int i = 0, j, oneteam, twoteam;
	
	int  **teams = (int**)calloc(18, sizeof(int*));
	for (i = 0; i < 18; i++) {
		teams[i] = (int*)calloc(18, sizeof(int));
    }
	FILE *probability = fopen("test.txt", "r");
	for (i = 0; i < 3; i++) {
		for(j = 0; j < 6; j++) {
			fscanf(probability, "%d", &teams[i][j]);
		}
	}
	fclose(probability);
	
	FILE *commandnames = fopen("teams.txt", "r");
	while (!feof(commandnames)) {
		fgets(data[i].name, 50, commandnames);
		i++;
	}
	fclose(commandnames);
	
	scanf("%d", &oneteam);
	scanf("%d", &twoteam);
	one_match(data, teams, 32, 64, oneteam, twoteam);
	
//	system("pause");
	
	return 0;
}
