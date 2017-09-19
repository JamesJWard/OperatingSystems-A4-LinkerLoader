/*	James Ward
	Assignment 4, makefiles
	Operating Systems Spring 2016

	This file holds all of the modification functions to act on the string struct.
	These funcitons are declared in string.h, and are used in a4.c and sort.c.
*/

#include "a4.h"

/*creates a  new string structure with initialSize, doesn't hold null char*/
string * newString(int initialSize){

	string * ret;
	if((ret = malloc(sizeof(string))) == NULL){
		exitProg("malloc, struct");
	}
	if((ret->array = malloc(sizeof(char)*initialSize)) == NULL){
		exitProg("malloc, array");
	}
	ret->length = 0;
	ret->size = initialSize;

	return ret;
}

/*adds a character to at the end of str*/
void addChar(string * str, char c){

	//increase size of string if needed
	if(str->length >= str->size){
		char * temp;
		if((temp = malloc(sizeof(char) * (str->size + 2))) == NULL){
			exitProg("malloc, addChar");
		}

		strncpy(temp, str->array, str->length);
		free(str->array);
		str->array = temp;
		str->size+=2;
	}

	str->array[str->length] = c;
	str->length++;
}

/*returns the character stored in str at position
on success, null on error*/
char getPos(string * str, int position){

	char ret = '\0';

	if (position < str->length)
		ret = str->array[position];
	else
		ret = '\0';

	return ret;
}

/*adds src to the end of dest. Returns 0 or -1 on error*/
int appendString(string * dest, string * src){

	char * temp;
	if ((temp = malloc(sizeof(char) * (dest->length + src->length))) == NULL){
		exitProg("malloc, append");
	}

	strncpy(temp, dest->array, dest->length);
	strncpy(temp+dest->length, src->array, src->length);

	free(dest->array);
	dest->array = temp;
	dest->size = (dest->length + src->length);
	dest->length = (dest->length + src->length);

	return 0;
}

/*returns the length of str, not including the null byte*/
int lengthString(string * str){

	return str->length;
}

/*swaps characters at pos1 and pos2 of str. Returns 0 or -1 on error*/
int swap(string * str, int pos1, int pos2){
	
	int retVal = 0;

	if (pos1 < str->length && pos2 < str->length){

		char temp = str->array[pos1];
		str->array[pos1] = str->array[pos2];
		str->array[pos2] = temp;

	}else{
		retVal = -1;
	}

	return retVal;
}

/*fills the char * dest with the array of chars in str. Adds a \0 to the end*/
void getCString(string * str, char * dest){

	int i = 0;

	while((*dest++ = str->array[i])){
		i++;
	}
}

/*appends C src onto end of str*/
int catCString(string * str, char * src){

	int i = 0;

	while(src[i] != '\0'){
		addChar(str, src[i]);
		i++;
	}

	return 0;
}