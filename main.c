//
// Created by Frank Pryor on 2019-02-21.
//

#include <stdio.h>


int global_i = 9;
int global_j = 11;

// Part 1.ii  //
void part1_2();
// Part 1.iii  //
void part1_3();


int main() {

    // Part 1. Pointers //
    int a = 33;
    int *pa = &a;

    a +=2;
    *pa += 2;
    printf("The value of a is %d\n", a);

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
    printf("my name is %s\n", name);


    // Part 1.ii  //
    part1_2();
    // Part 1.iii  //
    part1_3();

        return 0;
}


// Part 1.ii  //
void wont_change(int argument_i) {
    argument_i = 10;
}


void change_inside(int *pointer_to_global_i) {
    *pointer_to_global_i = 10; // dereference and assign a new value
}

void part1_2() {
    printf("%d\n", global_i);
    wont_change(global_i);
    printf("%d\n", global_i);
    change_inside(&global_i);
    printf("%d\n", global_i);
}



int will_return_it_changed(int argument_j) {
    return argument_j + 1;
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
    iarray[6] = 7;  // the type of 'iarray[5]' is integer (int)
    // the indexing is equivalent to dereferencing
    // (including the step calculation laid out above)

//  explicitly
    int *jarr = iarray;
    jarr[6] = jarr[6] + 1;

    int jarr_size = sizeof(*jarr);
// once an array had "degenerated" to a pointer, the
// `sizeof(jarr)` expression will only return the size of the
// pointer in bytes (most probably 4)


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
    printf("number of letters in abracadabra is %d\n", cstring_size);





}