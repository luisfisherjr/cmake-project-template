#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "SortsHelper.h"

#include <string>
#include <iostream>
#include <cstring>


int compareString(const void* stringA, const void* stringB);
void printStringArray(char *array[], int length);


int compareInt(const void* intA, const void* intB);
void printIntArray(int *array, int length);


//currently used to test swap macro
int main(int argc, char *argv[]) {

    int a[] = {1,20,10,5,100,12};

    int length = 6;

    printf("\nbefore sort: ");
    printIntArray(a, length);

    quickSort((int*)a, length, sizeof(int), compareInt);

    printf("\n\nafter sort: ");
    printIntArray(a, length);
    printf("\n");

    char* toOrder[] = {
            "cat",
            "hat",
            "boo",
            "zoo",
            "feather",
            "leather",
            "cool",
            "aARASDSXZCEDFSAWCEQ!XDSZVFZFECZEDZACasdaaxdadwdDSGSZVDSVZ",
            "hello",
            "fellow",
    };

    length = 10;

    printf("\nbefore sort: ");

    printStringArray(toOrder, length);

    quickSort((char**)toOrder, length, sizeof(char*), compareString);

    printf("\nafter sort: ");

    printStringArray(toOrder, length);
}


int compareInt(const void* intA, const void* intB) {

    int value =  *(int*)intA - *(int*)intB;

    printf("\ncompare return: %d\n", value);

    return value;
}

void printIntArray(int *array, int length) {

    if (length > 0) {

        printf("%d ", array[0]);

        int index = 1;

        while (index != length) {

            printf("%d ", array[index]);
            index++;
        }
    }
}

int compareString(const void* stringA, const void* stringB) {

    int value =  strcmp(*((char**)stringA),*((char**)stringB));

    printf("\ncompare return: %d\n", value);

    return value;
}

void printStringArray(char* array[], int length) {

    if (length > 0) {

        std::cout << array[0] << " ";

        int index = 1;

        while (index != length) {

            std::cout << array[index] << " ";
            index++;
        }

        std::cout << std::endl;
    }
}

//// qsort() in Array of Pointer to String
//
//#include<stdio.h>
////#include<conio.h>
//#include<stdlib.h>
//#include<string.h>
//int cmp(const void *, const void *);
//
//int main(void)
//{
//    char *s[] = {
//            "Gaurav",
//            "Vaibhav",
//            "Garima",
//            "Amit"
//    };
//
//    qsort( (char**)s, 4 , sizeof(char*), cmp);
//
//    int i = 0;
//    while(i<4)
//    {
//        printf("\t%s\n",s[i]);
//        i++;
//    }
//
//    getchar();
//}
//
//int cmp(const void *x, const void *y)
//{
//    return(strcmp(*(char**)x,*(char**)y));
//}