/* This file takes in the dewpoint and temperature from a University of Wyoming 
   sounding and calculates the mixing ratio */

#include <stdio.h>
#include <stdlib.h>
#include "sounding_io.h"
#include "conversion.h"


int main(int argc, char **argv)
{
    Sounding input_sounding;
    float *u, *v;
    int i;

    if(argc < 2)
    {
        printf("Arguments: %s [sounding_name]\n", argv[0]);
        return -1;
    }
    
    printf("## Loading sounding...\n");
    input_sounding = get_sounding(argv[1]);
    u = get_u(input_sounding);
    v = get_v(input_sounding);
    printf("## Values of U with height:\n");

    for(i = 0; i < input_sounding.num_entries; i++)
    {
        printf("ALT: %6.2f U:%4.2f V:%4.2f\n", input_sounding.height[i],
               u[i], v[i]);
    }
    // Garbage collection - Must always be done for allocated arrays in C
    // C will only automatically remove from memory
    kill_sounding(input_sounding);
    free(u);
    free(v);
}
