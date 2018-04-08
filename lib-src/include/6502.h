/* 6502.h
 * Authors: Jesse Lembo, Lukas Mallory, Steven Savold
 * 
 * This is the main header file for the 6502 emulator library.
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* simple types for dealing with signed(sbyte) and unsigned(ubyte) 8 bit data */
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
 * This is a struct to define the layout of
 * the bus used to talk with peripherals.
 */
struct bus {

    //TODO:
    /* Fill this with the architechure of the 6502 bus */

};


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


#ifdef __cplusplus
} //End of extern "C"
#endif