/*	James Ward
	Assignment 4, makefiles
	Operating Systems Spring 2016

	This file holds the sorting function for use on the string collection. The function
	is declared in sort.h, and is used in a4.c.
*/

#include "a4.h"

/*Implements the selection sorting algorithm to sort the string pointed to by str*/
void sortString(string * str){

	fprintf(stdout, ">UNSORTED: ");
	printString(str);

	int minIdx = 0;
	int sorted = 0;
	int i = 0;

	for(sorted = 0; sorted < str->length; sorted++){

		minIdx = sorted;

		for(i = (sorted+1); i < str->length; i++){

			if (str->array[i] < str->array[minIdx]){
				minIdx = i;//find the smallest char this iteration
			}
		}
		//swap the min char to the front of the array
		if(swap(str, minIdx, sorted) == -1){
			fprintf(stderr, "Warning: swap returned -1\n");
		}
	}

	fprintf(stdout, ">SORTED: ");
	printChars(str);
}