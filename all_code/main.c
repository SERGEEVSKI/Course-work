#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct {
	char name[50];
	int wins;
	int draws;
	int loses;
	int scored;
	int missed;
	int points;
} team_information;

int check_data(int oneteam, int twoteam)	//funccia proverki dannyh fa'lov
{
	int victoryoneteam, victorytwoteam, n = 0, pawn;
	
	if (oneteam == twoteam) {
		
		return 0;
	}
	
	FILE *test = fopen("data.txt", "r");	//iz'yatie veroyatnosti dlya komand iz tekstovogo fa'la
	for (n = 0; !feof(test); n++) {
		fscanf(test, "%d", &pawn);
		if (n == 64 * (oneteam - 1) + 2 * (twoteam - 1)) {
			victoryoneteam = pawn;
		} else if (n  == 64 * (twoteam - 1) + 2 * (oneteam - 1)) {
			victorytwoteam = pawn;
		}
	}
	fclose(test);
	
	if (victoryoneteam + victorytwoteam == 100) {
		
		return 0;
	} else {
//		printf("\n\nTEAMS: %d %d\nFAILED", oneteam, twoteam);
//		printf("\nvictory: %d %d\n", victoryoneteam, victorytwoteam);
		
		return -1;
	}
}

int final_one_match(int oneteam, int twoteam)
{
	int winnerteam, result, n = 0, error, pawn, victoryoneteam, victorytwoteam, goals_one_team = 0, goals_two_team = 0;
	
	error = check_data(oneteam, twoteam);
	if (error == -1) {
		
//		return 0;
	}
	
	FILE *probability = fopen("data.txt", "r");		//iz'yatie veroyatnosti dlya komand iz tekstovogo fa'la
	for (n = 0; !feof(probability); n++) {
		fscanf(probability, "%d", &pawn);
		if (n == 64 * (oneteam - 1) + 2 * (twoteam - 1)) {
			victoryoneteam = pawn;
		} else if (n  == 64 * (twoteam - 1) + 2 * (oneteam - 1)) {
			victorytwoteam = pawn;
		}
	}
	fclose(probability);
	
//	printf("\nvictory: %d %d\n", victoryoneteam, victorytwoteam);
	
	while (goals_one_team == goals_two_team) {
	    if (victoryoneteam > 0 && victoryoneteam <= 10) {
		goals_one_team = rand() % 1;
	    } else if (victoryoneteam > 10 && victoryoneteam <= 20) {
		goals_one_team = rand() % 1;
	    } else if (victoryoneteam > 20 && victoryoneteam <= 30) {
		goals_one_team = rand() % 2;
	    } else if (victoryoneteam > 30 && victoryoneteam <= 40) {
		goals_one_team = rand() % 2;
	    } else if (victoryoneteam > 40 && victoryoneteam <= 50) {
		goals_one_team = rand() % 3;
	    } else if (victoryoneteam > 50 && victoryoneteam <= 60) {
		goals_one_team = rand() % 4;
	    } else if (victoryoneteam > 60 && victoryoneteam <= 70) {
		goals_one_team = rand() % 5;
	    } else if (victoryoneteam > 70 && victoryoneteam <= 80) {
		goals_one_team = rand() % 6;
	    } else if (victoryoneteam > 80 && victoryoneteam <= 90) {
		goals_one_team = rand() % 7;
	    } else if (victoryoneteam > 90 && victoryoneteam <= 100) {
		goals_one_team = rand() % 9;
	    } else {
		
		return -1;
	    }
	
	    if (victorytwoteam > 0 && victorytwoteam <= 10) {
		goals_two_team = rand() % 1;
	    } else if (victorytwoteam > 10 && victorytwoteam <= 20) {
		goals_two_team = rand() % 1;
	    } else if (victorytwoteam > 20 && victorytwoteam <= 30) {
		goals_two_team = rand() % 2;
	    } else if (victorytwoteam > 30 && victorytwoteam <= 40) {
		goals_two_team = rand() % 2;
	    } else if (victorytwoteam > 40 && victorytwoteam <= 50) {
		goals_two_team = rand() % 3;
	    } else if (victorytwoteam > 50 && victorytwoteam <= 60) {
		goals_two_team = rand() % 4;
	    } else if (victorytwoteam > 60 && victorytwoteam <= 70) {
		goals_two_team = rand() % 5;
	    } else if (victorytwoteam > 70 && victorytwoteam <= 80) {
		goals_two_team = rand() % 6;
	    } else if (victorytwoteam > 80 && victorytwoteam <= 90) {
		goals_two_team = rand() % 7;
	    } else if (victorytwoteam > 90 && victorytwoteam <= 100) {
		goals_two_team = rand() % 9;
	    } else {
		
		return -1;
	    }
	}
	
	
	FILE *goalshistory = fopen("goalshistory.txt", "a");		//zapis' matcha v tekstovy' fa'l
	
	fprintf(goalshistory, "%d %d\n", goals_one_team, goals_two_team);
	
	fclose(goalshistory);
	
	
	if (goals_one_team > goals_two_team) {
		
		
		return oneteam;
	} else if (goals_one_team == goals_two_team) {
		
		return -1;
	} else if (goals_one_team < goals_two_team) {
		
		
		return twoteam;
	}
	
	return 0;
}

