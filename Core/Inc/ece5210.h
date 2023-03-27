#ifndef ECE5210_H
#define ECE5210_H

#include <stdint.h>

#define PASSTHROUGH_RIGHT

int16_t fir_fixed(int16_t sample_in, uint16_t len_h);
void init_firwin(void);
int16_t process_sample(int16_t sample_in);

#endif
