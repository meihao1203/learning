OBJS:=*.cpp
ELF:=server
$(ELF):$(OBJS)
	#g++ $(OBJS) -o $(ELF) -std=c++11
	g++ $^ -o $@ -std=c++11
.PHONY:rebuild clean
rebuild:
	make clean $(ELF)
clean:
	rm -rf $(ELF)
