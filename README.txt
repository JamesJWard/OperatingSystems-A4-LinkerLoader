James Ward
Assignment 4, makefiles
Operating Systems Spring 2016

This collection of files are held together through included headers. Various functions are called outside of the original file. The demonstration of this is done with an implementation of the string collection popular in java. 

Below is a sample make and run of the program:

james@SgtSarcasm:~/Documents/OS/JWARD_A4$ make clean
rm *.o prog

james@SgtSarcasm:~/Documents/OS/JWARD_A4$ ls
a4.c  a4.h  makefile  sort.c  sort.h  string.c  string.h

james@SgtSarcasm:~/Documents/OS/JWARD_A4$ make
gcc -Wall   -c -o a4.o a4.c
gcc -Wall   -c -o sort.o sort.c
gcc -Wall   -c -o string.o string.c
gcc -Wall -o prog a4.o sort.o string.o

james@SgtSarcasm:~/Documents/OS/JWARD_A4$ ./prog
2 strings created:
>s1 size: 20 length: 0
>s2 size: 20 length: 0

>adding 25 z's to s1
>s1:zzzzzzzzzzzzzzzzzzzzzzzzz

>adding 30 chars's to s2
>s2:JIHGFEDCBA@?>=<;:9876543210/.-

>s1 appeneded with s2
zzzzzzzzzzzzzzzzzzzzzzzzzJIHGFEDCBA@?>=<;:9876543210/.-

>AZXgTaIJ appeneded to s2
JIHGFEDCBA@?>=<;:9876543210/.-AZXgTaIJ

>sort s2
>UNSORTED: JIHGFEDCBA@?>=<;:9876543210/.-AZXgTaIJ
>SORTED: -./0123456789:;<=>?@AABCDEFGHIIJJTXZag

Final strings stats:
>s1 size: 55 length: 55
>s2 size: 38 length: 38


