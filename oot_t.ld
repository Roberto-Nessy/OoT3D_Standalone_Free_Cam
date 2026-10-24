OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(loader_patch)
SECTIONS
{
	. = 0x100000;
	.patch_loader 0x100000 : {
		*(.patch_loader)
	}

	.patch_CameraUpdate 0x2ED2C8 : {
	    * (.patch_CameraUpdate)
	}

	.patch_before_GlobalContext_Update 0x13A2C4 : {
		*(.patch_before_GlobalContext_Update)
	}

	.patch_after_GlobalContext_Update 0x13A320 : {
		*(.patch_after_GlobalContext_Update)
	}

	. = 0x4CF3C4;
	. = ALIGN(4);
	.loader : {
		*(.loader*)
	}

	. = 0x005CE000;
	.text : {
		__text_start = . ;
		*(.text)
		*(.text.*)
		__text_end  = . ;
		*(.rodata)
		*(.rodata.*)
		*(.data)
		*(.bss)
		*(COMMON)
	}
}
