a:a.c b.c a1.c b1.c
	gcc a.c -o a
	gcc b.c -o b
	gcc a1.c -o a1
	gcc b1.c -o b1
.PHONY:rebuild clean
rebuild:
	make clean a
clean:
	rm a b a1 b1
