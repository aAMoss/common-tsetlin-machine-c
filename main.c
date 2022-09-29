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



//FILE *Train_Sample_File;
FILE *Input_Sample_File;
 
int TrainDataBools[DATA_SAMPLES][FEATURES];
int TestDataBools[DATA_SAMPLES][FEATURES];

int TrainingLiterals[DATA_SAMPLES][LITERALS];
int TestingLiterals[DATA_SAMPLES][LITERALS];

int read_input_file(FILE *fp, int data[DATA_SAMPLES][FEATURES], char *fname);
int make_bool_literals(int input[DATA_SAMPLES][FEATURES], int output[DATA_SAMPLES][LITERALS]);
void print_input(int data[DATA_SAMPLES][FEATURES]);
void print_literals(int data[DATA_SAMPLES][LITERALS]);


int read_input_file(FILE *fp, int data[DATA_SAMPLES][FEATURES], char *fname)
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

void print_input(int data[DATA_SAMPLES][FEATURES])
{
    
    for(int i = 0; i < DATA_SAMPLES; i++)
    {

        printf("Sample %d\t",i);
        
        for(int j = 0; j < FEATURES; j++)
        {
            printf("%d", data[i][j]);
        }

        printf("\n");
    }

}



int make_bool_literals(int input[DATA_SAMPLES][FEATURES], int output[DATA_SAMPLES][LITERALS])
{

    for(int i = 0; i < DATA_SAMPLES; i++)
    {
       
        for(int j = 0; j < FEATURES; j++)
        {   
     
            switch(input[i][j])
            {
                case 0: output[i][j] = 0; output[i][j+FEATURES] = 1; break;
                case 1: output[i][j] = 1; output[i][j+FEATURES] = 0; break;
                default: break;
            }
   
            //printf("Sample %d Feature %d Input %d Comp %d\n", i, j, input[i][j], output[i][j+FEATURES]);
            
        }

    }

    return SUCCESS;
}

void print_literals(int data[DATA_SAMPLES][LITERALS])
{
    
    for(int i = 0; i < DATA_SAMPLES; i++)
    {
        printf("Sample %d\t",i);

        for(int j = 0; j < FEATURES; j++)
        {
            printf("%d", data[i][j]);
        }

        printf(" ");

        for(int j = FEATURES; j < LITERALS; j++)
        {
            printf("%d", data[i][j]);
        }

        printf("\n");
    }

}

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

