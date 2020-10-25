all:
	arm-none-eabi-as --warn --fatal-warnings -mcpu=cortex-m3 startup.s -o startup.o
	arm-none-eabi-gcc -Wall -Werror -O0 -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m3 -mthumb -c rcc.c -o rcc.o
	arm-none-eabi-gcc -Wall -Werror -O0 -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m3 -mthumb -c gpio.c -o gpio.o
	arm-none-eabi-gcc -Wall -Werror -O0 -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m3 -mthumb -c spi.c -o spi.o
	arm-none-eabi-gcc -Wall -Werror -O0 -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m3 -mthumb -c oled.c -o oled.o
	arm-none-eabi-gcc -Wall -Werror -O0 -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m3 -mthumb -c notmain.c -o notmain.o
	arm-none-eabi-ld -o flash.elf -T flash.ld startup.o rcc.o gpio.o spi.o oled.o notmain.o
	arm-none-eabi-objdump -D flash.elf > flash.list
	arm-none-eabi-objcopy flash.elf flash.bin -O binary

clean:
	rm -rf *.bin *.o *.elf *.list