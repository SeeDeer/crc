/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @copyright: Copyright (c) tuya.inc 2021
 * @LastEditTime: 2022-03-22 11:03:49
 *************************************************************************/

#ifndef __CRC_H__
#define __CRC_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t iot_calc_crc32(const uint8_t *data, uint32_t size, uint32_t crc_poly, uint32_t init_value, uint8_t ref_flag, uint32_t xorout);

uint16_t iot_calc_crc16(const uint8_t *data, uint32_t size, uint16_t crc_poly, uint16_t init_value, uint8_t ref_flag, uint16_t xorout);

uint8_t iot_calc_crc8(const uint8_t *data, uint32_t size, uint8_t crc_poly, uint8_t init_value, uint8_t ref_flag, uint8_t xorout);

// 按CRC所用协议直接调用如下宏函数即可，这里只列出部分常用的
#define IOT_CRC8(data,size)             iot_calc_crc8(data,size,0x07,0x00,0,0x00)
#define IOT_CRC8_ITU(data,size)         iot_calc_crc8(data,size,0x07,0x00,0,0x55)
#define IOT_CRC8_ROHC(data,size)        iot_calc_crc8(data,size,0x07,0xFF,1,0x00)
#define IOT_CRC8_MAXIM(data,size)       iot_calc_crc8(data,size,0x31,0x00,1,0x00)

#define IOT_CRC16_CCITT(data,size)      iot_calc_crc16(data,size,0x1021,0x0000,1,0x0000)
#define IOT_CRC16_MODBUS(data,size)     iot_calc_crc16(data,size,0x8005,0xFFFF,1,0x0000)
#define IOT_CRC16_XMODEM(data,size)     iot_calc_crc16(data,size,0x1021,0x0000,0,0x0000)

#define IOT_CRC32(data,size)            iot_calc_crc32(data,size,0x04C11DB7,0xFFFFFFFF,1,0xFFFFFFFF)
#define IOT_CRC32_MPEG2(data,size)      iot_calc_crc32(data,size,0x04C11DB7,0xFFFFFFFF,0,0x00000000)

#ifdef __cplusplus
}
#endif


#endif /* __CRC_H__ */
