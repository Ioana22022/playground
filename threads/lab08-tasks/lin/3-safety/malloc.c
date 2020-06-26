/**
 * SO, 2016
 * Lab #8
 *
 * Task #3, lin
 *
 * Is malloc thread safe?
 */
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include <utils.h>

#define NUM_THREADS	100
#define NUM_ROUNDS	1000

void *th_alloc(void *args)
{
	size_t i;
	char **a;

	a = malloc(1000 * sizeof(char *));
	for (i = 0; i < NUM_ROUNDS; i++)
		a[i] = malloc(1000);

	return a;
}

void free_mat(void **mat)
{
	size_t i;
	char **a = (char **) mat;

	for (i = 0; i < NUM_ROUNDS; i++)
		free(a[i]);
	free(a);
}

int main(void)
{

	pthread_t th[NUM_THREADS];
	int rc;
	size_t i;
	void *mat[NUM_THREADS];

	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_create(&th[i], NULL, th_alloc, &i);
		DIE(rc != 0, "pthread_create");
	}

	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_join(th[i], &mat[i]);
		DIE(rc != 0, "pthread_join");
	}

	/* Freeing */
	for (i = 0; i < NUM_THREADS; i++)
		free_mat(mat[i]);

	return 0;
}
