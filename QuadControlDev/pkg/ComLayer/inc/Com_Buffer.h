#ifndef COM_BUFFER_H
#define COM_BUFFER_H

#include "stm32f4xx.h"

/*All buffers needed to transfer data from one module to another */
typedef struct
{
	uint8_t ComLayer_IMUData;



}ComLayer_tstComData;

extern ComLayer_tstComData ComLayer_stComData;


#endif /* COM_BUFFER_H */
