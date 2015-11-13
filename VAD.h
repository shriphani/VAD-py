/*
 * This header file includes the Webrtc headers and a helper function
 * so we can use numpy.i easily
 */

#include "webrtc/common_audio/vad/include/webrtc_vad.h"

VadInst* WebRtcVad_Create();

void WebRtcVad_Free(VadInst* handle);

int WebRtcVad_Init(VadInst* handle);

int WebRtcVad_set_mode(VadInst* handle, int mode);

/**
 * Wrapper around WebRtcVad_Process.
 * This signature plays nicely with numpy.i
 **/
int processFrame(VadInst* handle, int fs, int16_t* audio_frame, int frame_length) {
  size_t frame_len = (size_t)frame_length;
  return WebRtcVad_Process(handle, fs, (const int16_t*)audio_frame, frame_len);
}
