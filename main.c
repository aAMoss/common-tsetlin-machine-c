// main.c

#include "main.h"









int print_ta_state(int tm[CLAUSES][LITERALS]);

void print_tm_input(int input[LITERALS]);

void print_clause_values(int input[CLAUSES]);





int print_ta_state(int tm[CLAUSES][LITERALS])
{

    for(int i = 0; i < CLAUSES; i++)
    {

         printf("Clause: %d\t TA States: ", i);
        for(int j = 0; j < LITERALS; j++)
        {

            printf("%d  ", tm[i][j]);

        }
        
        printf("\n");

    }



    return SUCCESS;
}



void print_tm_input(int input[LITERALS])
{

    printf("TM Input Sample:\t");
    for(int i = 0; i < FEATURES; i++)
    {
        printf("%d", input[i]);

    }

    printf(" ");

    for(int i = FEATURES; i < LITERALS; i++)
    {
        printf("%d", input[i]);

    }
    printf("\n");

}



void print_clause_values(int input[CLAUSES])
{

    for(int i = 0; i < CLAUSES; i++)
    {
        printf("Clause: %d Value: %d\n", i, input[i]);
    }
    
}






int main(void)
{
    srand(time(NULL));

    read_input_file(Input_Sample_File, TrainDataInput, TRAIN_DATA);
    read_input_file(Input_Sample_File, TestDataInput, TEST_DATA);
    puts("Training and Testing Data aquired!");
    
    make_bool_literals(TrainDataInput, TrainingLiterals, TrainClass);
    make_bool_literals(TestDataInput, TestingLiterals, TestClass);
    puts("Training and Testing Literals acquired!");
    
    init_tsetlin_machine(tm);
    puts("TA States initialised!");

    fetch_input_data(TrainingLiterals, tm_input);
    //fetch_input_data(TestingLiterals, tm_input);
    puts("Input Data!");
   
    conjunction(tm, tm_input, clause_values);
    summation(clause_values, &sum);
    threshold(&sum, &tm_output);

    //print_input(TrainDataInput);
    //print_input(TestDataInput);
    //print_literals(TrainingLiterals, TrainClass);
    //print_literals(TestingLiterals, TestClass);
    //print_ta_state(tm);
    //print_tm_input(tm_input);
    //print_clause_values(clause_values);
    

    return 0;

}



