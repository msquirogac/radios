#include "si4463.h"

void SI4463_RadioConfig(uint8_t *buffer)
{
	while(buffer[0] != 0)
	{
		SendCommand(buffer[1], buffer + 2, buffer[0] - 1);
		buffer += buffer[0] + 1;
	}
}

//*************************************************************************************//

void SI4463_PartInfo(uint8_t *buffer)
{
	SendCommand(CMD_PART_INFO, NULL, 0);
	if(buffer != NULL)
		RecvCommand(CMD_READ_CMD_BUFF, buffer, 9);
}

void SI4463_FuncInfo(uint8_t *buffer)
{
	SendCommand(CMD_FUNC_INFO, NULL, 0);
	if(buffer != NULL)
		RecvCommand(CMD_READ_CMD_BUFF, buffer, 7);
}

void SI4463_SetProperty(uint8_t group, uint8_t index, uint8_t buffer)
{
	uint8_t tmpreg[] = {group, 1, index, buffer};
	SendCommand(CMD_SET_PROPERTY, tmpreg, 4);
}

void SI4463_GetProperty(uint8_t group, uint8_t index, uint8_t *buffer)
{
	uint8_t tmpreg[] = {group, 1, index};
	SendCommand(CMD_GET_PROPERTY, tmpreg, 3);
	RecvCommand(CMD_READ_CMD_BUFF, tmpreg, 2);
	buffer[0] = tmpreg[1];
}

void SI4463_FifoInfo(uint8_t *buffer, uint8_t reset)
{
	uint8_t tmpreg[1] = {0x03 & reset};
	SendCommand(CMD_FIFO_INFO, tmpreg, 1);
	if(buffer != NULL)
		RecvCommand(CMD_READ_CMD_BUFF, buffer, 3);
}

void SI4463_IntStatus(uint8_t *buffer)
{
	uint8_t tmpreg[3] = {0x00, 0x00, 0x00};
	SendCommand(CMD_GET_INT_STATUS, tmpreg, 3);
	if(buffer != NULL)
		RecvCommand(CMD_READ_CMD_BUFF, buffer, 9);
}

void SI4463_ModemStatus(uint8_t *buffer)
{
	uint8_t tmpreg[1] = {0x00};
	SendCommand(CMD_GET_MODEM_STATUS, tmpreg, 1);
	if(buffer != NULL)
		RecvCommand(CMD_READ_CMD_BUFF, buffer, 9);
}

void SI4463_GetDeviceState(uint8_t *buffer)
{
	SendCommand(CMD_REQUEST_DEVICE_STATE, NULL, 0);
	if(buffer != NULL)
		RecvCommand(CMD_READ_CMD_BUFF, buffer, 3);
}

void SI4463_SetDeviceState(uint8_t state)
{
	uint8_t tmpreg[1] = {0x0F & state};
	SendCommand(CMD_CHANGE_STATE, tmpreg, 1);
}

//*************************************************************************************//

void SI4463_WriteTxFifo(uint8_t *buffer, size_t size)
{
	SendCommand(CMD_WRITE_TX_FIFO, buffer, size);
}

void SI4463_ReadRxFifo(uint8_t *buffer, size_t size)
{
	RecvCommand(CMD_READ_RX_FIFO, buffer, size);
}

void SI4463_StartTX(uint8_t channel, size_t size)
{
	uint8_t tmpreg[] = {channel, 0x30, 0x00, size};
	SendCommand(CMD_START_TX, tmpreg, 4);
}

void SI4463_StartRX(uint8_t channel, size_t size)
{
	uint8_t tmpreg3[7] = {channel, 0x00, 0x00, size, 0x00, 0x03, 0x08};
	SendCommand(CMD_START_RX, tmpreg3, 7);
}