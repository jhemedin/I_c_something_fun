// Math for getting u, v wind components //
#include <math.h>
#include <malloc.h>
#include "sounding_io.h"

/* Gets the u component of the wind field. 
  Returns a new pointer to an allocated array.
  */

float deg2rad(float degrees)
{
    return degrees * M_PI/180.0;
}
 
float *get_u(Sounding the_sounding)
{
    float *u;
    int i;
    u = malloc(the_sounding.num_entries*sizeof(float));
    for(i = 0; i < the_sounding.num_entries; i++)
    {
        u[i] = -sin(deg2rad(the_sounding.wdir[i])) * the_sounding.wspeed[i];
    }
    return u;
}

float *get_v(Sounding the_sounding)
{
    float *v;
    int i;
    v = malloc(the_sounding.num_entries*sizeof(float));
    for(i = 0; i < the_sounding.num_entries; i++)
    {
        v[i] = -cos(deg2rad(the_sounding.wdir[i])) * the_sounding.wspeed[i];
    }
    return v;
}    
