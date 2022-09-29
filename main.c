// main.c

#include "main.h"




int tm[CLAUSES][LITERALS];


int get_random()
{

    int r;

    r = ( rand() % (TA_MAX + 1 - TA_MIN) ) + TA_MIN;


    return r;
}

int init_tsetlin_machine(int tm[CLAUSES][LITERALS])
{

    for(int i = 0; i < CLAUSES; i++)
    {
        for(int j = 0; j < LITERALS; j++)
        {

            tm[i][j] = get_random();

        }

    }

    return SUCCESS;

}

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



int main(void)
{
    srand(time(NULL));

    read_input_file(Input_Sample_File, TrainDataInput, TRAIN_DATA);
    read_input_file(Input_Sample_File, TestDataInput, TEST_DATA);
    puts("Training and Testing Data aquired!");
    
    make_bool_literals(TrainDataInput, TrainingLiterals, TrainClass);
    // make_bool_literals(TestDataInput, TestingLiterals, TestClass);
    // puts("Training and Testing Literals acquired!");
    
    //init_tsetlin_machine(tm);
    //puts("TA States initialised!");
   
    //print_input(TrainDataInput);
    //print_input(TestDataInput);
    print_literals(TrainingLiterals, TrainClass);
    //print_literals(TestingLiterals, TestClass);
    //print_ta_state(tm);

    return 0;

}





