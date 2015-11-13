/*
 * This header file includes the Webrtc headers and is a helper function
 */

#include "webrtc/common_audio/vad/include/webrtc_vad.h"

int processFrame(VadInst* handle, int fs, int16_t* audio_frame, int frame_length) {
  
  WebRtcVad_Process(handle, fs, (const int16_t*)audio_frame, (unsigned int)frame_length);
}
