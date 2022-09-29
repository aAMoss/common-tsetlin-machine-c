// main.c

#include "main.h"

int main(void)
{
    srand(time(NULL));

    read_input_file(Input_Sample_File, TrainDataBools, TRAIN_DATA);
    read_input_file(Input_Sample_File, TestDataBools, TEST_DATA);
    puts("Training and Testing Data aquired!");
    
    make_bool_literals(TrainDataBools, TrainingLiterals);
    make_bool_literals(TestDataBools, TestingLiterals);
    puts("Training and Testing Literals acquired!");
    

    
   
    //print_input(TrainDataBools);
    //print_input(TestDataBools);
    //print_literals(TrainingLiterals);
    //print_literals(TestingLiterals);

    return 0;

}





