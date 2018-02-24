#include "si4463.h"

void SI4463_RadioConfig(SI4463_HandleTypeDef *hradio, uint8_t *buffer)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  while (buffer[0] != 0)
  {
    cmd(buffer[1], buffer + 2, buffer[0] - 1);
    buffer += buffer[0] + 1;
  }
}

//*************************************************************************************//

void SI4463_PartInfo(SI4463_HandleTypeDef *hradio, uint8_t *buffer)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_PART_INFO, NULL, 0);
  if (buffer != NULL)
    cmd(CMD_READ_CMD_BUFF, buffer, 9);
}

void SI4463_FuncInfo(SI4463_HandleTypeDef *hradio, uint8_t *buffer)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_FUNC_INFO, NULL, 0);
  if (buffer != NULL)
    cmd(CMD_READ_CMD_BUFF, buffer, 7);
}

void SI4463_SetProperty(SI4463_HandleTypeDef *hradio, uint8_t group, uint8_t index, uint8_t buffer)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg[] = {group, 1, index, buffer};
  cmd(CMD_SET_PROPERTY, tmpreg, 4);
}

void SI4463_GetProperty(SI4463_HandleTypeDef *hradio, uint8_t group, uint8_t index, uint8_t *buffer)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg[] = {group, 1, index};
  cmd(CMD_GET_PROPERTY, tmpreg, 3);
  cmd(CMD_READ_CMD_BUFF, tmpreg, 2);
  buffer[0] = tmpreg[1];
}

void SI4463_FifoInfo(SI4463_HandleTypeDef *hradio, uint8_t *buffer, uint8_t reset)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg[1] = {0x03 & reset};
  cmd(CMD_FIFO_INFO, tmpreg, 1);
  if (buffer != NULL)
    cmd(CMD_READ_CMD_BUFF, buffer, 3);
}

void SI4463_IntStatus(SI4463_HandleTypeDef *hradio, uint8_t *buffer)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg[3] = {0x00, 0x00, 0x00};
  cmd(CMD_GET_INT_STATUS, tmpreg, 3);
  if (buffer != NULL)
    cmd(CMD_READ_CMD_BUFF, buffer, 9);
}

void SI4463_ModemStatus(SI4463_HandleTypeDef *hradio, uint8_t *buffer)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg[1] = {0x00};
  cmd(CMD_GET_MODEM_STATUS, tmpreg, 1);
  if (buffer != NULL)
    cmd(CMD_READ_CMD_BUFF, buffer, 9);
}

void SI4463_GetDeviceState(SI4463_HandleTypeDef *hradio, uint8_t *buffer)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_REQUEST_DEVICE_STATE, NULL, 0);
  if (buffer != NULL)
    cmd(CMD_READ_CMD_BUFF, buffer, 3);
}

void SI4463_SetDeviceState(SI4463_HandleTypeDef *hradio, uint8_t state)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg[1] = {0x0F & state};
  cmd(CMD_CHANGE_STATE, tmpreg, 1);
}

//*************************************************************************************//

void SI4463_WriteTxFifo(SI4463_HandleTypeDef *hradio, uint8_t *buffer, size_t size)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_WRITE_TX_FIFO, buffer, size);
}

void SI4463_ReadRxFifo(SI4463_HandleTypeDef *hradio, uint8_t *buffer, size_t size)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_READ_RX_FIFO, buffer, size);
}

void SI4463_StartTX(SI4463_HandleTypeDef *hradio, uint8_t channel, size_t size)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg[] = {channel, 0x30, 0x00, size};
  cmd(CMD_START_TX, tmpreg, 4);
}

void SI4463_StartRX(SI4463_HandleTypeDef *hradio, uint8_t channel, size_t size)
{
  SI4463_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg3[7] = {channel, 0x00, 0x00, size, 0x00, 0x03, 0x08};
  cmd(CMD_START_RX, tmpreg3, 7);
}