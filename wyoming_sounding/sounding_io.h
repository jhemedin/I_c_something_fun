// Sounding IO procedures //
typedef struct Sounding {
   float *height;
   float *temperature;
   float *pressure;
   float *wspeed;
   float *wdir;
   float *dewpoint;
   float *RH;
   float *mixing_ratio;
   float *theta;
   float *theta_e;
   float *theta_v;
   int num_entries;
} Sounding;

int num_lines(char *file_name);
Sounding get_sounding(char *file_name);
void kill_sounding(Sounding sounding);
