#ifndef __SI4463_H
#define __SI4463_H

#include "si4463_api.h"
#include "si4463_defs.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern void SendCommand(uint8_t Command, uint8_t *Buffer, size_t NumBytes);
extern void RecvCommand(uint8_t Command, uint8_t *Buffer, size_t NumBytes);

void SI4463_RadioConfig(uint8_t *buffer);

//*************************************************************************************//

void SI4463_PartInfo(uint8_t *buffer);
void SI4463_FuncInfo(uint8_t *buffer);
void SI4463_SetProperty(uint8_t group, uint8_t index, uint8_t buffer);
void SI4463_GetProperty(uint8_t group, uint8_t index, uint8_t *buffer);
void SI4463_FifoInfo(uint8_t *buffer, uint8_t reset);
void SI4463_IntStatus(uint8_t *buffer);
void SI4463_ModemStatus(uint8_t *buffer);
void SI4463_GetDeviceState(uint8_t *buffer);
void SI4463_SetDeviceState(uint8_t state);

//*************************************************************************************//

void SI4463_StartTX(uint8_t channel, size_t size);
void SI4463_StartRX(uint8_t channel, size_t size);
void SI4463_WriteTxFifo(uint8_t *buffer, size_t size);
void SI4463_ReadRxFifo(uint8_t *buffer, size_t size);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __SI4463_H */