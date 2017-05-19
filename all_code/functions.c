#include "functions.h"

void one_match(commanddata data[], int **teams, int lines, int columns, int oneteam, int twoteam)
{
	srand(time(NULL));
	
	int victoryoneteam, draw, victorytwoteam, goalsoneteam, goalstwoteam, goalsdraw, result, winner = rand() % 100 + 1;
	
	victoryoneteam = teams[oneteam - 1][twoteam * 2 - 2];
	draw = teams[oneteam - 1][twoteam * 2 - 1];
	victorytwoteam = teams[twoteam - 1][oneteam * 2 - 2];
	
//	printf("%d %d %d\n", victoryoneteam, draw, victorytwoteam);
	
	if (winner > 0 && winner <= victoryoneteam) {
		result = 1;
		winner = victoryoneteam;
//		printf("1\n");
	} else if (winner > victoryoneteam && winner <= victoryoneteam + draw) {
		result = 2;
		winner = draw;
//		printf("2\n");
	} else if (winner > victoryoneteam + draw && winner <= victoryoneteam + draw + victorytwoteam) {
		result = 3;
		winner = victorytwoteam;
//		printf("3\n");
	}
	
	if (winner <= 100 && winner > 90) {
		if (result == 1) {
			goalsoneteam = rand() % 14 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);			
		} else if (result == 2) {
			goalsdraw = rand() % 1;	
		} else if (result == 3) {
			goalstwoteam = rand() % 14 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 90 && winner > 80) {
		if (result == 1) {
			goalsoneteam = rand() % 12 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 2;
		} else if (result == 3) {
			goalstwoteam = rand() % 12 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 80 && winner > 70) {
		if (result == 1) {
			goalsoneteam = rand() % 9 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 3;
		} else if (result == 3) {
			goalstwoteam = rand() % 9 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 70 && winner > 60) {
		if (result == 1) {
			goalsoneteam = rand() % 7 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 4;
		} else if (result == 3) {
			goalstwoteam = rand() % 7 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 60 && winner > 50) {
		if (result == 1) {
			goalsoneteam = rand() % 6 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = rand() % 6 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 50 && winner > 40) {
		if (result == 1) {
			goalsoneteam = rand() % 5 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = rand() % 5 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 40 && winner > 30) {
		if (result == 1) {
			goalsoneteam = rand() % 4 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = rand() % 4 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 30 && winner > 20) {
		if (result == 1) {
			goalsoneteam = rand() % 3 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = rand() % 3+ 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 20 && winner > 10) {
		if (result == 1) {
			goalsoneteam = rand() % 2 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = rand() % 2 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 10 && winner > 0) {
		if (result == 1) {
			goalsoneteam = 1;
			goalstwoteam = 0;
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = 1;
			goalsoneteam = 0;
		}
	}
	
	if (result == 1) {
		data[oneteam - 1].scored = data[twoteam - 1].missed = goalsoneteam;
		data[oneteam - 1].missed = data[twoteam - 1].scored = goalstwoteam;
		data[oneteam - 1].points += 3;
		data[oneteam - 1].wins += 1;
		data[twoteam - 1].loses += 1;
	} else if (result == 2) {
		data[oneteam - 1].scored = data[oneteam - 1].missed = data[twoteam - 1].scored = data[twoteam - 1].missed = goalsdraw;
		data[oneteam - 1].points += 1;
		data[twoteam - 1].points += 1;
		data[oneteam - 1].draws += 1;
		data[twoteam - 1].draws += 1;
	} else if (result == 3) {
		data[oneteam - 1].scored = data[twoteam - 1].missed = goalsoneteam;
		data[oneteam - 1].missed = data[twoteam - 1].scored = goalstwoteam;
		data[twoteam - 1].points += 3;
		data[twoteam - 1].wins += 1;
		data[oneteam - 1].loses += 1;
	}
	
//	printf("%d %d\n", goalsoneteam, goalstwoteam);
	
	FILE *matchhistory = fopen("matchhistory.txt", "w+");
	
/*	if (result == 1) {
		fprintf(matchhistory, "%d %d %d %d", oneteam, goalsoneteam, goalstwoteam, twoteam);
	} else if (result == 2) {
		fprintf(matchhistory, "%d %d %d %d", oneteam, goalsdraw, goalsdraw, twoteam);
	} else if (result == 3) {
		fprintf(matchhistory, "%d %d %d %d", oneteam, goalsoneteam, goalstwoteam, twoteam);
	}
	
	fclose(matchhistory);*/
}

void group_stage(commanddata data[], int **teams, int lines, int columns)
{
	srand(time(NULL));
	
	int error = 0, answer, i, j, z, number, temp, *groupstageteams, *groupstagenumberteams, *finalstagenumberteams, oneteam, twoteam;
	
	groupstagenumberteams = (int*)malloc(32 * sizeof(int));
	groupstageteams = (int*)malloc(32 * sizeof(int));
	finalstagenumberteams = (int*)malloc(16 * sizeof(int));
	
	for (i = 0; i < 32; i++) {
		groupstagenumberteams[i] = i + 1;
		groupstageteams[i] = 0;
	}
	
	printf("Group stage 1 or 2(ne robit): ");
	scanf("%d", &answer);
	while (answer != 1 && answer != 2) {
		printf("Error\n");
		scanf("%d", &answer);
	}
	
	if (answer == 1) { //randomnoe raspredelenie na gruppy
		for (i = 0; i < 32; i++) {
			number = rand() % (32 - i);
			groupstageteams[i] = groupstagenumberteams[number];
			for (j = number; j < 31; j++) {
				temp = groupstagenumberteams[j];
				groupstagenumberteams[j] = groupstagenumberteams[j + 1];
				groupstagenumberteams[j + 1] = temp;
			}
		}
	} else if (answer == 2) { //samostoyatel'noe raspredelenie na gruppy
		
		
		
	}
	
	for (i = 0; i < 32; i++) {
		printf("%d ", groupstageteams[i]);
	}
	
	j = 0;
	
	for (i = 0; i < 28; i += 4) {
		oneteam = groupstageteams[i];
		twoteam = groupstageteams[i + 2];
		one_match(data, teams, 32, 64, oneteam, twoteam);
		
		oneteam = groupstageteams[i + 1];
		twoteam = groupstageteams[i + 3];
		one_match(data, teams, 32, 64, oneteam, twoteam);
		
		oneteam = groupstageteams[i];
		twoteam = groupstageteams[i + 1];
		one_match(data, teams, 32, 64, oneteam, twoteam);

		oneteam = groupstageteams[i + 3];
		twoteam = groupstageteams[i + 2];
		one_match(data, teams, 32, 64, oneteam, twoteam);

		oneteam = groupstageteams[i + 3];
		twoteam = groupstageteams[i];
		one_match(data, teams, 32, 64, oneteam, twoteam);

		oneteam = groupstageteams[i + 2];
		twoteam = groupstageteams[i + 1];
		one_match(data, teams, 32, 64, oneteam, twoteam);
	}
	
	for (z = 0; z <= 28; z += 4) {
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
	
	printf("\n");
	
	for (i = 0; i < 32; i++) {
		printf("%d ", groupstageteams[i]);
	}
	
	j = 0;
	for (i = 0; i < 32; i += 4) {
		finalstagenumberteams[j++] = groupstageteams[i];
		finalstagenumberteams[j++] = groupstageteams[i + 1];
	}
	
	printf("\n");
	
	for (i = 0; i < 16; i++) {
		printf("%d ", finalstagenumberteams[i]);
	}
	
	return;
	
	system("pause");
	
//	final_stage(data, teams, 32, 64, finalstagenumberteams);
}
