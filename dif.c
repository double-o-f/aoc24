#include <stdio.h>
#include <stdlib.h>


void sort(int size, int* num_list) {
	if (size <= 1) return;

	int list_1_size = size / 2;
	int list_2_size = list_1_size;
	if (size % 2 != 0) list_2_size += 1;

	printf("help\n");
	int* list_1 = (int*)malloc(list_1_size * sizeof(int));
	int* list_2 = (int*)malloc(list_2_size * sizeof(int));

	for (int i = 0; i < list_1_size; i += 1) {
		list_1[i] = num_list[i];
	}

	for (int i = 0; i < list_1_size; i += 1) {
		printf("%i, ", list_1[i]);
	}


	for (int i = list_1_size; i < size; i += 1) {
		list_2[i] = num_list[i];
	}

	printf(" ");
	for (int i = list_1_size; i < size; i += 1) {
		printf("%i, ", list_2[i]);
	}
	printf(" %i %i\n", list_1_size, list_2_size);


	sort(list_1_size, list_1);
	sort(list_2_size, list_2);

 	int index_1 = 0;
 	int index_2 = 0;

	for (int i = 0; i < size; i += 1) {
		if (index_1 < list_1_size) {
  			num_list[i] = list_2[index_2];
  			index_2 += 1;
  		}
  		else if (index_2 < list_2_size) {
  			num_list[i] = list_1[index_1];
  			index_1 += 1;
  		}
  		else if (list_1[index_1] <= list_2[index_2]) {
  			num_list[i] = list_1[index_1];
  			index_1 += 1;
  		}
  		else {
  			num_list[i] = list_2[index_2];
  			index_2 += 1;
  		}
	}
	free(list_1); 
	free(list_2);
}


int main(int argc, char const* argv[]) {
	int size = 11;

	int list_1[11] = {1, 3, 5, 4, 2, 6, 4, 6, 3, 1, 1};
	int list_2[11] = {4, 2, 4, 3, 3, 6, 6, 2, 4, 5, 3};

	for (int i = 0; i < size; i += 1) {
		printf("%i, ", list_1[i]);
	}
	printf("\n");

	sort(size, list_1);

	for (int i = 0; i < size; i += 1) {
		printf("%i, ", list_1[i]);
	}
	printf("\n");

}

