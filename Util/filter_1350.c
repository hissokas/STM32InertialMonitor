#include "filter_1350.h"

static const float filter_taps[SAMPLEFILTER_TAP_NUM_1350] = {
  0.000922491119311192,
  0.0000471064217270049,
  -0.0000331939370553374,
  -0.0001731116564778564,
  -0.00038378375687846405,
  -0.000672180767855017,
  -0.001043113479354036,
  -0.001500819030968005,
  -0.0020480570454910487,
  -0.0026841084296992754,
  -0.003403948821654414,
  -0.004198510967451023,
  -0.005054653017377225,
  -0.00595463171548564,
  -0.00687592653921615,
  -0.007791636551778721,
  -0.008670912044749299,
  -0.00947927055644102,
  -0.01017921640747466,
  -0.010731305705895729,
  -0.011095322371019584,
  -0.011231391111014656,
  -0.011101210263763303,
  -0.010669469219375657,
  -0.009905233426848395,
  -0.008783172877128768,
  -0.0072847398989903936,
  -0.005399326304047047,
  -0.0031252331957176056,
  -0.00047034011116669285,
  0.002547476376836995,
  0.005900155943569931,
  0.009549596158569982,
  0.0134481683745037,
  0.01753953370644554,
  0.021759706079871433,
  0.026038391680058285,
  0.0303006019943614,
  0.03446845699563725,
  0.03846310829464802,
  0.042206761587171515,
  0.045624750122266425,
  0.048647560381364544,
  0.05121272931272345,
  0.053266571492432885,
  0.05476568505176784,
  0.05567817015371276,
  0.055984520083872995,
  0.05567817015371276,
  0.05476568505176784,
  0.053266571492432885,
  0.05121272931272345,
  0.048647560381364544,
  0.045624750122266425,
  0.042206761587171515,
  0.03846310829464802,
  0.03446845699563725,
  0.0303006019943614,
  0.026038391680058285,
  0.021759706079871433,
  0.01753953370644554,
  0.0134481683745037,
  0.009549596158569982,
  0.005900155943569931,
  0.002547476376836995,
  -0.00047034011116669285,
  -0.0031252331957176056,
  -0.005399326304047047,
  -0.0072847398989903936,
  -0.008783172877128768,
  -0.009905233426848395,
  -0.010669469219375657,
  -0.011101210263763303,
  -0.011231391111014656,
  -0.011095322371019584,
  -0.010731305705895729,
  -0.01017921640747466,
  -0.00947927055644102,
  -0.008670912044749299,
  -0.007791636551778721,
  -0.00687592653921615,
  -0.00595463171548564,
  -0.005054653017377225,
  -0.004198510967451023,
  -0.003403948821654414,
  -0.0026841084296992754,
  -0.0020480570454910487,
  -0.001500819030968005,
  -0.001043113479354036,
  -0.000672180767855017,
  -0.00038378375687846405,
  -0.0001731116564778564,
  -0.0000331939370553374,
  0.0000471064217270049,
  0.000922491119311192
};

void SampleFilter_init_1350(SampleFilter* f) {
  int i;
  for(i = 0; i < SAMPLEFILTER_TAP_NUM_1350; ++i)
    f->history[i] = 0;
  f->last_index = 0;
}

void SampleFilter_put_1350(SampleFilter* f, float input) {
  f->history[f->last_index++] = input;
  if(f->last_index == SAMPLEFILTER_TAP_NUM_1350)
    f->last_index = 0;
}

float SampleFilter_get_1350(SampleFilter* f) {
  float acc = 0;
  int index = f->last_index, i;
  for(i = 0; i < SAMPLEFILTER_TAP_NUM_1350; ++i) {
    index = index != 0 ? index-1 : SAMPLEFILTER_TAP_NUM_1350-1;
    acc += f->history[index] * filter_taps[i];
  };
  return acc;
}
