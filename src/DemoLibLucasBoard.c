/*
===============================================================================
 Name        : DemoLibLucasBoard.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include "pulsador_irq.h"
#include "parpadeo.h"
#include "i2c_eeprom.h"
#include "display_1602.h"

#include <cr_section_macros.h>

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	main routine for examples
 * @return	Function should not exit.
 */
int main(void) {

#if defined (__USE_LPCOPEN)
	// Read clock settings and update SystemCoreClock variable
	SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
	// Set up and initialize all required blocks and
	// functions related to the board hardware
	Board_Init();

	#endif
#endif

	Pulsador_Irq_Init();
	I2C_Eeprom_Init();
	I2C_Eeprom_Escribir();
	I2C_Eeprom_Leer();
	LCD_Init();
	LCD_Print("INICIALIZANDO...");

	while (1) {

		Pulsador_Irq_Sec();
		Parpadeo_Sec();
	}
	return 0;
}


