//
// Created by Frank Pryor on 2019-03-02.
//
int global_i = 9;
int global_j = 11;


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
    printf("%d\n\n", global_i);
}


int will_return_it_changed(int argument_j) {
    return argument_j + 1;
}




