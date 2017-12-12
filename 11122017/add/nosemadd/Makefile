printf:add1.c add2.c zero.c
	gcc add1.c -o add1
	gcc add2.c -o add2
	gcc printf.c -o printf
	gcc zero.c -o zero
.PHONY:rebuild clean
rebuild:
	make clean printf
clean:	
	rm -f add1 add2 printf zero