
FAMISTUDIO_CFG_C_BINDINGS = 1
FAMISTUDIO_CFG_SFX_SUPPORT = 1
;FAMISTUDIO_EXP_NONE = 1
;FAMISTUDIO_USE_PHASE_RESET = 1
FAMISTUDIO_USE_FAMITRACKER_TEMPO = 1

; FamiStudio config.
FAMISTUDIO_CFG_EXTERNAL       = 1
FAMISTUDIO_CFG_DPCM_SUPPORT   = 1
FAMISTUDIO_CFG_SFX_SUPPORT    = 1 
FAMISTUDIO_CFG_SFX_STREAMS    = 2
FAMISTUDIO_CFG_EQUALIZER      = 1
FAMISTUDIO_USE_VOLUME_TRACK   = 1
FAMISTUDIO_USE_PITCH_TRACK    = 1
FAMISTUDIO_USE_SLIDE_NOTES    = 1
FAMISTUDIO_USE_VIBRATO        = 1
FAMISTUDIO_USE_ARPEGGIO       = 1
FAMISTUDIO_CFG_SMOOTH_VIBRATO = 1
FAMISTUDIO_USE_RELEASE_NOTES  = 1
FAMISTUDIO_USE_FAMITRACKER_DELAYED_NOTES_OR_CUTS = 1
FAMISTUDIO_DPCM_OFF           = 0xFFF0

FAMISTUDIO_USE_VOLUME_SLIDES  = 1

FAMISTUDIO_VERSION_MAJOR  = 4
FAMISTUDIO_VERSION_MINOR  = 1
FAMISTUDIO_VERSION_HOTFIX = 0

; SDAS-specific config.
.define FAMISTUDIO_SDAS_ZP_SEGMENT   "GBDKOVR (PAG, OVR)"
.define FAMISTUDIO_SDAS_RAM_SEGMENT  "_BSS"
.define FAMISTUDIO_SDAS_CODE_SEGMENT "_CODE_1"

.include "famistudio_sdas.inc"

;_famistudio_init::
;famistudio_init::
;    rts
;_famistudio_play::
;famistudio_play::
;    rts

.area _CODE_1 ;.area _CODE_0

    ; SONG
    .include "Rulz_GonaSpace.inc"

;_music_data=music_data
;.globl _music_data

;.area _DPCM (ABS)
;.org 0xFFF0
;.incbin "song_journey_to_silius_sdas.dmc"