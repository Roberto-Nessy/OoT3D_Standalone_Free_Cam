OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(loader_patch)
SECTIONS
{
	. = 0x100000;
	.patch_loader 0x100000 : {
		*(.patch_loader)
	}

	.patch_CameraUpdate 0x2D84C8 : {
	    * (.patch_CameraUpdate)
	}

	.patch_before_GlobalContext_Update 0x4523B0 : {
		*(.patch_before_GlobalContext_Update)
	}

	.patch_after_GlobalContext_Update 0x452454 : {
		*(.patch_after_GlobalContext_Update)
	}

	. = 0x4C99A8;
	. = ALIGN(4);
	.loader : {
		*(.loader*)
	}

	. = 0x005C7000;
	.text : {
		__text_start = . ;
		*(.text)
		*(.text.*)
		*(.rodata)
		*(.data)
		*(.bss)
		*(COMMON)
		__text_end  = . ;
	}
}
