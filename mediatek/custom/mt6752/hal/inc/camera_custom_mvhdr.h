#ifndef _CAMERA_CUSTOM_MVHDR_H_
#define _CAMERA_CUSTOM_MVHDR_H_

#include "camera_custom_types.h"  // For MUINT*/MINT*/MVOID/MBOOL type definitions.

#define CUST_MVHDR_DEBUG          0   // Enable this will dump HDR Debug Information into SDCARD
#define MVHDR_DEBUG_OUTPUT_FOLDER   "/storage/sdcard1/" // For ALPS.JB.
/**************************************************************************
 *                      D E F I N E S / M A C R O S                       *
 **************************************************************************/

/**************************************************************************
 *     E N U M / S T R U C T / T Y P E D E F    D E C L A R A T I O N     *
 **************************************************************************/

/**************************************************************************
 *                 E X T E R N A L    R E F E R E N C E S                 *
 **************************************************************************/

/**************************************************************************
 *        P U B L I C    F U N C T I O N    D E C L A R A T I O N         *
 **************************************************************************/

/*******************************************************************************
* IVHDR exposure setting
*******************************************************************************/
typedef struct mVHDRInputParam_S
{
    MUINT32 u4SensorID;               //
    MUINT32 u4OBValue;                 // 10 bits
    MUINT32 u4ISPGain;                 // 1x=1024
    MVOID *pDataPointer;            //
} mVHDRInputParam_T;

typedef struct mVHDROutputParam_S
{
    MBOOL bUpdateSensorAWB;     // MTRUE : update, MFALSE : don't update
    MVOID *pDataPointer;           //
} mVHDROutputParam_T;

MVOID decodemVHDRStatistic(const mVHDRInputParam_T& rInput, mVHDROutputParam_T& rOutput);

/**************************************************************************
 *                   C L A S S    D E C L A R A T I O N                   *
 **************************************************************************/

#endif // _CAMERA_CUSTOM_IVHDR_H_

