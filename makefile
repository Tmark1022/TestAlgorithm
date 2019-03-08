RES = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, ./obj/%.o, $(RES))

all : main.exe

$(OBJ):./obj/%.o:%.cpp
	g++ -c $< -o $@ -Wall -std=c++11

main.exe:$(OBJ)
	g++ $^ -o $@ -Wall -std=c++11

clean:
	-rm -rf main.exe $(OBJ)

.PHONY:all clean
