/*
 * MPEGAudioFrame.h
 *
 *  Created on: 2010-11-26
 *      Author: gansc23@gmail.com
 * 
 *  2010-12-16:
 *      1)������ʱ�ж��Ƿ��Ǵ���ֽ���
 */

#ifndef MPEGAUDIOFRAME_H_
#define MPEGAUDIOFRAME_H_



// Delete by gansc23 at 2010-12-16 for ������ʱ�ж��Ƿ��Ǵ��
/**
 * ����ֽ���������������С���ֽ���
 */
//#define BIG_ENDIAN



// MPEGAudioRet::mErrCode
enum{
      MPEG_AUDIO_OK = 0
    , MPEG_AUDIO_NEED_MORE = -99
};


/**
 * �����ؽ���Ľṹ��
 */
typedef struct _MPEGAudioRet{
    int mErrCode;
    int mNextPos;
} MPEGAudioRet;


/**
 * ����MPEG��Ƶ֡����Ϣ
 */
typedef struct _MPEGAudioFrameInfo{
    
    // MPEG Audio Frame Header /////////////////////////////////////////////////
    
    /**
     * MPEG-1.0: 10
     * MPEG-2.0: 20
     * MPEG-2.5: 25
     * invalid : other
     */
    int mMPEGVersion : 6;
    
    /**
     * Layer I  : 1
     * Layer II : 2
     * Layer III: 3
     * invalid  : other
     */
    int mLayer : 3;
    
    /**
     * in kbits/s
     */
    int mBitrate : 10;
    
    /**
     * in Bytes
     */
    int mPaddingSize : 4;
    
    
    /**
     * Channel mode
     *
     * Joint Stereo (Stereo) - 0
     * Single channel (Mono) - 1
     * Dual channel (Two mono channels) - 2
     * Stereo - 3
     */
    int mChannelMode : 3;
    
    /**
     * Mode extension, Only used in Joint Stereo Channel mode.
     * not process
     */
    int mExtensionMode : 3;
    
    /**
     * Emphasis:
     * The emphasis indication is here to tell the decoder that the file must be 
     * de-emphasized, that means the decoder must 're-equalize' the sound after 
     * a Dolby-like noise suppression. It is rarely used.
     * 
     * 0 - none
     * 1 - 50/15 ms
     * 2 - reserved (invalid)
     * 3 - CCIT J.17
     */
    int mEmphasis : 3;

    
    /**
     * in Hz
     */
    int mSamplerate : 17;
    

    /**
     * Protection off: 0
     * Protection on : 1
     */
    int mProtection : 2;
    

    /**
     * Copyright bit, only informative
     */
    int mCopyrightBit : 2;
    
    /**
     * Original bit, only informative
     */
    int mOriginalBit : 2;
    
    /**
     * ����Ϣ��С(Layer III), in Bytes
     */
    int mSideInfoSize : 7;
    
    
    /**
     * Samples per frame
     */
    int mSamplesPerFrame : 12;
    
    /**
     * 0 - CBR
     * 1 - CBR(INFO)
     * 2 - VBR(XING)
     * 3 - VBR(VBRI)
     */
    int mBitrateType : 3;
    
    /**
     * 2 Bytes
     */
    unsigned short int mCRCValue;
    
    
    // XING, INFO or VBRI Header /////////////////////////////////////////////////////

    /**
     * mTotalFrames
     */
    int mTotalFrames;
    
    /**
     * mTotalBytes
     */
    int mTotalBytes;
    
    /**
     * Quality indicator
     * 
     * From 0 - worst quality to 100 - best quality
     */
    short int mQuality;



    // only for VBRI Header ////////////////////////////////////////////////////
    
    /**
     * Size per table entry in bytes (max 4)
     */
    short int  mEntrySize : 4;
    
    
    /**
     * Number of entries within TOC table
     */
    short int  mEntriesNumInTOCTable;
    
    /**
     * Scale factor of TOC table entries
     */
    short int  mTOCTableFactor;
    
    /**
     * VBRI version
     */
    short int mVBRIVersionID;
    
    /**
     * Frames per table entry
     */
    short int mFramesNumPerTable;
    
    /**
     * VBRI delay
     * 
     * Delay as Big-Endian float.
     */
    unsigned char mVBRIDelay[2]; 
    
    
    ////////////////////////////////////////////////////////////////////////////
    
    /**
     * Frame size
     */
    int mFrameSize;
    
    
} MPEGAudioFrameInfo;


/**
 * Ѱ�Ҳ���һ֡MPEG��Ƶ֡����Ϣ��
 * 
 * @param buf         ������
 * @param bufSize     ��������С
 * @param info[out]   MPEG��Ƶ֡����Ϣ������ΪNULL
 * @param firstFrame  �Ƿ���Ѱ�Һͽ�����һ֡����
 * 
 * @ret  ��MPEGAudioRet.mErrCodeΪMPEG_AUDIO_OK�����������ɹ������������Ҫ�������ݡ�
 *       �������ɹ���ʱ��MPEGAudioRet.mNextPos��������һ֡��ƫ���������������һ�δ�
 *       ���������ݣ�Ӧ�ÿ�ʼ������ƫ������
 */
MPEGAudioRet findMpegAudioFramePos(
        unsigned char * buf, 
        int bufSize,
        MPEGAudioFrameInfo * info, 
        bool firstFrame);



#endif /* MPEGAUDIOFRAME_H_ */