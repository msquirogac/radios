#ifndef __NRF24_TYPES_H
#define __NRF24_TYPES_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef void (*NRF24_CommandHandler)(uint8_t Command, uint8_t *Buffer, size_t NumBytes);
typedef void (*NRF24_PowerHandler)(uint8_t State);
typedef uint32_t (*NRF24_InterruptHandler)(void);

typedef struct
{
  const NRF24_CommandHandler Command;
  const NRF24_CommandHandler CommandReturn;
  const NRF24_PowerHandler Power;
  const NRF24_InterruptHandler Interrupt;
} NRF24_HalTypeDef;

typedef struct
{
} NRF24_InitTypeDef;

typedef struct
{
  NRF24_HalTypeDef HAL;
  NRF24_InitTypeDef Init;
} NRF24_HandleTypeDef;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __NRF24_TYPES_H */