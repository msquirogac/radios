#ifndef __NRF24_H
#define __NRF24_H

#include "nrf24_api.h"
#include "nrf24_defs.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void NRF24_SetRegister(NRF24_HandleTypeDef *hradio, uint8_t address, uint8_t value);
uint8_t NRF24_GetRegister(NRF24_HandleTypeDef *hradio, uint8_t address);
void NRF24_RadioConfig(NRF24_HandleTypeDef *hradio, uint8_t *buffer);

//*************************************************************************************//

void NRF24_Init(NRF24_HandleTypeDef *hradio);
void NRF24_Reset(NRF24_HandleTypeDef *hradio);
void NRF24_SetTxAddress(NRF24_HandleTypeDef *hradio, uint8_t *address, size_t size);
void NRF24_SetRxAddress(NRF24_HandleTypeDef *hradio, uint8_t *address, size_t size);
void NRF24_SetRxPayloadSize(NRF24_HandleTypeDef *hradio, uint8_t size);
void NRF24_SetChannel(NRF24_HandleTypeDef *hradio, uint8_t channel);
void NRF24_SetStatus(NRF24_HandleTypeDef *hradio, uint8_t status);
void NRF24_SetFifoStatus(NRF24_HandleTypeDef *hradio, uint8_t status);
uint8_t NRF24_GetRxPayloadSize(NRF24_HandleTypeDef *hradio);
uint8_t NRF24_GetFifoStatus(NRF24_HandleTypeDef *hradio);
uint8_t NRF24_GetStatus(NRF24_HandleTypeDef *hradio);
void NRF24_PowerUp(NRF24_HandleTypeDef *hradio);
void NRF24_PowerDown(NRF24_HandleTypeDef *hradio);
void NRF24_RadioStart(NRF24_HandleTypeDef *hradio);
void NRF24_RadioStop(NRF24_HandleTypeDef *hradio);
void NRF24_RxFlush(NRF24_HandleTypeDef *hradio);
void NRF24_TxFlush(NRF24_HandleTypeDef *hradio);
void NRF24_RxMode(NRF24_HandleTypeDef *hradio);
void NRF24_TxMode(NRF24_HandleTypeDef *hradio);
void NRF24_RxPacket(NRF24_HandleTypeDef *hradio, void *buffer, size_t size);
void NRF24_TxPacket(NRF24_HandleTypeDef *hradio, void *buffer, size_t size);

//*************************************************************************************//

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __NRF24_H */