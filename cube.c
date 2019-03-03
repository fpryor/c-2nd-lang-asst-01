//
// Created by Frank Pryor on 2019-03-02.

int ***data_cube;

// allocate 1st dimension
data_cube = (int ***) malloc(sizeof(int **) * 11);

// allocate 2nd dimension
for (int i=0; i<11; i++)
data_cube[i] = (int **) malloc(sizeof(int *) * 11);

// allocate 3rd dimension
for (int i=0; i<11; i++)
for (int j=0; j<11; j++)
data_cube[i][j] = (int *) malloc(sizeof(int) * 11);

// use the data cube...

//data_cube[0][0]=99.0;
//printf("%f\n", data_cube[0][0]);

// free 3rd dimension
for (int i=0; i<11; i++)
for (int j=0; j<11; j++)
free(data_cube[i][j]);

// free 2nd dimension
for (int i=0; i<11; i++)
free(data_cube[i]);

// free 1st dimension
free(data_cube);

