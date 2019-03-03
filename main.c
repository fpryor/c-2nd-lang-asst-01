//
// Created by Frank Pryor on 2019-02-21.
//
#include <stdlib.h>
#include <stdio.h>
#include "part1_2.c"



// Part 1.ii  //
void part1_2();

// Part 3
void part3();

// Part 1.iii  //
void part1_3();



int main() {
    // 4. Memory allocation //

    int *array_size = (int *) malloc(sizeof(int));
    int size = 9;


    if (array_size == NULL) {
        printf("ERROR: Memory allocation failed!\n");
        return 1;
    } else {
        *array_size = 11;
    }

    // explicit allocation on heap
    int *int_array = (int *) malloc(*array_size * sizeof(int));

    // check

    if (int_array == NULL) {
        printf("ERROR: Memory allocation failed!\n");
        return 0;
    } else {
        for (int i = 0; i < *array_size; i ++) {
            int_array[i] = i * 3 + *array_size;
            printf("Array element %d holds %d\n", i, int_array[i]);
        }
    }

    // free allocated memory
    free(array_size);
    array_size = NULL;

    free(int_array);
    int_array = NULL;



            // Part 1. Pointers //
    int a = 33;
    int *pa = &a;

    a +=2;
    *pa += 2;
    printf("\nThe value of a is %d\n", a);

    int i = 19;
    int *p = &i;
    *p = 21;
    int **pt = &p;
    **pt += 15;
    printf("The value of i is now %d\n", i);

    float x = 3.3;
    float *f = &x;
    *f += 1;
    printf("x is %f\n", x);

    char * name = "mika";
    printf("my name is %s\n\n", name);


    // Part 1.ii  //
    part1_2();

    // Part 3
    part3();

    // Part 1.iii  //
    part1_3();


    double ***data_cube;

// allocate 1st
    data_cube = (double ***) malloc(sizeof(double **) * 10);

// allocate 2nd
    for (int i=0; i<10; i++)
        data_cube[i] = (double **) malloc(sizeof(double *) * 10);


// allocate 3rd
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            data_cube[i][j] = (double *) malloc(sizeof(double) * 10);

// use the data cube...
    data_cube = (0, 0, 0, 3.3, 0, 0, 0, 0, 0, 0);
    data_cube[i] = (0, 0, 0, 7, 0, 0, 0, 0, 0, 0);



// free 3rd
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            free(data_cube[i][j]);

// free 2nd
    for (int i=0; i<10; i++)
        free(data_cube[i]);

// free 1st
    free(data_cube);








        return 0;
}


// Part 1.ii  //



void swap_ends(int karray[], int size) {


    int tmp = karray[0];
    karray[0] = karray[size - 1];
    karray[size - 1] = tmp;
}


void part3() {
    int narray[] = {3, 4, 7, 1, 23};

    printf("Start: %d; End: %d\n", narray[0], narray[4]);
    swap_ends(narray, 5);
    printf("Start: %d; End: %d\n\n", narray[0], narray[4]);
}


void part1_3() {
    printf("%d\n", global_j);
    global_j = will_return_it_changed(global_j);
    printf("%d\n", global_j);


// Part 2. Array Duality //

// integer array //
    int iarray[10];

    int iarray_size = sizeof(iarray) / sizeof(iarray[0]);
// loop that zeroes out the array
    for (int i = 0; i < 10; i ++) {
        iarray[i] = 0;
    }
// loop that fills in second half of array with 1's
    for (int i = 5; i < 10; i ++) {
        iarray[i] = 1;
    }
    iarray[6] = 7;

//  explicitly
    int *jarr = iarray;
    jarr[6] = jarr[6] + 1;

    int jarr_size = sizeof(*jarr);

    // print commands for integer array
    printf("The value of the 5th element of the integer array is %d\n",iarray[4]);
    printf("The value of the 6th element of the integer array is %d\n",iarray[5]);
    printf("The value of the 7th element of the integer array is %d\n",iarray[6]);
    printf("the size of jarr is %d\n", jarr_size);
    printf("the number of elements in integer array is %d\n\n", iarray_size);




// literal array assignment for float array //
    float farray[] = { 0.5, 8.6 };

    // add 1 to the value of each float array element
    for (int i = 0; i < 2; i ++) {
        farray[i] = farray[i] + 1;
    }
    // print the float array
    printf("here's the float array: \n");
    for (int i = 0; i < 2; i ++) {
        printf("%f\n", farray[i]);
    }


// character array //
    char cstring[] = "abracadabra";

    int cstring_size = (sizeof(cstring) / sizeof(cstring[0]) - 1);

    // print info about string
    printf("\nnumber of letters in abracadabra is %d\n\n", cstring_size);



// 4. Structures

struct tape_collection {
    char artist[28];
    char title[28];
    int rating;
};

struct tape_collection tr4 = {"TENTENKO", "ROBOT", 4};
struct tape_collection pe3 = {"Phantogram", "Eyelid Movies", 3};
struct tape_collection pa2 = {"Plebian", "Atrium", 2};
struct tape_collection bd5 = {"Bright Eyes", "Digital Ash in a Digital Urn", 5};
struct tape_collection nt5 = {"Nmesh & TELEPATH", "(The Path to Lost Eden)", 5};

printf("Current Rotation: \n");
printf("%s - %s - %d stars \n", tr4.artist,
                                tr4.title,
                                tr4.rating);
printf("%s - %s - %d stars \n", pe3.artist,
                                pe3.title,
                                pe3.rating);
printf("%s - %s - %d stars \n", pa2.artist,
                                pa2.title,
                                pa2.rating);
printf("%s - %s - %d stars \n", bd5.artist,
                                bd5.title,
                                bd5.rating);
printf("%s - %s - %d stars \n", nt5.artist,
                                nt5.title,
                                nt5.rating);


}
