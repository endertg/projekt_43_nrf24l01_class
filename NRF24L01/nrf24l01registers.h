/*
nrf24l01 lib 0x02

copyright (c) Davide Gironi, 2012

Released under GPLv3.
Please refer to LICENSE file for licensing information.
*/

//CE 	PB0 	PIN 14
//CSN 	PB1 	PIN 15
//MOSI 	PB3  	PIN 17
//MISO	PB4		PIN 18
//SCK 	PB5		PIN 19
//IRQ	PD2		PIN 4

/* Memory Map */
#define NRF24L01_REG_CONFIG      0x00
#define NRF24L01_REG_EN_AA       0x01
#define NRF24L01_REG_EN_RXADDR   0x02
#define NRF24L01_REG_SETUP_AW    0x03
#define NRF24L01_REG_SETUP_RETR  0x04
#define NRF24L01_REG_RF_CH       0x05
#define NRF24L01_REG_RF_SETUP    0x06
#define NRF24L01_REG_STATUS      0x07
#define NRF24L01_REG_OBSERVE_TX  0x08
#define NRF24L01_REG_CD          0x09
#define NRF24L01_REG_RX_ADDR_P0  0x0A
#define NRF24L01_REG_RX_ADDR_P1  0x0B
#define NRF24L01_REG_RX_ADDR_P2  0x0C
#define NRF24L01_REG_RX_ADDR_P3  0x0D
#define NRF24L01_REG_RX_ADDR_P4  0x0E
#define NRF24L01_REG_RX_ADDR_P5  0x0F
#define NRF24L01_REG_TX_ADDR     0x10
#define NRF24L01_REG_RX_PW_P0    0x11
#define NRF24L01_REG_RX_PW_P1    0x12
#define NRF24L01_REG_RX_PW_P2    0x13
#define NRF24L01_REG_RX_PW_P3    0x14
#define NRF24L01_REG_RX_PW_P4    0x15
#define NRF24L01_REG_RX_PW_P5    0x16
#define NRF24L01_REG_FIFO_STATUS 0x17
#define NRF24L01_REG_FEATURE     0x1D
#define NRF24L01_REG_DYNPD	     0x1C

/* Bit Mnemonics */
#define NRF24L01_REG_MASK_RX_DR  6
#define NRF24L01_REG_MASK_TX_DS  5
#define NRF24L01_REG_MASK_MAX_RT 4
#define NRF24L01_REG_EN_CRC      3
#define NRF24L01_REG_CRCO        2
#define NRF24L01_REG_PWR_UP      1
#define NRF24L01_REG_PRIM_RX     0
#define NRF24L01_REG_ENAA_P5     5
#define NRF24L01_REG_ENAA_P4     4
#define NRF24L01_REG_ENAA_P3     3
#define NRF24L01_REG_ENAA_P2     2
#define NRF24L01_REG_ENAA_P1     1
#define NRF24L01_REG_ENAA_P0     0
#define NRF24L01_REG_ERX_P5      5
#define NRF24L01_REG_ERX_P4      4
#define NRF24L01_REG_ERX_P3      3
#define NRF24L01_REG_ERX_P2      2
#define NRF24L01_REG_ERX_P1      1
#define NRF24L01_REG_ERX_P0      0
#define NRF24L01_REG_AW          0
#define NRF24L01_REG_ARD         4
#define NRF24L01_REG_ARC         0
#define NRF24L01_REG_PLL_LOCK    4
#define NRF24L01_REG_RF_DR       3
#define NRF24L01_REG_RF_PWR      1
#define NRF24L01_REG_LNA_HCURR   0
#define NRF24L01_REG_RX_DR       6
#define NRF24L01_REG_TX_DS       5
#define NRF24L01_REG_MAX_RT      4
#define NRF24L01_REG_RX_P_NO     1
#define NRF24L01_REG_TX_FULL     0
#define NRF24L01_REG_PLOS_CNT    4
#define NRF24L01_REG_ARC_CNT     0
#define NRF24L01_REG_TX_REUSE    6
#define NRF24L01_REG_FIFO_FULL   5
#define NRF24L01_REG_TX_EMPTY    4
#define NRF24L01_REG_RX_FULL     1
#define NRF24L01_REG_RX_EMPTY    0
#define NRF24L01_REG_RPD         0x09
#define NRF24L01_REG_RF_DR_LOW   5
#define NRF24L01_REG_RF_DR_HIGH  3
#define NRF24L01_REG_RF_PWR_LOW  1
#define NRF24L01_REG_RF_PWR_HIGH 2