int one_match(int oneteam, int twoteam, team_information *data)
{
	int winnerteam, result, n = 0, error, pawn, victoryoneteam, victorytwoteam, goals_one_team, goals_two_team;
	
	error = check_data(oneteam, twoteam);
	if (error == -1) {
		
//		return 0;
	}
	
	FILE *probability = fopen("data.txt", "r");		//iz'yatie veroyatnosti dlya komand iz tekstovogo fa'la
	for (n = 0; !feof(probability); n++) {
		fscanf(probability, "%d", &pawn);
		if (n == 64 * (oneteam - 1) + 2 * (twoteam - 1)) {
			victoryoneteam = pawn;
		} else if (n  == 64 * (twoteam - 1) + 2 * (oneteam - 1)) {
			victorytwoteam = pawn;
		}
	}
	fclose(probability);
	
//	printf("\nvictory: %d %d\n", victoryoneteam, victorytwoteam);
	
	if (victoryoneteam > 0 && victoryoneteam <= 10) {
		goals_one_team = rand() % 1;
	} else if (victoryoneteam > 10 && victoryoneteam <= 20) {
		goals_one_team = rand() % 1;
	} else if (victoryoneteam > 20 && victoryoneteam <= 30) {
		goals_one_team = rand() % 2;
	} else if (victoryoneteam > 30 && victoryoneteam <= 40) {
		goals_one_team = rand() % 2;
	} else if (victoryoneteam > 40 && victoryoneteam <= 50) {
		goals_one_team = rand() % 3;
	} else if (victoryoneteam > 50 && victoryoneteam <= 60) {
		goals_one_team = rand() % 4;
	} else if (victoryoneteam > 60 && victoryoneteam <= 70) {
		goals_one_team = rand() % 5;
	} else if (victoryoneteam > 70 && victoryoneteam <= 80) {
		goals_one_team = rand() % 6;
	} else if (victoryoneteam > 80 && victoryoneteam <= 90) {
		goals_one_team = rand() % 7;
	} else if (victoryoneteam > 90 && victoryoneteam <= 100) {
		goals_one_team = rand() % 9;
	} else {
		
		return -1;
	}
	
	if (victorytwoteam > 0 && victorytwoteam <= 10) {
		goals_two_team = rand() % 1;
	} else if (victorytwoteam > 10 && victorytwoteam <= 20) {
		goals_two_team = rand() % 1;
	} else if (victorytwoteam > 20 && victorytwoteam <= 30) {
		goals_two_team = rand() % 2;
	} else if (victorytwoteam > 30 && victorytwoteam <= 40) {
		goals_two_team = rand() % 2;
	} else if (victorytwoteam > 40 && victorytwoteam <= 50) {
		goals_two_team = rand() % 3;
	} else if (victorytwoteam > 50 && victorytwoteam <= 60) {
		goals_two_team = rand() % 4;
	} else if (victorytwoteam > 60 && victorytwoteam <= 70) {
		goals_two_team = rand() % 5;
	} else if (victorytwoteam > 70 && victorytwoteam <= 80) {
		goals_two_team = rand() % 6;
	} else if (victorytwoteam > 80 && victorytwoteam <= 90) {
		goals_two_team = rand() % 7;
	} else if (victorytwoteam > 90 && victorytwoteam <= 100) {
		goals_two_team = rand() % 9;
	} else {
		
		return -1;
	}
	
	if (goals_one_team > goals_two_team) {
		winnerteam = oneteam;
		result = 1;
	} else if (goals_one_team == goals_two_team) {
		winnerteam = 99;
		result = 2;
	} else if (goals_one_team < goals_two_team) {
		winnerteam = twoteam;
		result = 3;
	}
		
//	printf("goals: %d %d\n", goals_one_team, goals_two_team);
	
	if (result == 1) {							//zapisyvaet ochki i golly v massivy dannyh
		data[oneteam - 1].scored += goals_one_team;
		data[twoteam - 1].missed += goals_one_team;
		data[oneteam - 1].missed += goals_two_team;
		data[twoteam - 1].scored += goals_two_team;
		data[oneteam - 1].points += 3;
		data[oneteam - 1].wins += 1;
		data[twoteam - 1].loses += 1;
	} else if (result == 2) {
		data[oneteam - 1].scored += goals_one_team;
		data[twoteam - 1].missed += goals_one_team;
		data[oneteam - 1].missed += goals_two_team;
		data[twoteam - 1].scored += goals_two_team;
		data[oneteam - 1].points += 1;
		data[twoteam - 1].points += 1;
		data[oneteam - 1].draws += 1;
		data[twoteam - 1].draws += 1;
	} else if (result == 3) {
		data[oneteam - 1].scored += goals_one_team;
		data[twoteam - 1].missed += goals_one_team;
		data[oneteam - 1].missed += goals_two_team;
		data[twoteam - 1].scored += goals_two_team;
		data[twoteam - 1].points += 3;
		data[twoteam - 1].wins += 1;
		data[oneteam - 1].loses += 1;
	}
/*	printf("\nwins: %d %d\n", wins[oneteam - 1], wins[twoteam - 1]);
	printf("draws: %d %d\n", draws[oneteam - 1], draws[twoteam - 1]);
	printf("loses: %d %d\n", loses[oneteam - 1], loses[twoteam - 1]);
	printf("scored: %d %d\n", scored[oneteam - 1], scored[twoteam - 1]);
	printf("missed: %d %d\n", missed[oneteam - 1], missed[twoteam - 1]);
	printf("points: %d %d\n", points[oneteam - 1], points[twoteam - 1]);
	printf("%d %d\n\n", goals_of_winner, goals_of_loser);
*/	
	
//	printf("\n%d %d %d %d\n", oneteam, goals_one_team, goals_two_team, twoteam);

	FILE *matchhistory = fopen("matchhistory.txt", "a");		//zapis' matcha v tekstovy' fa'l
	
	fprintf(matchhistory, "%d %d %d %d\n", oneteam, goals_one_team, goals_two_team, twoteam);
	
	fclose(matchhistory);
	
//	printf("%d %d %d %d %d %d\n", data[oneteam - 1].wins, data[oneteam - 1].loses, data[oneteam - 1].draws, data[oneteam - 1].scored, data[oneteam - 1].missed, data[oneteam - 1].points);
//	printf("%d %d %d %d %d %d\n", data[twoteam - 1].wins, data[twoteam - 1].loses, data[twoteam - 1].draws, data[twoteam - 1].scored, data[twoteam - 1].missed, data[twoteam - 1].points);
		
	if (goals_one_team > goals_two_team) {
		
		return oneteam;
	} else if (goals_one_team == goals_two_team) {
		
		return 99;
	} else if (goals_one_team < goals_two_team) {
		
		return twoteam;
	}
	return 0;
}

