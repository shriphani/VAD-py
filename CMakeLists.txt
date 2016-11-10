cmake_minimum_required (VERSION 3.5)
project (WebRTC_VAD)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(UNIX)
  add_definitions(-DWEBRTC_POSIX)
elseif(WIN32)
  add_definitions(-D_WIN32)
endif()

add_library(
  webrtc_vad
  SHARED
  webrtc/common_audio/vad/vad_gmm.c
  webrtc/common_audio/vad/webrtc_vad.c
  webrtc/common_audio/vad/vad_sp.c
  webrtc/common_audio/vad/vad_filterbank.c
  webrtc/common_audio/vad/vad_core.c
  webrtc/common_audio/signal_processing/ilbc_specific_functions.c
  webrtc/common_audio/signal_processing/filter_ma_fast_q12.c
  webrtc/common_audio/signal_processing/downsample_fast.c
  webrtc/common_audio/signal_processing/dot_product_with_scale.c
  webrtc/common_audio/signal_processing/filter_ar_fast_q12.c
  webrtc/common_audio/signal_processing/resample_by_2.c
  webrtc/common_audio/signal_processing/resample.c
  webrtc/common_audio/signal_processing/spl_sqrt_floor.c
  webrtc/common_audio/signal_processing/auto_corr_to_refl_coef.c
  webrtc/common_audio/signal_processing/complex_bit_reverse.c
  webrtc/common_audio/signal_processing/complex_fft.c
  webrtc/common_audio/signal_processing/min_max_operations.c
  webrtc/common_audio/signal_processing/filter_ar.c
  webrtc/common_audio/signal_processing/lpc_to_refl_coef.c
  webrtc/common_audio/signal_processing/resample_fractional.c
  webrtc/common_audio/signal_processing/copy_set_operations.c
  webrtc/common_audio/signal_processing/resample_by_2_mips.c
  webrtc/common_audio/signal_processing/energy.c
  webrtc/common_audio/signal_processing/division_operations.c
  webrtc/common_audio/signal_processing/sqrt_of_one_minus_x_squared.c
  webrtc/common_audio/signal_processing/auto_correlation.c
  webrtc/common_audio/signal_processing/vector_scaling_operations.c
  webrtc/common_audio/signal_processing/randomization_functions.c
  webrtc/common_audio/signal_processing/splitting_filter.c
  webrtc/common_audio/signal_processing/levinson_durbin.c
  webrtc/common_audio/signal_processing/refl_coef_to_lpc.c
  webrtc/common_audio/signal_processing/get_hanning_window.c
  webrtc/common_audio/signal_processing/spl_init.c
  webrtc/common_audio/signal_processing/spl_sqrt.c
  webrtc/common_audio/signal_processing/resample_by_2_internal.c
  webrtc/common_audio/signal_processing/resample_48khz.c
  webrtc/common_audio/signal_processing/real_fft.c
  webrtc/common_audio/signal_processing/cross_correlation.c
  webrtc/common_audio/signal_processing/get_scaling_square.c
  )

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

find_package(PythonLibs)
include_directories(${PYTHON_INCLUDE_PATH})

SET(CMAKE_SWIG_FLAGS "")

SWIG_ADD_MODULE(webrtc_vad python webrtc_vad.i webrtc_vad.i)
SWIG_LINK_LIBRARIES(webrtc_vad ${PYTHON_LIBRARIES} webrtc_vad)
