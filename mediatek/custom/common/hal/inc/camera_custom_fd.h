#ifndef _FD_CONFIG_H
#define _FD_CONFIG_H

//FDSizeRatio tuning parameter for FPR
typedef struct
{
    unsigned int FDThreadNum;
    unsigned int FDThreshold;
    unsigned int MajorFaceDecision;
    unsigned int OTRatio;
    unsigned int SmoothLevel;
    unsigned int FDSkipStep;
    unsigned int FDRectify;
    unsigned int FDRefresh;
    unsigned int SDThreshold;
    unsigned int SDMainFaceMust;
    unsigned int SDMaxSmileNum;
    unsigned int GSensor;
    unsigned char FDModel;
    float FDSizeRatio;
}FD_Customize_PARA;


void get_fd_CustomizeData(FD_Customize_PARA  *FDDataOut);
	
#endif /* _FD_CONFIG_H */

