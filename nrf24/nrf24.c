#include "nrf24.h"

void NRF24_Init(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  NRF24_PowerHandler pwr = hradio->HAL.Power;
  NRF24_InitTypeDef *init = &hradio->Init;
  uint8_t tmpreg;
  tmpreg = init->Config;
  pwr(0);
  cmd(CMD_W_REGISTER + REG_CONFIG, &tmpreg, 1);
  tmpreg = init->RF_Setup;
  cmd(CMD_W_REGISTER + REG_RF_SETUP, &tmpreg, 1);
  tmpreg = init->Feature;
  cmd(CMD_W_REGISTER + REG_FEATURE, &tmpreg, 1);
  tmpreg = init->Auto_Ack;
  cmd(CMD_W_REGISTER + REG_EN_AA, &tmpreg, 1);
  tmpreg = init->En_RxAddr;
  cmd(CMD_W_REGISTER + REG_EN_RXADDR, &tmpreg, 1);
}

void NRF24_SetTxAddress(NRF24_HandleTypeDef *hradio, uint8_t *address, size_t size)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_REGISTER + REG_TX_ADDR, address, size);
}

void NRF24_SetRxAddress(NRF24_HandleTypeDef *hradio, uint8_t *address, size_t size)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_REGISTER + REG_RX_ADDR_P0, address, size);
}

void NRF24_SetChannel(NRF24_HandleTypeDef *hradio, uint8_t channel)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_REGISTER + REG_RF_CH, &channel, 1);
}

void NRF24_SetPayloadSize(NRF24_HandleTypeDef *hradio, uint8_t size)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_REGISTER + REG_RX_PW_P0, &size, 1);
}

void NRF24_SetRxEnable(NRF24_HandleTypeDef *hradio, uint8_t config)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_REGISTER + REG_EN_RXADDR, &config, 1);
}

void NRF24_SetAutoAck(NRF24_HandleTypeDef *hradio, uint8_t config)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_REGISTER + REG_EN_AA, &config, 1);
}

uint8_t NRF24_GetPayloadSize(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg;
  cmd(CMD_R_RX_PL_WID, &tmpreg, 1);
  return tmpreg;
}

uint8_t NRF24_GetStatus(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg;
  cmd(CMD_R_REGISTER + REG_STATUS, &tmpreg, 1);
  return tmpreg;
}

uint8_t NRF24_GetFifoStatus(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg;
  cmd(CMD_R_REGISTER + REG_FIFO_STATUS, &tmpreg, 1);
  return tmpreg;
}

void NRF24_SetStatus(NRF24_HandleTypeDef *hradio, uint8_t status)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_REGISTER + REG_STATUS, &status, 1);
}

void NRF24_SetFifoStatus(NRF24_HandleTypeDef *hradio, uint8_t status)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_REGISTER + REG_FIFO_STATUS, &status, 1);
}

void NRF24_RadioPower(NRF24_HandleTypeDef *hradio, uint8_t state)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg;
  cmd(CMD_R_REGISTER + REG_CONFIG, &tmpreg, 1);
  if(state)
  {
    tmpreg |= CONFIG_PWR_UP;
  }
  else
  {
    tmpreg &= ~CONFIG_PWR_UP;
  }
  cmd(CMD_W_REGISTER + REG_CONFIG, &tmpreg, 1);
}

void NRF24_RadioEnable(NRF24_HandleTypeDef *hradio, uint8_t state)
{
  NRF24_PowerHandler pwr = hradio->HAL.Power;
  pwr(state);
}

void NRF24_RxMode(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg;
  cmd(CMD_R_REGISTER + REG_CONFIG, &tmpreg, 1);
  tmpreg |= CONFIG_PRIM_RX;
  cmd(CMD_W_REGISTER + REG_CONFIG, &tmpreg, 1);
}

void NRF24_TxMode(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg;
  cmd(CMD_R_REGISTER + REG_CONFIG, &tmpreg, 1);
  tmpreg &= ~CONFIG_PRIM_RX;
  cmd(CMD_W_REGISTER + REG_CONFIG, &tmpreg, 1);
}

void NRF24_TxPacket(NRF24_HandleTypeDef *hradio, void *buffer, size_t size)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg;
  cmd(CMD_W_TX_PAYLOAD, (uint8_t *)buffer, size);
}

void NRF24_RxPacket(NRF24_HandleTypeDef *hradio, void *buffer, size_t size)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg;
  cmd(CMD_R_RX_PAYLOAD, (uint8_t *)buffer, size);
}

void NRF24_TxFlush(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg = 0x00;
  cmd(CMD_FLUSH_TX, &tmpreg, 1);
}

void NRF24_RxFlush(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  uint8_t tmpreg = 0x00;
  cmd(CMD_FLUSH_RX, &tmpreg, 1);
}