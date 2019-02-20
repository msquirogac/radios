/****************************************************************/
/* Commands */
#define CMD_R_REGISTER         0x00  // Define read command to register
#define CMD_W_REGISTER         0x20  // Define write command to register
#define CMD_R_RX_PAYLOAD       0x61  // Define RX payload register address
#define CMD_W_TX_PAYLOAD       0xA0  // Define TX payload register address
#define CMD_FLUSH_TX           0xE1  // Define flush TX register command
#define CMD_FLUSH_RX           0xE2  // Define flush RX register command
#define CMD_REUSE_TX_PL        0xE3  // Define reuse TX payload register command
#define CMD_ACTIVATE           0x50  // Define activate command
#define CMD_R_RX_PL_WID        0x60  // Define Read RX payload command
#define CMD_W_ACK_PAYLOAD      0xA8  // Define Write ACK payload command
#define CMD_W_TX_PAYLOAD_NOACK 0xB0  // Define Write ACK payload command
#define CMD_NOP                0xFF  // Define No Operation, might be used to read status register

/****************************************************************/
/* Registers */
#define REG_CONFIG          0x00  // 'Config' register address
#define REG_EN_AA           0x01  // 'Enable Auto Acknowledgment' register address
#define REG_EN_RXADDR       0x02  // 'Enabled RX addresses' register address
#define REG_SETUP_AW        0x03  // 'Setup address width' register address
#define REG_SETUP_RETR      0x04  // 'Setup Auto. Retrans' register address
#define REG_RF_CH           0x05  // 'RF channel' register address
#define REG_RF_SETUP        0x06  // 'RF setup' register address
#define REG_STATUS          0x07  // 'Status' register address
#define REG_OBSERVE_TX      0x08  // 'Observe TX' register address
#define REG_CD              0x09  // 'Carrier Detect
#define REG_RX_ADDR_P0      0x0A  // 'RX address pipe0' register address
#define REG_RX_ADDR_P1      0x0B  // 'RX address pipe1' register address
#define REG_RX_ADDR_P2      0x0C  // 'RX address pipe2' register address
#define REG_RX_ADDR_P3      0x0D  // 'RX address pipe3' register address
#define REG_RX_ADDR_P4      0x0E  // 'RX address pipe4' register address
#define REG_RX_ADDR_P5      0x0F  // 'RX address pipe5' register address
#define REG_TX_ADDR         0x10  // 'TX address' register address
#define REG_RX_PW_P0        0x11  // 'RX payload width, pipe0' register address
#define REG_RX_PW_P1        0x12  // 'RX payload width, pipe1' register address
#define REG_RX_PW_P2        0x13  // 'RX payload width, pipe2' register address
#define REG_RX_PW_P3        0x14  // 'RX payload width, pipe3' register address
#define REG_RX_PW_P4        0x15  // 'RX payload width, pipe4' register address
#define REG_RX_PW_P5        0x16  // 'RX payload width, pipe5' register address
#define REG_FIFO_STATUS     0x17  // 'FIFO Status Register' register address
#define REG_DYNPD           0x1C  // 'Dynamic payload setup
#define REG_FEATURE         0x1D  // 'Exclusive feature setup

/****************************************************************/
/* CONFIG register bitwise definitions */
#define CONFIG_RESERVED			0x80
#define CONFIG_MASK_RX_DR		0x40
#define CONFIG_MASK_TX_DS		0x20
#define CONFIG_MASK_MAX_RT	0x10
#define CONFIG_EN_CRC				0x08
#define CONFIG_CRCO					0x04
#define CONFIG_PWR_UP				0x02
#define CONFIG_PRIM_RX			0x01

/****************************************************************/
/* EN_AA register bit definitions */
#define EN_AA_ENAA_RESERVED 0xC0
#define EN_AA_ENAA_P5       0x20
#define EN_AA_ENAA_P4       0x10
#define EN_AA_ENAA_P3       0x08
#define EN_AA_ENAA_P2       0x04
#define EN_AA_ENAA_P1       0x02
#define EN_AA_ENAA_P0       0x01

/****************************************************************/
/* EN_RXADDR register bit definitions */
#define EN_RXADDR_RESERVED  0xC0
#define EN_RXADDR_ERX_P5    0x20
#define EN_RXADDR_ERX_P4    0x10
#define EN_RXADDR_ERX_P3    0x08
#define EN_RXADDR_ERX_P2    0x04
#define EN_RXADDR_ERX_P1    0x02
#define EN_RXADDR_ERX_P0    0x01

/****************************************************************/
/* SETUP_AW register bit definitions */
#define SETUP_AW_RESERVED   0x3F
#define SETUP_AW_ADRW_3B    0x01
#define SETUP_AW_ADRW_4B    0x02
#define SETUP_AW_ADRW_5B    0x03

