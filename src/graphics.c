#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphics.h"

void group(char *a, int next, int *b)
{
	int i;
	char *mas;
        mas = (char*)malloc(8 * sizeof(char));
        mas[0] = 'A';
        for(i = 1; i < 8; i++)
                mas[i] = mas[0] + i;
	*a = mas[next-1];
	if(next == 1)
		*b = 0;
	else if(next == 2)
		*b = 4;
	else if(next == 3)
		*b = 8;
	else if(next == 4)
		*b = 12;
	else if(next == 5)
		*b = 16;
	else if(next == 6)
		*b = 20;
	else if(next == 7)
		*b = 24;
	else if(next == 8)
		*b = 28;
}

void screen_02()
{
	int q, next = 1, b;

	char **mas2, a;

	mas2 = (char**)malloc(50 * sizeof(char*));
	for(q = 0; q < 50; q++)
		mas2[q] = (char*)malloc(50 * sizeof(char));

	FILE *in = fopen("TeamList.txt", "r");

	for(q = 0; !(feof(in)); q++)
		fgets(mas2[q],40,in);
	fclose(in);

	while(next != 0)
{
	group(&a,next,&b);
	system("clear");
	printf("\n");
        printf(" ******************************************************************************\n");
        printf(" *                                                                            *\n");
        printf(" *              Список отборочных групп на основе подбора команд              *\n");
        printf(" *                                                                            *\n");
        printf(" ******************************************************************************\n");
        printf("                                                                               \n");
	printf("                         ***************************                           \n");
	printf("                        *         GROUP '%c'         *                          \n", a);
	printf(" ***********************                             **************************\n\t\t\t");
	printf("%s", mas2[b]);
	printf("                       *******************************                         \n\t\t\t");
	printf("%s", mas2[b+1]);
	printf("                       *******************************                         \n\t\t\t");
	printf("%s", mas2[b+2]);
	printf("                       *******************************                         \n\t\t\t");
	printf("%s", mas2[b+3]);
	printf(" ***********************                             **************************\n");
	printf("                        *                           *                          \n");
	printf("                         ***************************                           \n\n");
	printf(" (Подсказка: Нажмите 1-8 для просмотра других групп | Выйти в меню - 0)        \n [Выберите интересующий вас пункт] : ");
	scanf("%d", &next);
}
	if(next == 0)
		screen_01();
}

void screen_01()
{
	int mode;

	system("clear");

	printf("\n");
	printf(" ****************************************************************************** \n");
	printf("  *                                                                          *  \n");
	printf("   *                GENERATOR OF A TOURNAMENT GRID (v.1.1) 2017             *   \n");
	printf("  *                                                                          *  \n");
	printf(" ****************************************************************************** \n");
	printf(" *                                                                            * \n");
	printf(" *                             Добро пожаловать!                              * \n");
	printf(" *                                                                            * \n");
	printf("  *        Выберите один из пунктов меню для того, чтобы начать работу:      *  \n");
	printf("   *                                                                        *   \n");
	printf("   **************************************************************************   \n");
	printf("   *                                                                        *   \n");
	printf("   *       > НАЧАТЬ ОТБОРОЧНЫЙ ТУРНИР                     (нажмите '1')     *   \n");
	printf("   *                                                                        *   \n");
	printf("   **************************************************************************   \n");
	printf("   *                                                                        *   \n");
	printf("   *       > ПОМОЩЬ И СПРАВОЧНЫЕ МАТЕРИАЛЫ                (нажмите '2')     *   \n");
	printf("   *                                                                        *   \n");
	printf("   **************************************************************************   \n");
	printf("   *                                                                        *   \n");
	printf("   *       > ВЫЙТИ ИЗ ПРОГРАММЫ                           (нажмите '3')     *   \n");
	printf("   *                                                                        *   \n");
	printf("   **************************************************************************   \n : ");

	scanf("%d", &mode);

	if(mode != 1)
	{
		exit(1);
	}
	else if(mode == 1)
	{
		screen_02();
	}
}

