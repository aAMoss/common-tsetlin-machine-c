#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h> 


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



#define EPOCHS 100



FILE *Train_Sample_File;
FILE *Test_Sample_File;
 
int TrainDataBools[DATA_SAMPLES][FEATURES];
int TestDataBools[DATA_SAMPLES][FEATURES];

int get_input_bools(FILE *fp, int data[DATA_SAMPLES][FEATURES], char *fname)
{
    
    char buffer[256];
    int b;
    char *token = NULL;
    const char *s = " ";

    fp = fopen(fname, "r");
    
    if(!fp) 
    {
        perror("File opening failed\n");
        return EXIT_FAILURE;
    }

    rewind(fp);

    for(int i = 0; i < DATA_SAMPLES; i++ )
    {
        fgets(buffer, sizeof(buffer), fp);
        
        token = strtok(buffer, s);

        for(int j = 0; j < FEATURES; j++)
        {
            sscanf(token, "%d", &b);
            //printf("%d\n",b);
            data[i][j] = b;

            token = strtok(NULL,s);
        }
    }

    fclose(fp);

    return SUCCESS;
}

void print_data(int data[DATA_SAMPLES][FEATURES])
{

    for(int i = 0; i < DATA_SAMPLES; i++)
    {
        for(int j = 0; j < FEATURES; j++)
        {
            printf("%d", data[i][j]);
        }

        printf("\n");
    }


}


int main(void)
{

    if( get_input_bools(Train_Sample_File, TrainDataBools, TRAIN_DATA) != 1 )
    {
        puts("Training data, acquired!");
    }
    if( get_input_bools(Test_Sample_File, TestDataBools, TEST_DATA) != 1 )
    {
         puts("Test data, acquired!");
    }

    //print_data(TrainDataBools);
    //print_data(TestDataBools);

    
    return 0;

}



int make_literal_bools()
{



}




int init_tsetlin_machine()
{




}

int compute_clause()
{





}

int feedback_type1()
{


}

 int feedback_type2()
{

    
}

