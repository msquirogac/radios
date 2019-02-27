#include "nrf24.h"

void NRF24_SetRegister(NRF24_HandleTypeDef *hradio, uint8_t address, uint8_t value)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_REGISTER + address, &value, 1);
}

uint8_t NRF24_GetRegister(NRF24_HandleTypeDef *hradio, uint8_t address)
{
  NRF24_CommandHandler cmd = hradio->HAL.CommandReturn;
  uint8_t tmpreg;
  cmd(CMD_R_REGISTER + address, &tmpreg, 1);
  return tmpreg;
}

void NRF24_RadioConfig(NRF24_HandleTypeDef *hradio, void *buffer)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  uint8_t *tmpreg = buffer;
  while(tmpreg[0] != 0)
  {
    cmd(CMD_W_REGISTER + tmpreg[1], &tmpreg[2], tmpreg[0]);
    tmpreg += tmpreg[0] + 2;
  }
}

//*************************************************************************************//

void NRF24_Init(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  NRF24_PowerHandler pwr = hradio->HAL.Power;
  uint8_t tmpreg;
  pwr(0);
  tmpreg = CONFIG_EN_CRC | CONFIG_CRCO;
  cmd(CMD_W_REGISTER + REG_CONFIG, &tmpreg, 1);
  tmpreg = 0x00;
  cmd(CMD_W_REGISTER + REG_EN_AA, &tmpreg, 1);
  tmpreg = EN_RXADDR_ERX_P0;
  cmd(CMD_W_REGISTER + REG_EN_RXADDR, &tmpreg, 1);
  tmpreg = SETUP_RETR_ARD_500 | SETUP_RETR_ARC_5;
  cmd(CMD_W_REGISTER + REG_SETUP_RETR, &tmpreg, 1);
  tmpreg = RF_SETUP_RF_DR_250 | RF_SETUP_RF_PWR_0;
  cmd(CMD_W_REGISTER + REG_RF_SETUP, &tmpreg, 1);
  tmpreg = 0x00;
  cmd(CMD_W_REGISTER + REG_FEATURE, &tmpreg, 1);
}

void NRF24_Reset(NRF24_HandleTypeDef *hradio)
{
  NRF24_PowerDown(hradio);
  NRF24_TxFlush(hradio);
  NRF24_RxFlush(hradio);
  NRF24_SetStatus(hradio, STATUS_MAX_RT | STATUS_RX_DR | STATUS_TX_DS);
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

void NRF24_SetRxPayloadSize(NRF24_HandleTypeDef *hradio, uint8_t size)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_REGISTER + REG_RX_PW_P0, &size, 1);
}

void NRF24_SetChannel(NRF24_HandleTypeDef *hradio, uint8_t channel)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_REGISTER + REG_RF_CH, &channel, 1);
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

uint8_t NRF24_GetRxPayloadSize(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.CommandReturn;
  uint8_t tmpreg;
  cmd(CMD_R_RX_PL_WID, &tmpreg, 1);
  return tmpreg;
}

uint8_t NRF24_GetFifoStatus(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.CommandReturn;
  uint8_t tmpreg;
  cmd(CMD_R_REGISTER + REG_FIFO_STATUS, &tmpreg, 1);
  return tmpreg;
}

uint8_t NRF24_GetStatus(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.CommandReturn;
  uint8_t tmpreg;
  cmd(CMD_R_REGISTER + REG_STATUS, &tmpreg, 1);
  return tmpreg;
}

uint8_t NRF24_GetIRQ(NRF24_HandleTypeDef *hradio)
{
  NRF24_InterruptHandler irq = hradio->HAL.Interrupt;
  return irq() ? 0 : 1;
}

void NRF24_PowerUp(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.CommandReturn;
  NRF24_PowerHandler pwr = hradio->HAL.Power;
  uint8_t tmpreg;
  pwr(0);
  cmd(CMD_R_REGISTER + REG_CONFIG, &tmpreg, 1);
  tmpreg |= CONFIG_PWR_UP;
  cmd(CMD_W_REGISTER + REG_CONFIG, &tmpreg, 1);
}

void NRF24_PowerDown(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.CommandReturn;
  NRF24_PowerHandler pwr = hradio->HAL.Power;
  uint8_t tmpreg;
  pwr(0);
  cmd(CMD_R_REGISTER + REG_CONFIG, &tmpreg, 1);
  tmpreg &= ~CONFIG_PWR_UP;
  cmd(CMD_W_REGISTER + REG_CONFIG, &tmpreg, 1);
}

void NRF24_RadioStart(NRF24_HandleTypeDef *hradio)
{
  NRF24_PowerHandler pwr = hradio->HAL.Power;
  pwr(1);
}

void NRF24_RadioStop(NRF24_HandleTypeDef *hradio)
{
  NRF24_PowerHandler pwr = hradio->HAL.Power;
  pwr(0);
}

void NRF24_RxFlush(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_FLUSH_RX, NULL, 0);
}

void NRF24_TxFlush(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_FLUSH_TX, NULL, 0);
}

void NRF24_RxMode(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.CommandReturn;
  uint8_t tmpreg;
  cmd(CMD_R_REGISTER + REG_CONFIG, &tmpreg, 1);
  tmpreg |= CONFIG_PRIM_RX;
  cmd(CMD_W_REGISTER + REG_CONFIG, &tmpreg, 1);
}

void NRF24_TxMode(NRF24_HandleTypeDef *hradio)
{
  NRF24_CommandHandler cmd = hradio->HAL.CommandReturn;
  uint8_t tmpreg;
  cmd(CMD_R_REGISTER + REG_CONFIG, &tmpreg, 1);
  tmpreg &= ~CONFIG_PRIM_RX;
  cmd(CMD_W_REGISTER + REG_CONFIG, &tmpreg, 1);
}

void NRF24_RxPacket(NRF24_HandleTypeDef *hradio, void *buffer, size_t size)
{
  NRF24_CommandHandler cmd = hradio->HAL.CommandReturn;
  cmd(CMD_R_RX_PAYLOAD, (uint8_t *)buffer, size);
}

void NRF24_TxPacket(NRF24_HandleTypeDef *hradio, void *buffer, size_t size)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_TX_PAYLOAD, (uint8_t *)buffer, size);
}

void NRF24_TxPacketNACK(NRF24_HandleTypeDef *hradio, void *buffer, size_t size)
{
  NRF24_CommandHandler cmd = hradio->HAL.Command;
  cmd(CMD_W_TX_PAYLOAD_NOACK, (uint8_t *)buffer, size);
}