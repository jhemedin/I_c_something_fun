#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "sounding_io.h"

int num_lines(char *file_name)
{
    FILE *file_ptr;
    char line[80];
    int num_lines = 0;

    file_ptr = fopen(file_name, "r");
    if(file_ptr == NULL) {
        perror("Error opening file.");
    }
    
    while(fgets(line, 80, file_ptr) != NULL)
    {
        num_lines++;
    }
    fclose(file_ptr);
    
    return num_lines;
}

// Gets a new Sounding structure from a sounding file //     
Sounding get_sounding(char *file_name)
{
    FILE *file_ptr;
    int n_elements, i;
    char line[80];
    Sounding out_sounding;

    file_ptr = fopen(file_name, "r");
    n_elements = num_lines(file_name)-5;

    // Allocate our arrays
    out_sounding.height = malloc(n_elements*sizeof(float));
    out_sounding.temperature = malloc(n_elements*sizeof(float));
    out_sounding.pressure = malloc(n_elements*sizeof(float));
    out_sounding.wspeed = malloc(n_elements*sizeof(float));
    out_sounding.wdir = malloc(n_elements*sizeof(float));
    out_sounding.dewpoint = malloc(n_elements*sizeof(float));
    out_sounding.RH = malloc(n_elements*sizeof(float));
    out_sounding.mixing_ratio = malloc(n_elements*sizeof(float));
    out_sounding.theta = malloc(n_elements*sizeof(float));
    out_sounding.theta_e = malloc(n_elements*sizeof(float));
    out_sounding.theta_v = malloc(n_elements*sizeof(float));
    out_sounding.num_entries = n_elements;

    // Skip first 4 lines
    for(i = 0; i < 4; i++)
    {
        fgets(line, 80, file_ptr);
    }
    
    // First line of sounding only has pressure and height
    fscanf(file_ptr, "%f", &out_sounding.pressure[0]);
    fscanf(file_ptr, "%f", &out_sounding.height[0]);
    out_sounding.temperature[0] = NAN;
    out_sounding.wspeed[0] = NAN;
    out_sounding.wdir[0] = NAN;
    out_sounding.dewpoint[0] = NAN;
    out_sounding.RH[0] = NAN;
    out_sounding.mixing_ratio[0] = NAN;

    for(i = 0; i < n_elements; i++)
    {
        fscanf(file_ptr, "%f", &out_sounding.pressure[i]);
        fscanf(file_ptr, "%f", &out_sounding.height[i]);
        fscanf(file_ptr, "%f", &out_sounding.temperature[i]);
        fscanf(file_ptr, "%f", &out_sounding.dewpoint[i]);
        fscanf(file_ptr, "%f", &out_sounding.RH[i]);
        fscanf(file_ptr, "%f", &out_sounding.mixing_ratio[i]);
        fscanf(file_ptr, "%f", &out_sounding.wdir[i]);
        fscanf(file_ptr, "%f", &out_sounding.wspeed[i]);
        fscanf(file_ptr, "%f", &out_sounding.theta[i]);
        fscanf(file_ptr, "%f", &out_sounding.theta_e[i]);
        fscanf(file_ptr, "%f", &out_sounding.theta_v[i]);
    }
   
    return out_sounding;
}


// Remove sounding from memory (garbage collection)
void kill_sounding(Sounding sounding)
{
    free(sounding.height);
    free(sounding.temperature);
    free(sounding.pressure);
    free(sounding.wspeed);
    free(sounding.wdir);
    free(sounding.dewpoint);
    free(sounding.RH);
    free(sounding.mixing_ratio);
    free(sounding.theta);
    free(sounding.theta_e);
    free(sounding.theta_v);
}