/* Instruction Mnemonics */
#define NRF24L01_CMD_R_REGISTER    0x00
#define NRF24L01_CMD_W_REGISTER    0x20
#define NRF24L01_CMD_REGISTER_MASK 0x1F
#define NRF24L01_CMD_R_RX_PAYLOAD  0x61
#define NRF24L01_CMD_W_TX_PAYLOAD  0xA0
#define NRF24L01_CMD_FLUSH_TX      0xE1
#define NRF24L01_CMD_FLUSH_RX      0xE2
#define NRF24L01_CMD_REUSE_TX_PL   0xE3
#define NRF24L01_CMD_NOP           0xFF


//***********************************


//define the spi path
#define NRF24L01_SPIPATH "../spi/spi_aw.h" //spi lib path

//CE and CSN functions
#define nrf24l01_CSNhi NRF24L01_PORT |= (1<<NRF24L01_CSN);
#define nrf24l01_CSNlo NRF24L01_PORT &= ~(1<<NRF24L01_CSN);
#define nrf24l01_CEhi NRF24L01_PORT |=  (1<<NRF24L01_CE);
#define nrf24l01_CElo NRF24L01_PORT &= ~(1<<NRF24L01_CE);

//power setup
#define NRF24L01_RF24_PA_MIN 1
#define NRF24L01_RF24_PA_LOW 2
#define NRF24L01_RF24_PA_HIGH 3
#define NRF24L01_RF24_PA_MAX 4
#define NRF24L01_RF24_PA NRF24L01_RF24_PA_MAX

//speed setup
#define NRF24L01_RF24_SPEED_250KBPS 1
#define NRF24L01_RF24_SPEED_1MBPS 2
#define NRF24L01_RF24_SPEED_2MBPS 3
#define NRF24L01_RF24_SPEED NRF24L01_RF24_SPEED_250KBPS

//crc setup
#define NRF24L01_RF24_CRC_DISABLED 1
#define NRF24L01_RF24_CRC_8 2
#define NRF24L01_RF24_CRC_16 3
#define NRF24L01_RF24_CRC NRF24L01_RF24_CRC_8

//transmission channel
#define NRF24L01_CH 95

//payload lenght
#define NRF24L01_PAYLOAD 6

//auto ack enabled
#define NRF24L01_ACK 0

//auto retransmit delay and count
#define NRF24L01_RETR (0b0100 << NRF24L01_REG_ARD) | (0b0111 << NRF24L01_REG_ARC) //1500uS, 15 times

//enable / disable pipe
#define NRF24L01_ENABLEDP0 1 //pipe 0
#define NRF24L01_ENABLEDP1 1 //pipe 1
#define NRF24L01_ENABLEDP2 1 //pipe 2
#define NRF24L01_ENABLEDP3 1 //pipe 3
#define NRF24L01_ENABLEDP4 1 //pipe 4
#define NRF24L01_ENABLEDP5 1 //pipe 5

//address size
#define NRF24L01_ADDRSIZE 5

//pipe address
#define NRF24L01_ADDRP0 {0xE8, 0xE8, 0xF0, 0xF0, 0xE2} //pipe 0, 5 byte address
#define NRF24L01_ADDRP1 {0xC1, 0xC2, 0xC2, 0xC2, 0xC2} //pipe 1, 5 byte address
#define NRF24L01_ADDRP2 {0xC1, 0xC2, 0xC2, 0xC2, 0xC3} //pipe 2, 5 byte address
#define NRF24L01_ADDRP3 {0xC1, 0xC2, 0xC2, 0xC2, 0xC4} //pipe 3, 5 byte address
#define NRF24L01_ADDRP4 {0xC1, 0xC2, 0xC2, 0xC2, 0xC5} //pipe 4, 5 byte address
#define NRF24L01_ADDRP5 {0xC1, 0xC2, 0xC2, 0xC2, 0xC6} //pipe 5, 5 byte address
#define NRF24L01_ADDRTX {0xE8, 0xE8, 0xF0, 0xF0, 0xE2} //tx default address*/

 //enable print info function
#define NRF24L01_PRINTENABLE 1
