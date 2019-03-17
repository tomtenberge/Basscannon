#include "bassFilter.h"

static int filter_taps[BASSFILTER_TAP_NUM] = {
  286,
  160,
  -305,
  -1183,
  -2063,
  -2224,
  -1020,
  1639,
  5045,
  7919,
  9044,
  7919,
  5045,
  1639,
  -1020,
  -2224,
  -2063,
  -1183,
  -305,
  160,
  286
};

void bassFilter_init(bassFilter* f) {
  int i;
  for(i = 0; i < BASSFILTER_TAP_NUM; ++i)
    f->history[i] = 0;
  f->last_index = 0;
}

void bassFilter_put(bassFilter* f, int input) {
  f->history[f->last_index++] = input;
  if(f->last_index == BASSFILTER_TAP_NUM)
    f->last_index = 0;
}

int bassFilter_get(bassFilter* f) {
  long long acc = 0;
  int index = f->last_index, i;
  for(i = 0; i < BASSFILTER_TAP_NUM; ++i) {
    index = index != 0 ? index-1 : BASSFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[i];
  };
  return acc >> 16;
}
