/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @copyright: Copyright (c) tuya.inc 2021
 * @LastEditTime: 2022-03-22 11:36:22
 *************************************************************************/
#include <stdio.h>
#include "crc.h"

int main(int argc, char **argv)
{
    uint8_t data[5] = {0x5A,0x13,0x01};
    // uint8_t data[] = {0x5A,0x13,0x00,0xCF,0x2F};

    uint32_t crc = 0;
    crc = IOT_CRC16_XMODEM(&data[0], 3);
    printf("crc16-xmodem:%x\n", crc);

    data[3] = crc >> 8;
    data[4] = crc & 0xff;
    crc = IOT_CRC16_XMODEM(&data[0], 5);
    printf("crc16-xmodem:%x\n", crc);

    // 认为制造错误帧验证通过
    data[2] = 0x00;
    data[3] = 0xCF;
    data[4] = 0x2F;
    crc = IOT_CRC16_XMODEM(&data[0], 5);
    printf("crc16-xmodem:%x\n", crc);


    return 0;
}


