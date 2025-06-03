main: main.o hello_world.o 
	g++ -o main main.o hello_world.o

main.o: main.cpp hello_world/hello_world.h
	g++ -c main.cpp
# g++ -c main.cpp -I hello_world 注意：如果main.cpp中包含了hello_world.h，但没有指定路径，则需要指定头文件的路径

hello_world.o: hello_world/hello_world.cpp hello_world/hello_world.h
	g++ -c hello_world/hello_world.cpp

clean:
	rm -rf *.o main