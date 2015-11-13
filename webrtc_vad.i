%module webrtc_vad

%{
#define SWIG_FILE_WITH_INIT
#include "VAD.h"
%}

%{
  /* Include in the generated wrapper file */
%}

%include "numpy.i"

%init %{
  import_array();
%}

typedef unsigned int size_t;
%numpy_typemaps(int16_t, NPY_INT16, int)
%apply (int16_t* IN_ARRAY1, int DIM1) {(int16_t* audio_frame, int frame_length)};
%include "VAD.h"
