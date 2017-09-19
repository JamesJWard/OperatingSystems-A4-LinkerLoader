/*	James Ward
	Assignment 4, makefiles
	Operating Systems Spring 2016

	This file holds the mian function and printing functions. It's functions are declared
	in a4.h, and it uses functions from both string.c and sort.c. A demonstration of the
	string "collection" is done on two string structures where their size is increased,
	they're concatenated, and sorted.
*/

#include "a4.h"

int main(int argc, char const *argv[])
{
	
	string * s1 = newString(20);
	string * s2 = newString(20);

	fprintf(stdout, "2 strings created:\n>s1 size: %d length: %d\n>s2 size: %d length: %d\n\n", 
		s1->size, s1->length, s2->size, s2->length);


	fprintf(stdout, ">adding 25 z's to s1\n");
	while(s1->length < 25){
		addChar(s1,'z');
	}
	fprintf(stdout, ">s1:");printChars(s1);

	fprintf(stdout, "\n>adding 30 chars's to s2\n");
	int a = 0;
	while(s2->length < 30){
		addChar(s2,'J'-a++);
	}
	fprintf(stdout, ">s2:");printChars(s2);

	fprintf(stdout, "\n>s1 appeneded with s2\n");
	appendString(s1,s2);
	printString(s1);

	fprintf(stdout, "\n>AZXgTaIJ appeneded to s2\n");
	catCString(s2, "AZXgTaIJ");
	printString(s2);

	fprintf(stdout, "\n>sort s2\n");
	sortString(s2);

	fprintf(stdout, "\nFinal strings stats:\n>s1 size: %d length: %d\n>s2 size: %d length: %d\n", 
		s1->size, s1->length, s2->size, s2->length);

	//clean up
	free(s1->array);
	free(s1);
	free(s2->array);
	free(s2);

	return 0;
}

/*Accepts a string structure pointer that is used with getCString to get a null terminated
	String and prints with fprintf. Mallocs space for this string returned from getCString
	and frees it. If there is an error with malloc, the program exits*/
void printString(string * str){

	char * outStr;
	if ((outStr = malloc((lengthString(str) + 1))) == NULL){
		exitProg("malloc, printString");
	}

	getCString(str, outStr);

	fprintf(stdout, "%s\n", outStr);
	
	free(outStr);
}


/*Accepts a string struct pointer and uses getPos to print out every char of str's array. */
void printChars(string * str){

	char out = '\0';
	int i = 0;

	while((out = getPos(str,i)) != '\0'){

		fprintf(stdout, "%c", out);

		i++;
	}
	fprintf(stdout, "\n");
}

/*simple exit function that prints a message*/
void exitProg(char * msg){

	fprintf(stderr, "ERROR: %s\n", msg);
	exit(0);
}