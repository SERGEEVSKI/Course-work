include "functions.h"

int main(void)
{
	FILE *matchhistory = fopen("matchhistory.txt", "w");
	fclose(matchhistory);
	
	setlocale(LC_ALL, "Rus");
	
	commanddata data[32];
	
	int answer,  i = 0, j, oneteam, twoteam, n, m, winnerteam;
	
	int  **teams = (int**)calloc(2048, sizeof(int*));
	for (i = 0; i < 2048; i++) {
		teams[i] = (int*)calloc(2048, sizeof(int));
    }
    
	FILE *probability = fopen("data.txt", "r");
	for (i = 0; i < 32; i++) {
		for (j = 0; j < 64; j++) {
			fscanf(probability, "%d", &teams[i][j]);
		}
	}
	fclose(probability);
	
	i = 0;
	FILE *commandnames = fopen("teams.txt", "r");
	while (!feof(commandnames)) {
		fgets(data[i].name, 50, commandnames);
		i++;
	}
	fclose(commandnames);
	
	printf("play(1) or help(2)(error) or exit(3): ");
	
	scanf("%d", &answer);
	while (answer != 1 && answer != 2 && answer != 3) {
		printf("Error\n");
		scanf("%d", &answer);
	}
	
	if (answer == 1) {
		
		printf("liga(1) or one match(2): ");
		
		scanf("%d", &answer);
		while (answer != 1 && answer != 2) {
			printf("Error\n");
			scanf("%d", &answer);
		}
		
		if (answer == 1) {
			group_stage(data, teams, 32, 64);
			
			return;
		} else if (answer == 2) {
			
			printf("one team and two team: ");
			
			scanf("%d", &oneteam);
			while (oneteam < 1 || oneteam > 32) {
				printf("Error\n");
				scanf("%d", &oneteam);
			}
			scanf("%d", &twoteam);
			while (twoteam < 1 || twoteam > 32 || twoteam == oneteam) {
				printf("Error\n");
				scanf("%d", &twoteam);
			}
			winnerteam = one_match(data, teams, 32, 64, oneteam, twoteam);
			
			return;
		}
		
	} else if (answer == 2) {
		
	} else if (answer == 3) {
		
		return;
	}
	
	system("pause");
	
	return 0;
}