/****************************************************************/
/* SETUP_RETR register bitwise definitions */
#define SETUP_RETR_ARD			0xF0
#define SETUP_RETR_ARD_4000	0xF0 /* 4400 us retry delay */
#define SETUP_RETR_ARD_3750	0xE0 /* 3750 us retry delay */
#define SETUP_RETR_ARD_3500	0xD0 /* 3500 us retry delay */
#define SETUP_RETR_ARD_3250	0xC0 /* 3250 us retry delay */
#define SETUP_RETR_ARD_3000	0xB0 /* 3000 us retry delay */
#define SETUP_RETR_ARD_2750	0xA0 /* 2750 us retry delay */
#define SETUP_RETR_ARD_2500	0x90 /* 2500 us retry delay */
#define SETUP_RETR_ARD_2250	0x80 /* 2250 us retry delay */
#define SETUP_RETR_ARD_2000	0x70 /* 2000 us retry delay */
#define SETUP_RETR_ARD_1750	0x60 /* 1750 us retry delay */
#define SETUP_RETR_ARD_1500	0x50 /* 1500 us retry delay */
#define SETUP_RETR_ARD_1250	0x40 /* 1250 us retry delay */
#define SETUP_RETR_ARD_1000	0x30 /* 1000 us retry delay */
#define SETUP_RETR_ARD_750	0x20 /* 750 us retry delay */
#define SETUP_RETR_ARD_500	0x10 /* 500 us retry delay */
#define SETUP_RETR_ARD_250	0x00 /* 250 us retry delay */
#define SETUP_RETR_ARC		  0x0F
#define SETUP_RETR_ARC_15	  0x0F /* 15 retry count */
#define SETUP_RETR_ARC_14  	0x0E /* 14 retry count */
#define SETUP_RETR_ARC_13	  0x0D /* 13 retry count */
#define SETUP_RETR_ARC_12  	0x0C /* 12 retry count */
#define SETUP_RETR_ARC_11  	0x0B /* 11 retry count */
#define SETUP_RETR_ARC_10  	0x0A /* 10 retry count */
#define SETUP_RETR_ARC_9	  0x09 /* 9 retry count */
#define SETUP_RETR_ARC_8  	0x08 /* 8 retry count */
#define SETUP_RETR_ARC_7	  0x07 /* 7 retry count */
#define SETUP_RETR_ARC_6	  0x06 /* 6 retry count */
#define SETUP_RETR_ARC_5	  0x05 /* 5 retry count */
#define SETUP_RETR_ARC_4	  0x04 /* 4 retry count */
#define SETUP_RETR_ARC_3	  0x03 /* 3 retry count */
#define SETUP_RETR_ARC_2	  0x02 /* 2 retry count */
#define SETUP_RETR_ARC_1	  0x01 /* 1 retry count */
#define SETUP_RETR_ARC_0	  0x00 /* 0 retry count, retry disabled */

/****************************************************************/
/* RF_CH register bitwise definitions */
#define RF_CH_RESERVED	  	0x80

/****************************************************************/
/* RF_SETUP register bitwise definitions */
#define RF_SETUP_RESERVED		0xE0
#define RF_SETUP_PLL_LOCK		0x10
#define RF_SETUP_RF_DR			0x28
#define RF_SETUP_RF_DR_250	0x20
#define RF_SETUP_RF_DR_1000	0x00
#define RF_SETUP_RF_DR_2000	0x08
#define RF_SETUP_RF_PWR			0x06
#define RF_SETUP_RF_PWR_0		0x06
#define RF_SETUP_RF_PWR_6		0x04
#define RF_SETUP_RF_PWR_12	0x02
#define RF_SETUP_RF_PWR_18	0x00

/****************************************************************/
/* DYNPD register bitwise definitions */
#define DYNPD_RESERVED		  0xC0
#define DYNPD_DPL_P5		    0x20
#define DYNPD_DPL_P4		    0x10
#define DYNPD_DPL_P3		    0x08
#define DYNPD_DPL_P2		    0x04
#define DYNPD_DPL_P1		    0x02
#define DYNPD_DPL_P0		    0x01

/****************************************************************/
/* FEATURE register bitwise definitions */
#define FEATURE_RESERVED		0xF8
#define FEATURE_EN_DPL			0x04
#define FEATURE_EN_ACK_PAY	0x02
#define FEATURE_EN_DYN_ACK	0x01

/****************************************************************/
/* STATUS register bit definitions */
#define STATUS_RESERVED	    0x80 /* bit 1xxx xxxx: This bit is reserved */
#define STATUS_RX_DR		    0x40 /* bit x1xx xxxx: Data ready RX FIFO interrupt. Asserted when new data arrives RX FIFO */
#define STATUS_TX_DS		    0x20 /* bit xx1x xxxx: Data sent TX FIFO interrupt. Asserted when packet transmitted on TX. */
#define STATUS_MAX_RT		    0x10 /* bit xxx1 xxxx: maximum number of TX retransmit interrupts */
#define STATUS_TX_FULL	    0x01 /* bit xxxx xxx1: if bit set, then TX FIFO is full */
#define STATUS_RX_P_NO	    0x0E

/****************************************************************/
/* FIFO_STATUS register bit definitions */
#define FIFO_STATUS_RESERVED	0x8C
#define FIFO_STATUS_TX_REUSE	0x40
#define FIFO_STATUS_TX_FULL		0x20
#define FIFO_STATUS_TX_EMPTY	0x10
#define FIFO_STATUS_RX_FULL		0x02
#define FIFO_STATUS_RX_EMPTY	0x01
