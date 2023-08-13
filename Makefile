
build:
	gcc crc.c -o crc
	./crc



.PHONY:clean
clean: 
	rm crc