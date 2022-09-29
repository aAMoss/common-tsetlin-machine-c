// main.h


#ifndef MAIN_H
#define MAIN_H

#include "input.h"
#include "tsetlin.h"


//extern variables
//________________________________________________

extern FILE *Input_Sample_File;
extern int TrainDataInput[DATA_SAMPLES][INPUTSIZE];
extern int TestDataInput[DATA_SAMPLES][INPUTSIZE];
extern int TestClass[DATA_SAMPLES];
extern int TrainClass[DATA_SAMPLES];
extern int TrainingLiterals[DATA_SAMPLES][LITERALS];
extern int TestingLiterals[DATA_SAMPLES][LITERALS];

//________________________________________________

extern int tm_input[LITERALS];
extern int tm[CLAUSES][LITERALS];
extern int clause_values[CLAUSES];
extern int sum;
extern int tm_output;

#endif //MAIN_H