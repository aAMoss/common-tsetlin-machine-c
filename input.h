// input.h

#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>


#define SUCCESS 0
#define FAILURE 1

#define CLAUSES 64
#define TA 30

#define S_FEEDBACK 3.9
#define THRESHOLD 15


#define TEST_DATA "./TestDataNoisyXOR.txt"
#define TRAIN_DATA "./TrainDataNoisyXOR.txt"

#define DATA_SAMPLES 5000
#define FEATURES 13 //includes the class number
#define LITERALS (FEATURES * 2)


#define EPOCHS 100





int read_input_file(FILE *fp, int data[DATA_SAMPLES][FEATURES], char *fname);
int make_bool_literals(int input[DATA_SAMPLES][FEATURES], int output[DATA_SAMPLES][LITERALS]);
void print_input(int data[DATA_SAMPLES][FEATURES]);
void print_literals(int data[DATA_SAMPLES][LITERALS]);





#endif //INPUT_H