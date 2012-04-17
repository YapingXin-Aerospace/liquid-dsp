/*
 * Copyright (c) 2007, 2009, 2012 Joseph Gaeddert
 * Copyright (c) 2007, 2009, 2012 Virginia Polytechnic Institute & State University
 *
 * This file is part of liquid.
 *
 * liquid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * liquid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with liquid.  If not, see <http://www.gnu.org/licenses/>.
 */

//
// fft_composite_benchmark.c : benchmark FFTs of 'composite' length (not
//   prime, not of form 2^m)
//

#include <stdlib.h>
#include <stdio.h>
#include <sys/resource.h>
#include "liquid.h"

#define FFT_COMPOSITE_BENCH_API(NFFT,D) \
(   struct rusage *_start,              \
    struct rusage *_finish,             \
    unsigned long int *_num_iterations) \
{ fft_composite_bench(_start, _finish, _num_iterations, NFFT, D); }

// Helper function to keep code base small
void fft_composite_bench(struct rusage *     _start,
                         struct rusage *     _finish,
                         unsigned long int * _num_iterations,
                         unsigned int        _nfft,
                         int                 _direction)
{
    // initialize arrays, plan
    float complex * x = (float complex *) malloc(_nfft*sizeof(float complex));
    float complex * y = (float complex *) malloc(_nfft*sizeof(float complex));
    int _method = 0;
    fftplan q = fft_create_plan(_nfft, x, y, _direction, _method);
    
    unsigned long int i;

    // initialize input with random values
    for (i=0; i<_nfft; i++)
        x[i] = randnf() + randnf()*_Complex_I;

    // scale number of iterations to keep execution time
    // relatively linear
    *_num_iterations /= _nfft;

    // start trials
    getrusage(RUSAGE_SELF, _start);
    for (i=0; i<(*_num_iterations); i++) {
        fft_execute(q);
        fft_execute(q);
        fft_execute(q);
        fft_execute(q);
    }
    getrusage(RUSAGE_SELF, _finish);
    *_num_iterations *= 4;

    fft_destroy_plan(q);
    free(x);
    free(y);
}

