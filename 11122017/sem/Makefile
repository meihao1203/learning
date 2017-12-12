add1:add1.c add2.c zero.c
	gcc add1.c -o add1
	gcc add2.c -o add2
	gcc zero.c -o zero
	gcc printf.c -o printf
.PHONY:clean rebuild
rebuild:
	make clean add1
clean:
	rm -f add1 add2 zero printf