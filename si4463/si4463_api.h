// SI4463 commands (from API documentation)
#define CMD_POWER_UP                0x02

#define CMD_NOP                     0x00
#define CMD_PART_INFO               0x01
#define CMD_FUNC_INFO               0x10
#define CMD_SET_PROPERTY            0x11
#define CMD_GET_PROPERTY            0x12
#define CMD_GPIO_PIN_CFG            0x13
#define CMD_FIFO_INFO               0x15
#define CMD_GET_INT_STATUS          0x20
#define CMD_REQUEST_DEVICE_STATE    0x33
#define CMD_CHANGE_STATE            0x34
#define CMD_READ_CMD_BUFF           0x44
#define CMD_FRR_A_READ              0x50
#define CMD_FRR_B_READ              0x53
#define CMD_FRR_C_READ              0x55
#define CMD_FRR_D_READ              0x57

#define CMD_IRCAL                   0x17
#define CMD_IRCAL_MANUAL            0x1A

#define CMD_START_TX                0x31
#define CMD_WRITE_TX_FIFO           0x66

#define CMD_PACKET_INFO             0x16
#define CMD_GET_MODEM_STATUS        0x22
#define CMD_START_RX                0x32
#define CMD_RX_HOP                  0x36
#define CMD_READ_RX_FIFO            0x77

#define CMD_GET_ADC_READING         0x14
#define CMD_GET_PH_STATUS           0x21
#define CMD_GET_CHIP_STATUS         0x23

// SI4463 property groups
#define GRP_GLOBAL                  0x00
#define GRP_INT_CTL                 0x01
#define GRP_FRR_CTL                 0x02
#define GRP_PREAMBLE                0x10
#define GRP_SYNC                    0x11
#define GRP_PKT                     0x12
#define GRP_MODEM                   0x20
#define GRP_MODEM_CHFLT             0x21
#define GRP_PA                      0x22
#define GRP_SYNTH                   0x23
#define GRP_MATCH                   0x30
#define GRP_FREQ_CONTROL            0x40
#define GRP_RX_HOP                  0x50