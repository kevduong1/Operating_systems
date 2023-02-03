#include "../include/structures.h"
#include <stdio.h>

int compare_structs(sample_t* a, sample_t* b)
{
	if(a == NULL || b == NULL || sizeof(a) != sizeof(b)) return 0;

	if(a->a != b->a || a->b != b->b || a->c != b->c) return 0;
	return 1;
}

void print_alignments()
{
	printf("Alignment of int is %zu bytes\n",__alignof__(int));
	printf("Alignment of double is %zu bytes\n",__alignof__(double));
	printf("Alignment of float is %zu bytes\n",__alignof__(float));
	printf("Alignment of char is %zu bytes\n",__alignof__(char));
	printf("Alignment of long long is %zu bytes\n",__alignof__(long long));
	printf("Alignment of short is %zu bytes\n",__alignof__(short));
	printf("Alignment of structs are %zu bytes\n",__alignof__(fruit_t));
}

int sort_fruit(const fruit_t* a,int* apples,int* oranges, const size_t size)
{
	int size_result = 0;
    for (int i = 0; i < (int)size; i++) {
        if (a[i].type == 1) {
            (*apples)++;
			size_result++;

        } else if (a[i].type == 2) {
            (*oranges)++;
			size_result++;
        }
    }
    return size_result;
}
// Purpose: Initializes an array of fruits with the specified number of apples and oranges
// Receives: fruit_t* a - pointer to an array of fruits
//						int apples - the number of apples
//						int oranges - the number of oranges
// Returns: -1 if there was an error, 0 otherwise.
int initialize_array(fruit_t* a, int apples, int oranges)
{
	int i = 0;
    while (apples > 0) {
        a[i].type = 1;
        apples--;
        i++;
    }
    while (oranges > 0) {
        a[i].type = 2;
        oranges--;
        i++;
    }
    return 0;
}

int initialize_orange(orange_t* a)
{
    a->type = 2;
    a->weight = 0;
    a->peeled = 0;
    return 0;
}

int initialize_apple(apple_t* a)
{
    a->type = 1;
    a->weight = 0;
    a->worms = 0;
    return 0;
}
