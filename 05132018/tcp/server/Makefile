OBJS:=*.cpp
ELF:=server
$(ELF):$(OBJS)
	g++ $(OBJS) -o $(ELF) -std=c++11
.PHONY:rebuild clean
rebuild:
	gcc $(ELF) -o $(OBJS) -std=c++11
clean:
	rm -rf $(ELF)
