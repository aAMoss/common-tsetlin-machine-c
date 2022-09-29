// input.h

#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>

//_________________________________________________________

#define TEST_DATA "./TestDataNoisyXOR.txt"
#define TRAIN_DATA "./TrainDataNoisyXOR.txt"

#define DATA_SAMPLES 5000
#define INPUTSIZE 13 //include bools for class label
#define FEATURES 12 

#define CLAUSES 64
#define TA_SIZE 30
#define S_FEEDBACK 3.9
#define THRESHOLD 15

#define EPOCHS 100

//_________________________________________________________

#define TA_MAX (TA_SIZE)
#define TA_MIN 1
#define CLASSBOOLS (INPUTSIZE - FEATURES)
#define LITERALS (FEATURES * 2)


#define SUCCESS 0
#define FAILURE 1



int read_input_file(FILE *fp, int data[DATA_SAMPLES][INPUTSIZE], char *fname);
int make_bool_literals( int input[DATA_SAMPLES][INPUTSIZE], 
                        int output[DATA_SAMPLES][LITERALS], 
                        int class[DATA_SAMPLES]);
void print_input(int data[DATA_SAMPLES][INPUTSIZE]);
void print_literals(int data[DATA_SAMPLES][LITERALS], int class[DATA_SAMPLES]);





#endif //INPUT_H