#ifndef __SI4463_H
#define __SI4463_H

#include "si4463_api.h"
#include "si4463_defs.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern void SendCommand(uint8_t Command, uint8_t *Buffer, size_t NumBytes);
extern void RecvCommand(uint8_t Command, uint8_t *Buffer, size_t NumBytes);

void SI4463_RadioConfig(SI4463_HandleTypeDef *hradio, uint8_t *buffer);

//*************************************************************************************//

void SI4463_PartInfo(SI4463_HandleTypeDef *hradio, uint8_t *buffer);
void SI4463_FuncInfo(SI4463_HandleTypeDef *hradio, uint8_t *buffer);
void SI4463_SetProperty(SI4463_HandleTypeDef *hradio, uint8_t group, uint8_t index, uint8_t buffer);
void SI4463_GetProperty(SI4463_HandleTypeDef *hradio, uint8_t group, uint8_t index, uint8_t *buffer);
void SI4463_FifoInfo(SI4463_HandleTypeDef *hradio, uint8_t *buffer, uint8_t reset);
void SI4463_IntStatus(SI4463_HandleTypeDef *hradio, uint8_t *buffer);
void SI4463_ModemStatus(SI4463_HandleTypeDef *hradio, uint8_t *buffer);
void SI4463_GetDeviceState(SI4463_HandleTypeDef *hradio, uint8_t *buffer);
void SI4463_SetDeviceState(SI4463_HandleTypeDef *hradio, uint8_t state);

//*************************************************************************************//

void SI4463_StartTX(SI4463_HandleTypeDef *hradio, uint8_t channel, size_t size);
void SI4463_StartRX(SI4463_HandleTypeDef *hradio, uint8_t channel, size_t size);
void SI4463_WriteTxFifo(SI4463_HandleTypeDef *hradio, uint8_t *buffer, size_t size);
void SI4463_ReadRxFifo(SI4463_HandleTypeDef *hradio, uint8_t *buffer, size_t size);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __SI4463_H */