#include <stdio.h>


void sort(int size, int* num_list) {
	if (size <= 1) return;

	int list_1_size = size / 2;
	int list_2_size = list_1_size;
	if (size % 2 != 0) list_2_size -= 1;

	int* list_1 = malloc(list_1_size * sizeof(int));
	int* list_2 = malloc(list_2_size * sizeof(int));

	sort(list_1);
	sort(list_2);

 	index_1 = 0;
 	index_2 = 0;

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
  			list[index_1];
  			index_1 += 1;
  		}
  		else {
  			list[index_2];
  			index_2 += 1;
  		}
	}
	free(list_1); 
	free(list_2);
}


int main(int argc, char const* argv[]) {
	int size = 5;

	int list_1[5] = {1, 3, 5, 4, 2};
	int list_1[5] = {4, 2, 4, 3, 3};

}

