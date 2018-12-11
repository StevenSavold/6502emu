/* Core.h
 * Written by Steven Savold 
 * 
 * This file provides the preprocessor macros
 * for _6502_API and other useful build config
 * macros. As well as all the essential types for 
 * the 6502 chip
 */
#pragma once 

 /* if the platform is windows, you need __declspec calls */
#ifdef _6502_PLATFORM_WINDOWS
    #ifdef _6502_BUILD_DLL
        #define _6502_API __declspec(dllexport)
    #else 
        #define _6502_API __declspec(dllimport)
    #endif

/* if the platform is not windows, you don't need __declspec calls */
#else
    #define _6502_API /* Empty_6502_API */
#endif


typedef int8_t  sbyte;
typedef uint8_t ubyte;


/* simple types for dealing with signed(sword) and unsigned(uword) 16 bit data */
typedef int16_t  sword;
typedef uint16_t uword;

typedef union byte byte;
typedef union word word;

/*
 * The data type for representing the 6502 chip
 */
typedef struct cpu6502 cpu6502;

/* 
 * The data type for defining the attributes of the bus the 6502 
 * uses to interact with peripherals. 
 */
typedef struct bus bus;


/*
 * This is a union to make working with bytes easier,
 * You can access byte data with:
 *      byte x = 0xFF;
 * 
 * signed form     -> x.s
 * unsigned form   -> x.u
 *          -- or in --
 * individual bits -> x.bit1
 */
union byte {
	struct {
		ubyte bit0 : 1;
		ubyte bit1 : 1;
		ubyte bit2 : 1;
		ubyte bit3 : 1;
		ubyte bit4 : 1;
		ubyte bit5 : 1;
		ubyte bit6 : 1;
		ubyte bit7 : 1;
	};
	sbyte s;
	ubyte u;
};


/*
 * This is a union to make working with words easier,
 * You can access word data with:
 *       word x = 0xFFFF;
 * 
 * signed form     -> x.s
 * unsigned form   -> x.u
 *          -- or in --
 * individual bits -> x.bit10
 */
union word {
	struct {
		uword bit0  : 1;
		uword bit1  : 1;
		uword bit2  : 1;
		uword bit3  : 1;
		uword bit4  : 1;
		uword bit5  : 1;
		uword bit6  : 1;
		uword bit7  : 1;
		uword bit8  : 1;
		uword bit9  : 1;
		uword bit10 : 1;
		uword bit11 : 1;
		uword bit12 : 1;
		uword bit13 : 1;
		uword bit14 : 1;
		uword bit15 : 1;
	};
	sword s;
	uword u;
};



/*
 * This is a struct to define the layout of
 * the bus used to talk with peripherals.
 * 
 * The layout of the actual pins of the 6502
 * can be found here:
 *     https://upload.wikimedia.org/wikipedia/commons/thumb/4/44/MOS6502.svg/215px-MOS6502.svg.png
 */
struct _6502_API bus {

	/* Architechure consists of:
	 *     - 8 bit wide data bus
	 * 
	 *     - 16 bit wide adress bus
	 * 
	 *     - some control lines that 
	 *       carried syncronisation 
	 *       signals throughout the
	 *       system.
	 * 
	 * The pins should be accessed as follows:
	 *          1 -> VSS
	 *          2 -> RDY
	 *          3 -> 01 (OUT)
	 *          4 -> IRQ
	 *          5 -> N.C.
	 *          6 -> NMI
	 *          7 -> SYNC
	 *          8 -> VCC
	 *     9 - 25 -> Addr
	 *    26 - 33 -> Data
	 *         34 -> R/W
	 *         35 -> N.C.
	 *         36 -> N.C.
	 *         37 -> 01 (IN)
	 *         38 -> SO
	 *         39 -> 02 (OUT)
	 *         40 -> RES 
	 */


	/* Pin 33 -> D0, Pin 26 -> D7 */
	byte data; //Data lines

	/* Pin 9 -> A0, Pin 25 -> A15 */
	word addr; //Address lines

	/* Pins 1 - 8, and 34 - 40 are control pins
	 * meaing...  Pins 1 - 8 are bits 1 - 8 in ctrl as shown in the 
	 *            above listings 
	 * 
	 * and...     Pins 34 - 40 are bits 9 - 15 in ctrl
	 * 
	 * leaving... bit 0 to be empty, this is good because both
	 *            signed and unsigned versions of ctrl will
	 *            be the same  
	 */
	word ctrl; //Control lines (Should be used as one bit per line) 

};
