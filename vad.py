import webrtc_vad

if __name__ == '__main__':
    vad_inst = webrtc_vad.WebRtcVad_Create()
    webrtc_vad.WebRtcVad_Init(vad_inst)
    webrtc_vad.WebRtcVad_set_mode(vad_inst, 2)
    