void final_stage(team_information data[], int *restart, int *groupstageteams, int *finalstagenumberteams, int **goals_group)
{
	int i, j, z, x, y, temp, number, oneteam, twoteam;
	int winnerteam, final[2], semifinal[4], quarterfinals[8], finalstageteams[16], goals[4][16];
	
	for (i = 0; i < 16; i++) {
		number = rand() % (16 - i);
		finalstageteams[i] = finalstagenumberteams[number];
		for (j = number; j < 15; j++) {
			temp = finalstagenumberteams[j];
			finalstagenumberteams[j] = finalstagenumberteams[j + 1];
			finalstagenumberteams[j + 1] = temp;
		}
	}
	
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 16; y++) {
		    goals[x][y] = 0;
//		    printf("%d ", goals[x][y]);
		}
//	printf("\n\n");
	}
	
	for (z = 0; z < 4; z++) {		//provedenie finala, polufinala, chetvert'finala
		FILE *re_goalshistory = fopen("goalshistory.txt", "w");
		fclose(re_goalshistory);
		
		j = 0;
		if (z == 0) {
			for (i = 0; i < 15; i += 2) {
				quarterfinals[j] = final_one_match(finalstageteams[i], finalstageteams[i + 1]);
				
				j++;
			}
			
			FILE *write_goals_quarter = fopen("goalshistory.txt", "r");
			for (y = 0; !feof(write_goals_quarter); y++) {
			    fscanf(write_goals_quarter, "%d", &goals[0][y]);
			}
			fclose(write_goals_quarter);
			
//			printf("\ngoals: ");
			for (y = 0; y < j * 2; y++) {
//			    printf("%d ", goals[0][y]);
			}
			
//			printf("\nQUARTERFINALS: ");
		        for (i = 0; i < 8; i++) {
//				printf("%d ", quarterfinals[i]);
			}
		} else if (z == 1) {
			for (i = 0; i < 7; i += 2) {
				semifinal[j] = final_one_match(quarterfinals[i], quarterfinals[i + 1]);
				
				j++;
			}
			
			FILE *write_goals_semifinal = fopen("goalshistory.txt", "r");
			for (y = 0; !feof(write_goals_semifinal); y++) {
			    fscanf(write_goals_semifinal, "%d", &goals[1][y]);
			}
			fclose(write_goals_semifinal);
			
//			printf("\n");
			for (y = 0; y < j * 2; y++) {
//			    printf("%d ", goals[1][y]);
			}
//			printf("\nSEMIFINAL: ");
			for (i = 0; i < 4; i++) {
//				printf("%d ", semifinal[i]);
			}
		} else if (z == 2) {
			final[0] = final_one_match(semifinal[0], semifinal[1]);
			final[1] = final_one_match(semifinal[2], semifinal[3]);
			
			FILE *write_goals_final = fopen("goalshistory.txt", "r");
			for (y = 0; !feof(write_goals_final); y++) {
			    fscanf(write_goals_final, "%d", &goals[2][y]);
			}
			fclose(write_goals_final);
			
//			printf("\ngoals: %d %d %d %d", goals[2][0], goals[2][1], goals[2][2], goals[2][3]);
//			printf("\nFINAL: ");
			for (i = 0; i < 2; i++) {
//			    printf("%d ", final[i]);
			}
		} else if (z == 3) {
			winnerteam = final_one_match(final[0], final[1]);
			
			FILE *write_goals_win = fopen("goalshistory.txt", "r");
			for (y = 0; !feof(write_goals_win); y++) {
			    fscanf(write_goals_win, "%d", &goals[3][y]);
			}
			fclose(write_goals_win);
			
//			printf("\ngoals: %d %d\n", goals[3][0], goals[3][1]);
		}
	}
	
