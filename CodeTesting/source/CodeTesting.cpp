#include <cstddef>
#include <cstring> // std::strcmp
#include <cstdlib> // std::rand, std::srand

#include <iostream>
#include <algorithm> // std::generate

#include "SortsHelper.h"

#define SIZE 10000

int compareString(const void* stringA, const void* stringB);
void printStringArray(char *array[], int length);


int compareInt(const void* intA, const void* intB);
void printIntArray(int *array, int length);

void populateRandCString(char *s, int length);
char* randomCString();


//currently used to test swap macro
int main(int argc, char *argv[]) {

    int intToOder[SIZE];
    char* stringToOrder[SIZE];

    std::generate(intToOder, intToOder + SIZE, std::rand);
    std::generate(stringToOrder, stringToOrder + SIZE, randomCString);

    int length = 6;

    std::cout << "\nbefore sort:" << std::endl;
    printIntArray(intToOder, SIZE);

    selectSortStable(intToOder, SIZE, sizeof(int), compareInt);

    std::cout << "\n\nafter sort:" << std::endl;
    printIntArray(intToOder, SIZE);


    std::cout << "\n\nbefore sort:" << std::endl;
    printStringArray(stringToOrder, SIZE);

    selectSortStable(stringToOrder, SIZE, sizeof(char*), compareString);

    std::cout << "\n\nafter sort:" << std::endl;
    printStringArray(stringToOrder, SIZE);

    for(int i = 0; i < SIZE; i++) {

        // created with malloc
        std::free(stringToOrder[i]);
    }
}


int compareInt(const void* intA, const void* intB) {

    int a = *(int*)intA;
    int b = *(int*)intB;

    if (a < b) {
//        printf("\ncompare return: %d\n", -1);
        return -1;
    }
    else if (a == b) {
//        printf("\ncompare return: %d\n", 0);
        return 0;
    }
    else {
//        printf("\ncompare return: %d\n", 1);
        return 1;
    }
}

void printIntArray(int *array, int length) {

    if (length > 0) {

        std::cout << array[0];

        int index = 1;

        while (index != length) {

            std::cout << " " << array[index];
            index++;
        }
        std::cout << std::endl;
    }
}

int compareString(const void* stringA, const void* stringB) {

    int value =  std::strcmp(*((char**)stringA),*((char**)stringB));

//    printf("\ncompare return: %d\n", value);

    return value;
}

void printStringArray(char* array[], int length) {

    if (length > 0) {

        std::cout << array[0];

        int index = 1;

        while (index != length) {

            std::cout << " " << array[index];
            index++;
        }

        std::cout << std::endl;
    }
}

void populateRandCString(char *s, const int length) {
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < length; ++i) {
        s[i] = alphanum[std::rand() % (sizeof(alphanum) - 1)];
    }

    s[length] = 0;
}

char* randomCString() {

    int minLength = 1;
    int maxLength = 6;

    int length = minLength + (std::rand() % maxLength - minLength + 1);

    char* randCString = (char*) malloc(sizeof(char) * (length + 1));

    populateRandCString(randCString, length);

    return randCString;
}

