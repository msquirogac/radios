#ifndef __NRF24_H
#define __NRF24_H

#include "nrf24_api.h"
#include "nrf24_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void NRF24_Init(NRF24_HandleTypeDef *hradio);

//*************************************************************************************//

void NRF24_Init(NRF24_HandleTypeDef *hradio);
void NRF24_SetTxAddress(NRF24_HandleTypeDef *hradio, uint8_t *address, size_t size);
void NRF24_SetRxAddress(NRF24_HandleTypeDef *hradio, uint8_t *address, size_t size);
void NRF24_SetChannel(NRF24_HandleTypeDef *hradio, uint8_t channel);
void NRF24_SetPayloadSize(NRF24_HandleTypeDef *hradio, uint8_t size);
void NRF24_SetRxEnable(NRF24_HandleTypeDef *hradio, uint8_t config);
void NRF24_SetAutoAck(NRF24_HandleTypeDef *hradio, uint8_t config);

uint8_t NRF24_GetPayloadSize(NRF24_HandleTypeDef *hradio);
uint8_t NRF24_GetStatus(NRF24_HandleTypeDef *hradio);
uint8_t NRF24_GetFifoStatus(NRF24_HandleTypeDef *hradio);
void NRF24_SetStatus(NRF24_HandleTypeDef *hradio, uint8_t status);
void NRF24_SetFifoStatus(NRF24_HandleTypeDef *hradio, uint8_t status);

void NRF24_RadioPower(NRF24_HandleTypeDef *hradio, uint8_t state);
void NRF24_RadioEnable(NRF24_HandleTypeDef *hradio, uint8_t state);
void NRF24_TxFlush(NRF24_HandleTypeDef *hradio);
void NRF24_RxFlush(NRF24_HandleTypeDef *hradio);
void NRF24_RxMode(NRF24_HandleTypeDef *hradio);
void NRF24_TxMode(NRF24_HandleTypeDef *hradio);
void NRF24_RxPacket(NRF24_HandleTypeDef *hradio, void *buffer, size_t size);
void NRF24_TxPacket(NRF24_HandleTypeDef *hradio, void *buffer, size_t size);

//*************************************************************************************//

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __NRF24_H */