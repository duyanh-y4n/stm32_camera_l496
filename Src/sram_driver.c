/*
 * sram_driver.c
 *
 *  Created on: 26.08.2019
 *      Author: hungv
 */

#include "stm32l496xx.h"
#include "sram_driver.h"
#include "var_interface.h"

//uint16_t aTxBuffer[BUFFER_SIZE] = { 0x1011, 0x1112, 0x0213, 0x0314, 0x0415, 0x0516, 0x0617,
//		0x0718, 0x0819, 0x09AB, 0x0AAC, 0x0BAF, 0x0CBC, 0x0DAB, 0x0EAE, 0x0FAB };
uint16_t aRxBuffer[BUFFER_SIZE] = { 0 };
/* Counter index */
uint32_t uwIndex = 0;
uint32_t length = 16;

void SRAM_Write(uint16_t *aTxBuffer) {

//	HAL_DMA_Start_IT(&hdma_memtomem_dma1_channel1, (uint32_t) aTxBuffer,
//			(uint32_t) (0x68000800), length);
//
	for (uwIndex = 0; uwIndex < BUFFER_SIZE; uwIndex++) {
		*(__IO uint16_t*) (SRAM_BANK_ADDR + WRITE_READ_ADDR + 2 * uwIndex) =
				aTxBuffer[uwIndex];
	}
	HAL_DMA_Abort(&hdma_memtomem_dma1_channel1);
}

void SRAM_Read(void) {
	for (uwIndex = 0; uwIndex < BUFFER_SIZE; uwIndex++) {
		aRxBuffer[uwIndex] = *(__IO uint16_t*) (SRAM_BANK_ADDR +
		WRITE_READ_ADDR + 2 * uwIndex);

	}
}

