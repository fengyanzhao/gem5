isox:
	arm-isox-linux-gnueabi-gcc -c main.s -o main.o
	arm-isox-linux-gnueabi-gcc -c comp.s -o comp.o
	arm-isox-linux-gnueabi-gcc -T isoxld.ld -static main.o comp.o -o isox
clean:
	rm *.o isox
