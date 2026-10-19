/*
 * This file will (eventually) be automatically generated, following
 * the method used by RicBent in the program Magikoopa
 */

#ifndef _NEWCODEINFO_H_
#define _NEWCODEINFO_H_

#ifdef Version_TW
#define NEWCODE_OFFSET 0x005CE000 // first page after the TW bss (ends 0x5CDB20), must match oot_t.ld
#else
#define NEWCODE_OFFSET 0x005C7000 //TODO: this
#endif
#define NEWCODE_SIZE   0x0002E000 //TODO: this. even now, this is too big.

#endif //_NEWCODEINFO_H_