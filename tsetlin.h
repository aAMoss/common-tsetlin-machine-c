// tsetlin.h

#ifndef TSETLIN_H
#define TSETLIN_H

#include "input.h"

int get_random(int min, int max);
int init_tsetlin_machine(int tm[CLAUSES][LITERALS]);
int fetch_input_data(int data[DATA_SAMPLES][LITERALS], int input[LITERALS]);
int conjunction(int states[CLAUSES][LITERALS], 
                int input[LITERALS], 
                int output[CLAUSES] );
int summation(int values[CLAUSES], int *sum);
int threshold(int *sum, int *tm_output);

#endif //TSETLIN_H