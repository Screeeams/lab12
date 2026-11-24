#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define N 10
#define M 100

double calc_func(double x);

int main() {
	setlocale(LC_ALL, "RUS");

	float A[N], B[N];
	float temp, sum = 0;

	for (int i = 0; i < N; i++) {
		printf("a[%d] = ", i + 1);
		scanf("%f", &temp);
		A[i] = temp;
		if (A[i] == 0) {
			B[i] = (float)(i + 1);
		}
		else {
			B[i] = A[i];
		}
		sum += B[i];
	}

	printf("\n| индекс | исходное значение | новое значение |\n");
	for (int i = 0; i < N; i++) {
		printf("| %6d | %17.2f | %14.2f |\n", i, A[i], B[i]);
	}
	printf("Среднее арифметическое элементов массива: %.2f\n\n", sum / N);

	double C[M];
	double x = 0.1, step = 0.02;
	double sum_pos = 0, sum_neg = 0;
	int count_pos = 0, count_neg = 0;

	for (int i = 0; i < M; i++) {
		C[i] = calc_func(x);
		if (C[i] > 0) {
			sum_pos += C[i];
			count_pos++;
		}
		else if (C[i] < 0) {
			sum_neg += C[i];
			count_neg++;
		}
		x += step;
	}

	double avg_pos = (count_pos > 0) ? (sum_pos / count_pos) : 0;
	printf("Имя массива: C | Сумма полож.: %.2lf | Сумма отриц.: %.2lf | Кол-во полож.: %d | Кол-во отриц.: %d | Среднее полож.: %.2lf\n\n", sum_pos, sum_neg, count_pos, count_neg, avg_pos);

	int n;
	int D[100];
	int count = 0;

	printf("Введите количество элементов массива (не более 100): ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("D[%d] = ", i);
		scanf("%d", &D[i]);
		if (i % 2 == 0 && D[i] > 10) {
			count++;
		}
	}

	printf("Количество элементов больше 10 на четных позициях: %d\n", count);

	return 0;
}

double calc_func(double x) {
	return x * x - 4 * sin(x);
}