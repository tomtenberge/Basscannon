#ifndef BASSFILTER_H_
#define BASSFILTER_H_

/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 1700 Hz

fixed point precision: 16 bits

* 0 Hz - 200 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 300 Hz - 850 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

*/

#define BASSFILTER_TAP_NUM 21

typedef struct {
  int history[BASSFILTER_TAP_NUM];
  unsigned int last_index;
} bassFilter;

void bassFilter_init(bassFilter* f);
void bassFilter_put(bassFilter* f, int input);
int bassFilter_get(bassFilter* f);

#endif