/*
 * Copyright (c) 2007, 2008, 2009, 2010 Joseph Gaeddert
 * Copyright (c) 2007, 2008, 2009, 2010 Virginia Polytechnic
 *                                      Institute & State University
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

#ifndef __LIQUID_DOC_H__
#define __LIQUID_DOC_H__

#include <stdio.h>
#include <complex.h>
#include <stdbool.h>
#include <liquid/liquid.h>

// default gnuplot colors
#define LIQUID_DOC_COLOR_GRID   "#cccccc"   // very light gray
#define LIQUID_DOC_COLOR_GRAY   "#999999"   // light gray
#define LIQUID_DOC_COLOR_BLUE   "#004080"   // blue
#define LIQUID_DOC_COLOR_GREEN  "#008040"   // green
#define LIQUID_DOC_COLOR_RED    "#800000"   // dark red
#define LIQUID_DOC_COLOR_PURPLE "#400040"   // dark puple

// power spectral density window
typedef enum {
    LIQUID_DOC_PSDWINDOW_NONE=0,
    LIQUID_DOC_PSDWINDOW_HANN,
    LIQUID_DOC_PSDWINDOW_HAMMING
} liquid_doc_psdwindow;

// compute power spectral density (complex float input)
void liquid_doc_compute_psdcf(float complex * _x,
                              unsigned int _n,
                              float complex * _X,
                              unsigned int _nfft,
                              liquid_doc_psdwindow _wtype,
                              bool _normalize);

// compute power spectral density (float input)
void liquid_doc_compute_psdf(float * _x,
                             unsigned int _n,
                             float complex * _X,
                             unsigned int _nfft,
                             liquid_doc_psdwindow _wtype,
                             bool _normalize);


// Compute spectral response
void liquid_doc_freqz(float * _b,
                      unsigned int _nb,
                      float * _a,
                      unsigned int _na,
                      unsigned int _nfft,
                      float complex * _H);

// 
// html documentation generation
//

// doc-html-gen function
typedef void (*htmlgen_func) (FILE * _fid_tex, FILE * _fid_html);

// token structure
typedef struct {
    char * token;
    htmlgen_func f;
} htmlgen_token_s;

// html gen structure
typedef struct htmlgen_s * htmlgen;
struct htmlgen_s {
    // file names
    char filename_tex[128];
    char filename_html[128];
    char filename_eqmk[128];

    // file pointers
    FILE * fid_tex;
    FILE * fid_html;
    FILE * fid_eqmk;

    // equation identifier
    unsigned int equation_id;
};

// main parsing function
void htmlgen_parse_latex_file(char * _filename_tex,
                              char * _filename_html,
                              char * _filename_eqmk);

// html output
void htmlgen_html_write_header(FILE * _fid);
void htmlgen_html_write_footer(FILE * _fid);

// equation files
void htmlgen_add_equation(char * _eqn,
                          unsigned int _eqn_id,
                          FILE * _fid_eqmk);
void htmlgen_eqn_write_header(FILE * _fid);
void htmlgen_eqn_write_footer(FILE * _fid);

// token methods
void htmlgen_token_parse_begin(FILE * _fid_tex, FILE * _fid_html);
void htmlgen_token_parse_end(FILE * _fid_tex, FILE * _fid_html);
void htmlgen_token_parse_document(FILE * _fid_tex, FILE * _fid_html);
void htmlgen_token_parse_section(FILE * _fid_tex, FILE * _fid_html);
void htmlgen_token_parse_subsection(FILE * _fid_tex, FILE * _fid_html);
void htmlgen_token_parse_subsubsection(FILE * _fid_tex, FILE * _fid_html);
void htmlgen_token_parse_figure(FILE * _fid_tex, FILE * _fid_html);
void htmlgen_token_parse_tabular(FILE * _fid_tex, FILE * _fid_html);
void htmlgen_token_parse_enumerate(FILE * _fid_tex, FILE * _fid_html);
void htmlgen_token_parse_itemize(FILE * _fid_tex, FILE * _fid_html);

#endif // __LIQUID_DOC_H__

