#CC: used to hold the compiler for C (use CXX when compiling C++ code)
#MCPU: Holds the cpu architecture (passed as a flag to the compiler as -mcpu=cortex-m4)
#CFLAGS: Holds all the flags to be passed to the compiler (use CXXFLAGS when compiling C++ code)
#LDFLAGS: Holds all the flags to be passed to the linker

CXX= /doc/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-g++
MACH=cortex-m4
CXXFLAGS= -c -g -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu++11 -Wall -O0
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T nRF52833_ls.ld -Wl,-Map=final.map
LDFLAGS_SH= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T nRF52833_ls.ld -Wl,-Map=final.map
#In CFLAGS:
#	-c is used to stop the linker from running
#	-mcpu is used to select the cpu architecture
#	-mthumb is used to select code that executes in Thumb state and not in ARM state
#	-std=gnu11 is used to select C standard of 2011
#	-Wall is used to turn on warning flags
#	-o0 is used to select optimization level 0

#In LDFLAGS:
#	-nostdlib means do not use the standard system startup files or libraries when linking
#	-T is used to pass a linker script
#	nRF52833_ls.ld is a linker script
# 	-Wl,-Map=final.map is one command used to generate a .map file
#	--specs is used to pass a standard library
#	nano.specs is a standard library(called newlib nano) passed when using system calls

#In LDFLAGS_SH:
#	rdimon.specs is passed when using system calls, and here semihosting was used

all:main.o nRF52833_startup.o syscalls.o nRF52833_gpio_driver.o final.elf

semihosting:main.o nRF52833_startup.o syscalls.o final_sh.elf

main.o:main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

nRF52833_startup.o:nRF52833_startup.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

syscalls.o:syscalls.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

nRF52833_gpio_driver.o:nRF52833_gpio_driver.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
	
final.elf: main.o nRF52833_startup.o syscalls.o nRF52833_gpio_driver.o
	$(CXX) $(LDFLAGS) -o $@ $^
	
final_sh.elf: main.o nRF52833_startup.o
	$(CXX) $(LDFLAGS_SH) -o $@ $^

clean:
	rm -rf *.o *.elf
