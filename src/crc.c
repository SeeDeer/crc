/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @copyright: Copyright (c) tuya.inc 2021
 * @LastEditTime: 2022-03-22 11:09:29
 *************************************************************************/
#include <stddef.h>
#include <stdint.h>

static uint8_t __invert_uint8(const uint8_t data)
{
    uint8_t i,result = 0;
    for ( i = 0; i < 8; i++){
        if (data & (1 << i)){
            result |= 1 << (7-i);
        }
    }
    return result;
}

static uint16_t __invert_uint16(const uint16_t data)
{
    uint16_t i,result = 0;
    for ( i = 0; i < 16; i++){
        if (data & (1 << i)){
            result |= 1 << (15-i);
        }
    }
    return result;
}

static uint32_t __invert_uint32(const uint32_t data)
{
    uint32_t i,result = 0;
    for ( i = 0; i < 32; i++){
        if (data & (1 << i)){
            result |= 1 << (31-i);
        }
    }
    return result;
}

/*****************************************************************
 * @Function: iot_calc_crc32
 * @Description: 计算CRC32值的算法实现，适配所有CRC32的协议
 * @Return: uint32_t
 *****************************************************************/
uint32_t iot_calc_crc32(const uint8_t *data, uint32_t size, uint32_t crc_poly, uint32_t init_value, uint8_t ref_flag, uint32_t xorout)
{    
    uint32_t crc_reg = init_value,tmp = 0;
    uint8_t j,byte = 0;
    
    while (size--){
        byte = *(data++);
        if (ref_flag) {
            byte = __invert_uint8(byte);
        }
        crc_reg ^= byte << 24;
        for ( j = 0; j < 8; j++) {
            tmp = crc_reg & 0x80000000;
            crc_reg <<= 1;
            if (tmp)
                crc_reg ^= crc_poly;
        }
    }
    
    if (ref_flag) {
        crc_reg = __invert_uint32(crc_reg);
    }
    crc_reg = crc_reg ^ xorout;
    
    return crc_reg;
}

uint16_t iot_calc_crc16(const uint8_t *data, uint32_t size, uint16_t crc_poly, uint16_t init_value, uint8_t ref_flag, uint16_t xorout)
{    
    uint16_t crc_reg = init_value,tmp = 0;
    uint8_t j,byte = 0;
    
    while (size--){
        byte = *(data++);
        if (ref_flag) {
            byte = __invert_uint8(byte);
        }
        crc_reg ^= byte << 8;
        for ( j = 0; j < 8; j++) {
            tmp = crc_reg & 0x8000;
            crc_reg <<= 1;
            if (tmp)
                crc_reg ^= crc_poly;
        }
    }
    
    if (ref_flag) {
        crc_reg = __invert_uint16(crc_reg);
    }
    crc_reg = crc_reg ^ xorout;
    
    return crc_reg;
}

uint8_t iot_calc_crc8(const uint8_t *data, uint32_t size, uint8_t crc_poly, uint8_t init_value, uint8_t ref_flag, uint8_t xorout)
{    
    uint8_t crc_reg = init_value,tmp = 0;
    uint8_t j,byte = 0;
    
    while (size--){
        byte = *(data++);
        if (ref_flag) {
            byte = __invert_uint8(byte);
        }
        crc_reg ^= byte;
        for ( j = 0; j < 8; j++) {
            tmp = crc_reg & 0x80;
            crc_reg <<= 1;
            if (tmp)
                crc_reg ^= crc_poly;
        }
    }
    
    if (ref_flag) {
        crc_reg = __invert_uint8(crc_reg);
    }
    crc_reg = crc_reg ^ xorout;
    
    return crc_reg;
}


