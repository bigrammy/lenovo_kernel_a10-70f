#include "camera_custom_mvhdr.h"
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <cutils/properties.h>
#include <cutils/xlog.h> // For XLOG?().
#include <utils/Errors.h>

#define CLAMP(x,min,max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))


/**************************************************************************
 *                      D E F I N E S / M A C R O S                       *
 **************************************************************************/
 // customize parameters
#define CUST_MVHDR_UPDATE_AWB_GAIN  1

/**************************************************************************
 *     E N U M / S T R U C T / T Y P E D E F    D E C L A R A T I O N     *
 **************************************************************************/

#define CUST_MVHDR_ISPGAIN_BASE 1024   // 1x = 1023
/**************************************************************************
 *                 E X T E R N A L    R E F E R E N C E S                 *
 **************************************************************************/

/**************************************************************************
 *                         G L O B A L    D A T A                         *
 **************************************************************************/

/**************************************************************************
 *       P R I V A T E    F U N C T I O N    D E C L A R A T I O N        *
 **************************************************************************/
MVOID decodemVHDRStatistic(const mVHDRInputParam_T& rInput, mVHDROutputParam_T& rOutput)
{
    MINT32 i, j;
    MUINT8 *pAEStat = reinterpret_cast<MUINT8 *>(rInput.pDataPointer);
    MUINT16 u2UperLSBData, u2UperMSBData, u2LowLSBData, u2LowMSBData;
    MUINT32 u4AEStaY;
    MINT32 i4StaY;
    MUINT16 strAEStsBufferAdd[16*16 + 256];      //AE statistic buffer

//    if(rInput.u4SensorID == )   // TBD
    {
        memset(strAEStsBufferAdd, 0, (16*16+256)*sizeof(MUINT16));

        for(i=0; i <16; i++) {
            for(j=0; j<16; j++) {
                u2UperMSBData = pAEStat[i*16*2 + j*2 + 8*i + j/2 ];
                u2LowMSBData = pAEStat[i*16*2 + j*2 + 1 + 8*i + j/2];
                u4AEStaY = (((u2UperMSBData << 6) & 0x3FC0) | ((u2LowMSBData >> 2) & 0x003F)) * rInput.u4ISPGain / CUST_MVHDR_ISPGAIN_BASE;
                if(u4AEStaY >= 1024) {
                    strAEStsBufferAdd[i*16 + j] = 1023;
                } else {
                    strAEStsBufferAdd[i*16 + j] = u4AEStaY;
                }
                if(strAEStsBufferAdd[i*16 + j] > 64) {   // reduce OB
                    strAEStsBufferAdd[i*16 + j] = ((strAEStsBufferAdd[i*16 + j] - rInput.u4OBValue) * 1023) / ((1023 - rInput.u4OBValue) * 4);
                } else {
                    strAEStsBufferAdd[i*16 + j] = 0;
                }
            }
            XLOGE("[%s] RAW:%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", __FUNCTION__,
            i,
            strAEStsBufferAdd[i*16 + 0],
            strAEStsBufferAdd[i*16 + 1],
            strAEStsBufferAdd[i*16 + 2],
            strAEStsBufferAdd[i*16 + 3],
            strAEStsBufferAdd[i*16 + 4],
            strAEStsBufferAdd[i*16 + 5],
            strAEStsBufferAdd[i*16 + 6],
            strAEStsBufferAdd[i*16 + 7],
            strAEStsBufferAdd[i*16 + 8],
            strAEStsBufferAdd[i*16 + 9],
            strAEStsBufferAdd[i*16 + 10],
            strAEStsBufferAdd[i*16 + 11],
            strAEStsBufferAdd[i*16 + 12],
            strAEStsBufferAdd[i*16 + 13],
            strAEStsBufferAdd[i*16 + 14],
            strAEStsBufferAdd[i*16 + 15]);
        }

        /*
        *   Stat to Histogram
        */
        for(int i = 0; i < 16; i++) {
            for(int j = 0; j < 16; j++) {
                i4StaY = strAEStsBufferAdd[i*16 + j]; 
                i4StaY = CLAMP(i4StaY, 0, 255);
                strAEStsBufferAdd[16*16 + i4StaY]++ ;
            }
        }
        rOutput.pDataPointer = strAEStsBufferAdd;
        rOutput.bUpdateSensorAWB = MTRUE;
    }
}
