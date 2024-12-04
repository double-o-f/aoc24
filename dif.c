#include <stdio.h>
#include <stdlib.h>


void mergeSort(int size, int* num_list) {
	/*
		split list in half and call recursively until size <= 1
	*/
	if (size <= 1) return;

	int list_1_size = size / 2;
	int list_2_size = list_1_size;
	if (size % 2 != 0) list_2_size += 1;

	int* list_1 = (int*)malloc(list_1_size * sizeof(int));
	int* list_2 = (int*)malloc(list_2_size * sizeof(int));

	for (int i = 0; i < list_1_size; i += 1) {
		list_1[i] = num_list[i];
	}

	for (int i = 0; i < size - list_1_size; i += 1) {
		list_2[i] = num_list[i + list_1_size];
	}

	mergeSort(list_1_size, list_1);
	mergeSort(list_2_size, list_2);

	/*
		merge lists from least to greatest
	*/
 	int index_1 = 0;
 	int index_2 = 0;

	for (int i = 0; i < size; i += 1) {
		if (index_1 >= list_1_size) {
  			num_list[i] = list_2[index_2];
  			index_2 += 1;
  		}
  		else if (index_2 >= list_2_size) {
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
	int size = 0;
	int total_dif = 0;
	int* list_1;
	int* list_2;


	FILE* filePtr = fopen("dif-input.txt","r");
	while (!feof(filePtr))				/*loop finds how many lines are in file*/
	{
		char chr = fgetc(filePtr);		/*read next char from file*/
		if (chr == '\n')
		{
			size += 1;
		}
	}
	fseek(filePtr, 0, SEEK_SET);			/*set pointer to start of file*/
	
	list_1 = (int*)malloc(size * sizeof(int));
	list_2 = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i += 1)
	{
		char num_str[5];			/*numbers in input are 5 chars long*/
		for (int j = 0; j < 5; j += 1)
		{
			num_str[j] = fgetc(filePtr);	/*read next char from file*/
		}

		list_1[i] = atoi(num_str);		/*convert num_str to int*/
		fseek(filePtr, 3, SEEK_CUR);		/*skip past spaces*/


		for (int j = 0; j < 5; j += 1)
		{
			num_str[j] = fgetc(filePtr);	/*read next char from file*/
		}

		list_2[i] = atoi(num_str);		/*convert num_str to int*/
		fseek(filePtr, 1, SEEK_CUR);		/*skip past \n*/
	}
	fclose(filePtr);


	mergeSort(size, list_1);
	mergeSort(size, list_2);


	for (int i = 0; i < size; i += 1) {		/*difference between lists*/
		int dif = abs(list_1[i] - list_2[i]);
		total_dif += dif;
	}
	printf("%i\n", total_dif);			/*print total difference*/

	return 0;
}
