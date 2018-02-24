#ifndef __SI4463_TYPES_H
#define __SI4463_TYPES_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef void (*SI4463_CommandHandler)(uint8_t Command, uint8_t *Buffer, size_t NumBytes);

typedef struct
{
} SI4463_InitTypeDef;

typedef struct
{
  const SI4463_CommandHandler Command;
} SI4463_HalTypeDef;

typedef struct
{
  SI4463_InitTypeDef Init;
  SI4463_HalTypeDef HAL;
} SI4463_HandleTypeDef;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __SI4463_TYPES_H */