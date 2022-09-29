// input.c

#include "input.h"

FILE *Input_Sample_File;
 
int TrainDataInput[DATA_SAMPLES][INPUTSIZE];
int TestDataInput[DATA_SAMPLES][INPUTSIZE];
int TestClass[DATA_SAMPLES];
int TrainClass[DATA_SAMPLES];
int TrainingLiterals[DATA_SAMPLES][LITERALS];
int TestingLiterals[DATA_SAMPLES][LITERALS];

int read_input_file(FILE *fp, int data[DATA_SAMPLES][INPUTSIZE], char *fname)
{
    
    char buffer[500];
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

        for(int j = 0; j < INPUTSIZE; j++)
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

void print_input(int data[DATA_SAMPLES][INPUTSIZE])
{
    
    for(int i = 0; i < DATA_SAMPLES; i++)
    {

        printf("Sample %d\t",i);
        
        for(int j = 0; j < INPUTSIZE; j++)
        {
            printf("%d", data[i][j]);
        }

        printf("\n");
    }

}



int make_bool_literals( int input[DATA_SAMPLES][INPUTSIZE], 
                        int output[DATA_SAMPLES][LITERALS], 
                        int class[DATA_SAMPLES])
{

    for(int i = 0; i < DATA_SAMPLES; i++)
    {
        
        class[i] = input[i][FEATURES];
        
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

void print_literals(int data[DATA_SAMPLES][LITERALS], int class[DATA_SAMPLES])
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

        printf("\tClass %d", class[i]);

        printf("\n");
    }

}