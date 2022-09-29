// main.h


#ifndef MAIN_H
#define MAIN_H

#include "input.h"


//extern variables

extern FILE *Input_Sample_File;
extern int TrainDataInput[DATA_SAMPLES][INPUTSIZE];
extern int TestDataInput[DATA_SAMPLES][INPUTSIZE];
extern int TestClass[DATA_SAMPLES];
extern int TrainClass[DATA_SAMPLES];
extern int TrainingLiterals[DATA_SAMPLES][LITERALS];
extern int TestingLiterals[DATA_SAMPLES][LITERALS];




#endif //MAIN_H