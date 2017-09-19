#ifndef STRING_H
#define STRING_H

typedef struct string_s
{
	char * array;
	int size;
	int length;
	
} string;

/*string.c specific protoypes*/
string * newString(int initialSize);
void addChar(string * str, char c);
char getPos(string * str, int position);
int appendString(string * dest, string * src);
int lengthString(string * str);
int swap(string * str, int pos1, int pos2);
void getCString(string * str, char * dest);
int catCString(string * str, char * src);

#endif