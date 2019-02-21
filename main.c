/*
** EPITECH PROJECT, 2018
** 106bombyx
** File description:
** main.c
*/

#include "include/my.h"

int print_help(void)
{
	printf("USAGE\n");
	printf("\t./106bombyx n [k | i0 i 1]\n\n");
	printf("DESCRIPTION\n");
	printf("\tn\tnumber of first generation individuals\n");
	printf("\tk\tgrowth rate from 1 to 4\n");
	printf("\ti0\tinitial generation (included)\n");
	printf("\ti1\tfinal generation (included)\n");
	return (0);
}

int check_param(int argc, char **argv)
{
	float x;
	int a;
	int b;

	for (int i = 1; argv[i] != NULL; i++)
		for (int j = 0; argv[i][j] != '\0'; j++)
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '.')
				return (84);
	if (argc == 3) {
		x = atof(argv[2]);
		if (x < 1 || x > 4)
			return (84);
	}
	if (argc == 4) {
		a = atoi(argv[2]);
		b = atoi(argv[3]);
		if (b < a)
			return (84);
	}
	a = atoi(argv[1]);
	if (a < 0 || a > 100)
		return (84);
	return (1);
}

int calc_growth(int argc, char **argv)
{
	float a = atof(argv[1]);
	float b = atof(argv[2]);

	if (check_param(argc, argv) == 84)
		return (84);
	for (int i = 1; i <= 100; i++) {
		printf("%i %.2f\n", i, a);
		a = (a * b) * ((1000 - a) / 1000);
	}
	return (0);
}

int calc_between(int argc, char **argv)
{
	float x = atof(argv[1]);
	int a = atoi(argv[2]);
	int b = atoi(argv[3]);
	int i;
	float growth;
	float x_save = x;

	if (check_param(argc, argv) == 84)
		return (84);
	for (growth = 1; growth <= 4; growth += 0.01) {
		x = x_save;
		for (i = 0; i < a; i++)
			x = (x * growth) * ((1000 - x) / 1000);
		for (i = a; i <= b; i++) {
			printf("%.2f %.2f\n", growth, x);
			x = (x * growth) * ((1000 - x) / 1000);
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argv[1][0] == '-' && argv[1][1] == 'h' && argc == 2 && argv[1][2] == '\0')
		return (print_help());
	if (argc == 3)
		return (calc_growth(argc, argv));
	if (argc == 4)
		return (calc_between(argc, argv));
	return (84);
}