// composite numbers
void benchmark_fft_6      FFT_COMPOSITE_BENCH_API(     6, FFT_FORWARD)
void benchmark_fft_9      FFT_COMPOSITE_BENCH_API(     9, FFT_FORWARD)
void benchmark_fft_10     FFT_COMPOSITE_BENCH_API(    10, FFT_FORWARD)
void benchmark_fft_12     FFT_COMPOSITE_BENCH_API(    12, FFT_FORWARD)
void benchmark_fft_14     FFT_COMPOSITE_BENCH_API(    14, FFT_FORWARD)
void benchmark_fft_15     FFT_COMPOSITE_BENCH_API(    15, FFT_FORWARD)
void benchmark_fft_18     FFT_COMPOSITE_BENCH_API(    18, FFT_FORWARD)
void benchmark_fft_20     FFT_COMPOSITE_BENCH_API(    20, FFT_FORWARD)
void benchmark_fft_21     FFT_COMPOSITE_BENCH_API(    21, FFT_FORWARD)
void benchmark_fft_22     FFT_COMPOSITE_BENCH_API(    22, FFT_FORWARD)
void benchmark_fft_24     FFT_COMPOSITE_BENCH_API(    24, FFT_FORWARD)
void benchmark_fft_25     FFT_COMPOSITE_BENCH_API(    25, FFT_FORWARD)
void benchmark_fft_26     FFT_COMPOSITE_BENCH_API(    26, FFT_FORWARD)
void benchmark_fft_27     FFT_COMPOSITE_BENCH_API(    27, FFT_FORWARD)
void benchmark_fft_28     FFT_COMPOSITE_BENCH_API(    28, FFT_FORWARD)
void benchmark_fft_30     FFT_COMPOSITE_BENCH_API(    30, FFT_FORWARD)
void benchmark_fft_33     FFT_COMPOSITE_BENCH_API(    33, FFT_FORWARD)
void benchmark_fft_34     FFT_COMPOSITE_BENCH_API(    34, FFT_FORWARD)
void benchmark_fft_35     FFT_COMPOSITE_BENCH_API(    35, FFT_FORWARD)
void benchmark_fft_36     FFT_COMPOSITE_BENCH_API(    36, FFT_FORWARD)
void benchmark_fft_38     FFT_COMPOSITE_BENCH_API(    38, FFT_FORWARD)
void benchmark_fft_39     FFT_COMPOSITE_BENCH_API(    39, FFT_FORWARD)
void benchmark_fft_40     FFT_COMPOSITE_BENCH_API(    40, FFT_FORWARD)
void benchmark_fft_42     FFT_COMPOSITE_BENCH_API(    42, FFT_FORWARD)
void benchmark_fft_44     FFT_COMPOSITE_BENCH_API(    44, FFT_FORWARD)
void benchmark_fft_45     FFT_COMPOSITE_BENCH_API(    45, FFT_FORWARD)
void benchmark_fft_46     FFT_COMPOSITE_BENCH_API(    46, FFT_FORWARD)
void benchmark_fft_48     FFT_COMPOSITE_BENCH_API(    48, FFT_FORWARD)
void benchmark_fft_49     FFT_COMPOSITE_BENCH_API(    49, FFT_FORWARD)
void benchmark_fft_50     FFT_COMPOSITE_BENCH_API(    50, FFT_FORWARD)
void benchmark_fft_51     FFT_COMPOSITE_BENCH_API(    51, FFT_FORWARD)
void benchmark_fft_52     FFT_COMPOSITE_BENCH_API(    52, FFT_FORWARD)
void benchmark_fft_54     FFT_COMPOSITE_BENCH_API(    54, FFT_FORWARD)
void benchmark_fft_55     FFT_COMPOSITE_BENCH_API(    55, FFT_FORWARD)
void benchmark_fft_56     FFT_COMPOSITE_BENCH_API(    56, FFT_FORWARD)
void benchmark_fft_57     FFT_COMPOSITE_BENCH_API(    57, FFT_FORWARD)
void benchmark_fft_58     FFT_COMPOSITE_BENCH_API(    58, FFT_FORWARD)
void benchmark_fft_60     FFT_COMPOSITE_BENCH_API(    60, FFT_FORWARD)
void benchmark_fft_62     FFT_COMPOSITE_BENCH_API(    62, FFT_FORWARD)
void benchmark_fft_63     FFT_COMPOSITE_BENCH_API(    63, FFT_FORWARD)
void benchmark_fft_65     FFT_COMPOSITE_BENCH_API(    65, FFT_FORWARD)
void benchmark_fft_66     FFT_COMPOSITE_BENCH_API(    66, FFT_FORWARD)
void benchmark_fft_68     FFT_COMPOSITE_BENCH_API(    68, FFT_FORWARD)
void benchmark_fft_69     FFT_COMPOSITE_BENCH_API(    69, FFT_FORWARD)
void benchmark_fft_70     FFT_COMPOSITE_BENCH_API(    70, FFT_FORWARD)
void benchmark_fft_72     FFT_COMPOSITE_BENCH_API(    72, FFT_FORWARD)
void benchmark_fft_74     FFT_COMPOSITE_BENCH_API(    74, FFT_FORWARD)
void benchmark_fft_75     FFT_COMPOSITE_BENCH_API(    75, FFT_FORWARD)
void benchmark_fft_76     FFT_COMPOSITE_BENCH_API(    76, FFT_FORWARD)
void benchmark_fft_77     FFT_COMPOSITE_BENCH_API(    77, FFT_FORWARD)
void benchmark_fft_78     FFT_COMPOSITE_BENCH_API(    78, FFT_FORWARD)
void benchmark_fft_80     FFT_COMPOSITE_BENCH_API(    80, FFT_FORWARD)
void benchmark_fft_81     FFT_COMPOSITE_BENCH_API(    81, FFT_FORWARD)
void benchmark_fft_82     FFT_COMPOSITE_BENCH_API(    82, FFT_FORWARD)
void benchmark_fft_84     FFT_COMPOSITE_BENCH_API(    84, FFT_FORWARD)
void benchmark_fft_85     FFT_COMPOSITE_BENCH_API(    85, FFT_FORWARD)
void benchmark_fft_86     FFT_COMPOSITE_BENCH_API(    86, FFT_FORWARD)
void benchmark_fft_87     FFT_COMPOSITE_BENCH_API(    87, FFT_FORWARD)
void benchmark_fft_88     FFT_COMPOSITE_BENCH_API(    88, FFT_FORWARD)
void benchmark_fft_90     FFT_COMPOSITE_BENCH_API(    90, FFT_FORWARD)
void benchmark_fft_91     FFT_COMPOSITE_BENCH_API(    91, FFT_FORWARD)
void benchmark_fft_92     FFT_COMPOSITE_BENCH_API(    92, FFT_FORWARD)
void benchmark_fft_93     FFT_COMPOSITE_BENCH_API(    93, FFT_FORWARD)
void benchmark_fft_94     FFT_COMPOSITE_BENCH_API(    94, FFT_FORWARD)
void benchmark_fft_95     FFT_COMPOSITE_BENCH_API(    95, FFT_FORWARD)
void benchmark_fft_96     FFT_COMPOSITE_BENCH_API(    96, FFT_FORWARD)
void benchmark_fft_98     FFT_COMPOSITE_BENCH_API(    98, FFT_FORWARD)
void benchmark_fft_99     FFT_COMPOSITE_BENCH_API(    99, FFT_FORWARD)
void benchmark_fft_100    FFT_COMPOSITE_BENCH_API(   100, FFT_FORWARD)
void benchmark_fft_102    FFT_COMPOSITE_BENCH_API(   102, FFT_FORWARD)
void benchmark_fft_104    FFT_COMPOSITE_BENCH_API(   104, FFT_FORWARD)
void benchmark_fft_105    FFT_COMPOSITE_BENCH_API(   105, FFT_FORWARD)
void benchmark_fft_106    FFT_COMPOSITE_BENCH_API(   106, FFT_FORWARD)
void benchmark_fft_108    FFT_COMPOSITE_BENCH_API(   108, FFT_FORWARD)
void benchmark_fft_110    FFT_COMPOSITE_BENCH_API(   110, FFT_FORWARD)
void benchmark_fft_111    FFT_COMPOSITE_BENCH_API(   111, FFT_FORWARD)
void benchmark_fft_112    FFT_COMPOSITE_BENCH_API(   112, FFT_FORWARD)
void benchmark_fft_114    FFT_COMPOSITE_BENCH_API(   114, FFT_FORWARD)
void benchmark_fft_115    FFT_COMPOSITE_BENCH_API(   115, FFT_FORWARD)
void benchmark_fft_116    FFT_COMPOSITE_BENCH_API(   116, FFT_FORWARD)
void benchmark_fft_117    FFT_COMPOSITE_BENCH_API(   117, FFT_FORWARD)
void benchmark_fft_118    FFT_COMPOSITE_BENCH_API(   118, FFT_FORWARD)
void benchmark_fft_119    FFT_COMPOSITE_BENCH_API(   119, FFT_FORWARD)
void benchmark_fft_120    FFT_COMPOSITE_BENCH_API(   120, FFT_FORWARD)
void benchmark_fft_121    FFT_COMPOSITE_BENCH_API(   121, FFT_FORWARD)
void benchmark_fft_122    FFT_COMPOSITE_BENCH_API(   122, FFT_FORWARD)
void benchmark_fft_123    FFT_COMPOSITE_BENCH_API(   123, FFT_FORWARD)
void benchmark_fft_124    FFT_COMPOSITE_BENCH_API(   124, FFT_FORWARD)
void benchmark_fft_125    FFT_COMPOSITE_BENCH_API(   125, FFT_FORWARD)
void benchmark_fft_126    FFT_COMPOSITE_BENCH_API(   126, FFT_FORWARD)
void benchmark_fft_129    FFT_COMPOSITE_BENCH_API(   129, FFT_FORWARD)
void benchmark_fft_130    FFT_COMPOSITE_BENCH_API(   130, FFT_FORWARD)
void benchmark_fft_132    FFT_COMPOSITE_BENCH_API(   132, FFT_FORWARD)
void benchmark_fft_133    FFT_COMPOSITE_BENCH_API(   133, FFT_FORWARD)
void benchmark_fft_134    FFT_COMPOSITE_BENCH_API(   134, FFT_FORWARD)
void benchmark_fft_135    FFT_COMPOSITE_BENCH_API(   135, FFT_FORWARD)
void benchmark_fft_136    FFT_COMPOSITE_BENCH_API(   136, FFT_FORWARD)
void benchmark_fft_138    FFT_COMPOSITE_BENCH_API(   138, FFT_FORWARD)
void benchmark_fft_140    FFT_COMPOSITE_BENCH_API(   140, FFT_FORWARD)
void benchmark_fft_141    FFT_COMPOSITE_BENCH_API(   141, FFT_FORWARD)
void benchmark_fft_142    FFT_COMPOSITE_BENCH_API(   142, FFT_FORWARD)
void benchmark_fft_143    FFT_COMPOSITE_BENCH_API(   143, FFT_FORWARD)
void benchmark_fft_144    FFT_COMPOSITE_BENCH_API(   144, FFT_FORWARD)
void benchmark_fft_145    FFT_COMPOSITE_BENCH_API(   145, FFT_FORWARD)
void benchmark_fft_146    FFT_COMPOSITE_BENCH_API(   146, FFT_FORWARD)
void benchmark_fft_147    FFT_COMPOSITE_BENCH_API(   147, FFT_FORWARD)
void benchmark_fft_148    FFT_COMPOSITE_BENCH_API(   148, FFT_FORWARD)
void benchmark_fft_150    FFT_COMPOSITE_BENCH_API(   150, FFT_FORWARD)
void benchmark_fft_152    FFT_COMPOSITE_BENCH_API(   152, FFT_FORWARD)
void benchmark_fft_153    FFT_COMPOSITE_BENCH_API(   153, FFT_FORWARD)
void benchmark_fft_154    FFT_COMPOSITE_BENCH_API(   154, FFT_FORWARD)
void benchmark_fft_155    FFT_COMPOSITE_BENCH_API(   155, FFT_FORWARD)
void benchmark_fft_156    FFT_COMPOSITE_BENCH_API(   156, FFT_FORWARD)
void benchmark_fft_158    FFT_COMPOSITE_BENCH_API(   158, FFT_FORWARD)
void benchmark_fft_159    FFT_COMPOSITE_BENCH_API(   159, FFT_FORWARD)
void benchmark_fft_160    FFT_COMPOSITE_BENCH_API(   160, FFT_FORWARD)
void benchmark_fft_161    FFT_COMPOSITE_BENCH_API(   161, FFT_FORWARD)
void benchmark_fft_162    FFT_COMPOSITE_BENCH_API(   162, FFT_FORWARD)
void benchmark_fft_164    FFT_COMPOSITE_BENCH_API(   164, FFT_FORWARD)
void benchmark_fft_165    FFT_COMPOSITE_BENCH_API(   165, FFT_FORWARD)
void benchmark_fft_166    FFT_COMPOSITE_BENCH_API(   166, FFT_FORWARD)
void benchmark_fft_168    FFT_COMPOSITE_BENCH_API(   168, FFT_FORWARD)
void benchmark_fft_169    FFT_COMPOSITE_BENCH_API(   169, FFT_FORWARD)
void benchmark_fft_170    FFT_COMPOSITE_BENCH_API(   170, FFT_FORWARD)
void benchmark_fft_171    FFT_COMPOSITE_BENCH_API(   171, FFT_FORWARD)
void benchmark_fft_172    FFT_COMPOSITE_BENCH_API(   172, FFT_FORWARD)
void benchmark_fft_174    FFT_COMPOSITE_BENCH_API(   174, FFT_FORWARD)
void benchmark_fft_175    FFT_COMPOSITE_BENCH_API(   175, FFT_FORWARD)
void benchmark_fft_176    FFT_COMPOSITE_BENCH_API(   176, FFT_FORWARD)
void benchmark_fft_177    FFT_COMPOSITE_BENCH_API(   177, FFT_FORWARD)
void benchmark_fft_178    FFT_COMPOSITE_BENCH_API(   178, FFT_FORWARD)
void benchmark_fft_180    FFT_COMPOSITE_BENCH_API(   180, FFT_FORWARD)
void benchmark_fft_182    FFT_COMPOSITE_BENCH_API(   182, FFT_FORWARD)
void benchmark_fft_183    FFT_COMPOSITE_BENCH_API(   183, FFT_FORWARD)
void benchmark_fft_184    FFT_COMPOSITE_BENCH_API(   184, FFT_FORWARD)
void benchmark_fft_185    FFT_COMPOSITE_BENCH_API(   185, FFT_FORWARD)
void benchmark_fft_186    FFT_COMPOSITE_BENCH_API(   186, FFT_FORWARD)
void benchmark_fft_187    FFT_COMPOSITE_BENCH_API(   187, FFT_FORWARD)
void benchmark_fft_188    FFT_COMPOSITE_BENCH_API(   188, FFT_FORWARD)
void benchmark_fft_189    FFT_COMPOSITE_BENCH_API(   189, FFT_FORWARD)
void benchmark_fft_190    FFT_COMPOSITE_BENCH_API(   190, FFT_FORWARD)
void benchmark_fft_192    FFT_COMPOSITE_BENCH_API(   192, FFT_FORWARD)
void benchmark_fft_194    FFT_COMPOSITE_BENCH_API(   194, FFT_FORWARD)
void benchmark_fft_195    FFT_COMPOSITE_BENCH_API(   195, FFT_FORWARD)
void benchmark_fft_196    FFT_COMPOSITE_BENCH_API(   196, FFT_FORWARD)
void benchmark_fft_198    FFT_COMPOSITE_BENCH_API(   198, FFT_FORWARD)
void benchmark_fft_200    FFT_COMPOSITE_BENCH_API(   200, FFT_FORWARD)
void benchmark_fft_201    FFT_COMPOSITE_BENCH_API(   201, FFT_FORWARD)
void benchmark_fft_202    FFT_COMPOSITE_BENCH_API(   202, FFT_FORWARD)
void benchmark_fft_203    FFT_COMPOSITE_BENCH_API(   203, FFT_FORWARD)
void benchmark_fft_204    FFT_COMPOSITE_BENCH_API(   204, FFT_FORWARD)
void benchmark_fft_205    FFT_COMPOSITE_BENCH_API(   205, FFT_FORWARD)
void benchmark_fft_206    FFT_COMPOSITE_BENCH_API(   206, FFT_FORWARD)
void benchmark_fft_207    FFT_COMPOSITE_BENCH_API(   207, FFT_FORWARD)
void benchmark_fft_208    FFT_COMPOSITE_BENCH_API(   208, FFT_FORWARD)
void benchmark_fft_209    FFT_COMPOSITE_BENCH_API(   209, FFT_FORWARD)
void benchmark_fft_210    FFT_COMPOSITE_BENCH_API(   210, FFT_FORWARD)
void benchmark_fft_212    FFT_COMPOSITE_BENCH_API(   212, FFT_FORWARD)
void benchmark_fft_213    FFT_COMPOSITE_BENCH_API(   213, FFT_FORWARD)
void benchmark_fft_214    FFT_COMPOSITE_BENCH_API(   214, FFT_FORWARD)
void benchmark_fft_215    FFT_COMPOSITE_BENCH_API(   215, FFT_FORWARD)
void benchmark_fft_216    FFT_COMPOSITE_BENCH_API(   216, FFT_FORWARD)
void benchmark_fft_217    FFT_COMPOSITE_BENCH_API(   217, FFT_FORWARD)
void benchmark_fft_218    FFT_COMPOSITE_BENCH_API(   218, FFT_FORWARD)
void benchmark_fft_219    FFT_COMPOSITE_BENCH_API(   219, FFT_FORWARD)
void benchmark_fft_220    FFT_COMPOSITE_BENCH_API(   220, FFT_FORWARD)
void benchmark_fft_221    FFT_COMPOSITE_BENCH_API(   221, FFT_FORWARD)
void benchmark_fft_222    FFT_COMPOSITE_BENCH_API(   222, FFT_FORWARD)
void benchmark_fft_224    FFT_COMPOSITE_BENCH_API(   224, FFT_FORWARD)
void benchmark_fft_225    FFT_COMPOSITE_BENCH_API(   225, FFT_FORWARD)
void benchmark_fft_226    FFT_COMPOSITE_BENCH_API(   226, FFT_FORWARD)
void benchmark_fft_228    FFT_COMPOSITE_BENCH_API(   228, FFT_FORWARD)
void benchmark_fft_230    FFT_COMPOSITE_BENCH_API(   230, FFT_FORWARD)
void benchmark_fft_231    FFT_COMPOSITE_BENCH_API(   231, FFT_FORWARD)
void benchmark_fft_232    FFT_COMPOSITE_BENCH_API(   232, FFT_FORWARD)
void benchmark_fft_234    FFT_COMPOSITE_BENCH_API(   234, FFT_FORWARD)
void benchmark_fft_235    FFT_COMPOSITE_BENCH_API(   235, FFT_FORWARD)
void benchmark_fft_236    FFT_COMPOSITE_BENCH_API(   236, FFT_FORWARD)
void benchmark_fft_237    FFT_COMPOSITE_BENCH_API(   237, FFT_FORWARD)
void benchmark_fft_238    FFT_COMPOSITE_BENCH_API(   238, FFT_FORWARD)
void benchmark_fft_240    FFT_COMPOSITE_BENCH_API(   240, FFT_FORWARD)
void benchmark_fft_242    FFT_COMPOSITE_BENCH_API(   242, FFT_FORWARD)
void benchmark_fft_243    FFT_COMPOSITE_BENCH_API(   243, FFT_FORWARD)
void benchmark_fft_244    FFT_COMPOSITE_BENCH_API(   244, FFT_FORWARD)
void benchmark_fft_245    FFT_COMPOSITE_BENCH_API(   245, FFT_FORWARD)
void benchmark_fft_246    FFT_COMPOSITE_BENCH_API(   246, FFT_FORWARD)
void benchmark_fft_247    FFT_COMPOSITE_BENCH_API(   247, FFT_FORWARD)
void benchmark_fft_248    FFT_COMPOSITE_BENCH_API(   248, FFT_FORWARD)
void benchmark_fft_249    FFT_COMPOSITE_BENCH_API(   249, FFT_FORWARD)
void benchmark_fft_250    FFT_COMPOSITE_BENCH_API(   250, FFT_FORWARD)
void benchmark_fft_252    FFT_COMPOSITE_BENCH_API(   252, FFT_FORWARD)
void benchmark_fft_253    FFT_COMPOSITE_BENCH_API(   253, FFT_FORWARD)
void benchmark_fft_254    FFT_COMPOSITE_BENCH_API(   254, FFT_FORWARD)
void benchmark_fft_255    FFT_COMPOSITE_BENCH_API(   255, FFT_FORWARD)
