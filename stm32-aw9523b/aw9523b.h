/*
 * Minimal aw9523b library
 *
 * Copyright (c) 2022 Lars Boegild Thomsen <lbthomsen@gmail.com>
 */

#ifndef AW9523B_H_
#define AW9523B_H_

#ifdef DEBUG
#define AW_DBG(...) printf(__VA_ARGS__);\
                    printf("\n");
#else
#define AW_DBG(...) ;
#endif

#define W25QXX_MANUFACTURER_GIGADEVICE 0xC8
#define W25QXX_MANUFACTURER_WINBOND 0xEF

#define W25QXX_DUMMY_BYTE         0xA5
#define W25QXX_GET_ID             0x9F
#define W25QXX_READ_DATA          0x03
#define W25QXX_WRITE_ENABLE       0x06
#define W25QXX_PAGE_PROGRAM       0x02
#define W25QXX_SECTOR_ERASE	      0x20
#define W25QXX_CHIP_ERASE         0xc7
#define W25QXX_READ_REGISTER_1    0x05

typedef struct {
	I2C_HandleTypeDef *i2cHandle;
} AW9523B_HandleTypeDef;

typedef enum {
	AW9523B_Ok,     // 0
    AW9523B_Err,    // 1
    AW9523B_Timeout // 2
} AW9523B_result_t;

AW9523B_result_t AW9523B_init(AW9523B_HandleTypeDef *aw9523b, I2C_HandleTypeDef *hi2c);
//W25QXX_result_t w25qxx_read(W25QXX_HandleTypeDef *w25qxx, uint32_t address, uint8_t *buf, uint32_t len);
//W25QXX_result_t w25qxx_write(W25QXX_HandleTypeDef *w25qxx, uint32_t address, uint8_t *buf, uint32_t len);
//W25QXX_result_t w25qxx_erase(W25QXX_HandleTypeDef *w25qxx, uint32_t address, uint32_t len);
//AW9523B_result_t w25qxx_chip_erase(W25QXX_HandleTypeDef *w25qxx);

#endif /* AW9523B_H_ */