//	printf("\nFINALSTAGETEAMS: ");
//	for (i = 0; i < 16; i++) {
//		printf("%d ", finalstageteams[i]);
//	}
//	printf("\nQUARTERFINALS: ");
//	for (i = 0; i < 8; i++) {
//		printf("%d ", quarterfinals[i]);
//	}
//	printf("\nSEMIFINAL: ");
//	for (i = 0; i < 4; i++) {
//		printf("%d ", semifinal[i]);
//	}
//	printf("\nFINAL: ");
//	for (i = 0; i < 2; i++) {
//		printf("%d ", final[i]);
//	}
//	printf("\nWINNER: ");
//	printf("%d", winnerteam);


//	for (x = 0; x < 4; x++) {
//		for (y = 0; y < 16; y++) {
//		    printf("%d ", goals[x][y]);
//		}
//	printf("\n\n");
//	}
	
	screen_01(data, &*restart, groupstageteams, finalstagenumberteams, winnerteam, final, semifinal, quarterfinals, finalstageteams, goals, goals_group);
}

void group_stage(team_information data[], int *restart)
{
	int answer, i, j, z, number, temp;
	int groupstagenumberteams[32], groupstageteams[32], finalstagenumberteams[16], goals_group[48][4];

	for (i = 0; i < 32; i++) {
		groupstagenumberteams[i] = i + 1;
		groupstageteams[i] = 0;
	}

	for (i = 0; i < 32; i++) {
		number = rand() % (32 - i);
		groupstageteams[i] = groupstagenumberteams[number];
		for (j = number; j < 31; j++) {
			temp = groupstagenumberteams[j];
			groupstagenumberteams[j] = groupstagenumberteams[j + 1];
			groupstagenumberteams[j + 1] = temp;
		}
	}

	for (i = 0; i < 32; i += 4) {	//v kazhdo' gruppe 4 komandy igrayut mezhdu sobo', zdes' igrayut vse 8 grupp
		one_match(groupstageteams[i], groupstageteams[i + 2], data);
		one_match(groupstageteams[i + 1], groupstageteams[i + 3], data);
		one_match(groupstageteams[i], groupstageteams[i + 1], data);
		one_match(groupstageteams[i + 3], groupstageteams[i + 2], data);
		one_match(groupstageteams[i + 3], groupstageteams[i], data);
		one_match(groupstageteams[i + 2], groupstageteams[i + 1], data);
	}
	
/*	printf("\nGROUPSTAGETEAMS_BEFORE: ");
	
	for (i = 0; i < 32; i++) {
		printf("%d ", groupstageteams[i]);
	}
	printf("\nPOINTS: ");
	for (i = 0; i < 32; i++) {
		printf("%d ", data[groupstageteams[i] - 1].points);
	}
*/
	
	for (z = 0; z <= 28; z += 4) {	//sravnenie ochkov komand v gruppe i ih sortirovka po gruppam
		for (j = 0; j < 3; j++) {
			for (i = 0 + z; i < 3 + z; i++) {
				if (data[groupstageteams[i] - 1].points < data[groupstageteams[i + 1] - 1].points) {
					temp = groupstageteams[i];
					groupstageteams[i] = groupstageteams[i + 1];
					groupstageteams[i + 1] = temp;
				}
			}
		}
	}
	
	j = 0;
	for (i = 0; i < 32; i += 4) {
		finalstagenumberteams[j++] = groupstageteams[i];
		finalstagenumberteams[j++] = groupstageteams[i + 1];
	}
	
	for (i = 0; i < 48; i++) {
		for (j = 0; j < 4; j++) {
			goals_group[i][j] = 0;
//			printf("%d ", goals_group[i][j]);
		}
//		printf("\n");
	}
	
	FILE *matchhistory_groupstage = fopen("matchhistory.txt", "r");		//zapis' matcha v tekstovy' fa'l
	for (i = 0; i < 48; i++) {
		for (j = 0; j < 4; j++) {
			fscanf(matchhistory_groupstage, "%d", &goals_group[i][j]);
//			printf("%d ", goals_group[i][j]);
		}
//		printf("\n");
	}
	fclose(matchhistory_groupstage);
	
/*	printf("\n\n\nGROUPSTAGETEAMS_AFTER: ");
	
	for (i = 0; i < 32; i++) {
		printf("%d ", groupstageteams[i]);
	}
	printf("\nPOINTS: ");
	for (i = 0; i < 32; i++) {
		printf("%d ", data[groupstageteams[i] - 1].points);
	}
*/

/*	printf("\nFINALSTAGENUMBERTEAMS: ");	
	for (i = 0; i < 16; i++) {
		printf("%d ", finalstagenumberteams[i]);
	}
*/	

	final_stage(data, &*restart, groupstageteams, finalstagenumberteams, goals_group);
}
int main(void)
{
	srand(time(NULL));
	
	setlocale(LC_ALL, "Rus");
	
	int restart = 1,  i;
	
	team_information data[32];
	
	FILE *commandnames = fopen("teams.txt", "r");
	for (i = 0; !feof(commandnames); i++) {
		fgets(data[i].name, 50, commandnames);
	}
	fclose(commandnames);
	
	while (restart == 1) {
		restart = 0;
		
		FILE *matchhistory = fopen("matchhistory.txt", "w");
		fclose(matchhistory);
	
		for (i = 0; i < 32; i++) {
			data[i].wins = 0;
			data[i].draws = 0;
			data[i].loses = 0;
			data[i].scored = 0;
			data[i].missed = 0;
			data[i].points = 0;
		}
	
		group_stage(data, &restart);
	}
	
/*	printf("play(1) or help(2)(error) or exit(3): ");
	
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
			
			return 0;
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
			
			winnerteam = one_match(oneteam, twoteam, data);
			
//			printf("%d %d %d %d %d %d\n", data[oneteam - 1].wins, data[oneteam - 1].loses, data[oneteam - 1].draws, data[oneteam - 1].scored, data[oneteam - 1].missed, data[oneteam - 1].points);
//			printf("%d %d %d %d %d %d\n\n", data[twoteam - 1].wins, data[twoteam - 1].loses, data[twoteam - 1].draws, data[twoteam - 1].scored, data[twoteam - 1].missed, data[twoteam - 1].points);
			
			return 0;
		}
	}
*/	
	return 0;
}
