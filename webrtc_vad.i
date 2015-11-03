%module webrtc_vad
%inline %{
  #include "webrtc/typedefs.h"
  typedef struct WebRtcVadInst VadInst;
  VadInst* WebRtcVad_Create();
  void WebRtcVad_Free(VadInst* handle);
  int WebRtcVad_Init(VadInst* handle);
  int WebRtcVad_set_mode(VadInst* handle, int mode);
  int WebRtcVad_Process(VadInst* handle, int fs, const int16_t* audio_frame, size_t frame_length);
  int WebRtcVad_ValidRateAndFrameLength(int rate, size_t frame_length);
%}
