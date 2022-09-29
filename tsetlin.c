// tsetlin.c

#include "tsetlin.h"


int tm_input[LITERALS];
int tm[CLAUSES][LITERALS];
int clause_values[CLAUSES];
int sum;
int tm_output;


int init_tsetlin_machine(int tm[CLAUSES][LITERALS])
{

    for(int i = 0; i < CLAUSES; i++)
    {
        for(int j = 0; j < LITERALS; j++)
        {

            tm[i][j] = get_random(TA_MIN, TA_MAX);

        }

    }

    return SUCCESS;

}

int get_random(int min, int max)
{

    int r;

    r = ( rand() % (max + 1 - min) ) + min;


    return r;
}


int fetch_input_data(int data[DATA_SAMPLES][LITERALS], int input[LITERALS])
{
    int min = 0;
    int max = DATA_SAMPLES - 1;
    int r = get_random(min, max);

    for(int i = 0; i < LITERALS; i++)
    {
        input[i] = data[r][i];
    }

    return SUCCESS;
}


int conjunction(int states[CLAUSES][LITERALS], 
                int input[LITERALS], 
                int output[CLAUSES] )
{

    int include = (TA_SIZE/2);
    int running;


    for(int i = 0; i < CLAUSES; i++)
    {
        running = 1;

        for(int j = 0; j < LITERALS; j++)
        {
            if(states[i][j] <= include )
            {
                running &= input[j];
            }
            
        }

        output[i] = running;

    }

    return SUCCESS;
}



int summation(int values[CLAUSES], int *sum)
{

    int total = 0;

    for(int i = 0; i < CLAUSES; i++)
    {
        switch(values[i])
        {
        case 0: total--; break;
        case 1: total++; break;
        default: break;
        }
    }

    *sum = total;

    //printf("SUMMATION: %d\n", total);

    return SUCCESS;
}



int threshold(int *sum, int *tm_output)
{

    if(*sum >= 0)
    {
        *tm_output = 1;
    }else
    {
        *tm_output = 0;
    }

    return SUCCESS;
}
