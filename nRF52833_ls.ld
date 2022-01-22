ENTRY(Reset_Handler)

MEMORY
{
  FLASH(rx): ORIGIN =0x00000000, LENGTH =512K
  SRAM(rwx): ORIGIN =0x20000000, LENGTH =128K
}


SECTIONS
{
  .text :
  {
    *(.isr_vector)
    *(.text)							/* (.text) says merge all .text sections of all input files */
	*(.text.*)							/* combine all .text sections under the main .text section */
	*(.init)							/* put .init section under .text */
	*(.fini)							/* put .fini section under .text */
	*(.rodata)
	*(.rodata.*)
	/*__exidx_start = .;*/
	/* .ARM.exidx : { *(.ARM.exidx*) }*/
	/*__exidx_end = .;*/
	. = ALIGN(4);
	_etext = .;							/* Store the updated location counter '.' value in a symbol called '_etext' */
  }> FLASH								/* This line tells the linker where to put .text section */
  
  _la_data = LOADADDR(.data);
  
  .data :
  {
    _sdata = .;							/* Assign a value to symbol '_sdata' */
	*(.data)
	*(.data.*)
	. = ALIGN(4);
	_edata = .;
  }> SRAM AT> FLASH
  
  .bss :
  {
    _sbss = .;
	__bss_start__ = _sbss;				/* __bss_start__ was added because using nano.spec requires it */
	*(.bss)
	*(.bss.*)
	*(COMMON)
	. = ALIGN(4);
	_ebss = .;
	__bss_end__ = _ebss;				/* __bss_end__ was added because using nano.spec requires it */
	   . = ALIGN(4); 
	end = .;							/* required by syscalls.c to locate the start of heap */
	__end__ = .;						/* required when using semihosting */
  }> SRAM

  __exidx_start = .;
  .ARM.exidx :
  {
	*(.ARM.exodx*)
  }
  __exidx_end = .;
}