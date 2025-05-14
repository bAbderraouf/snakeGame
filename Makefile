All : compile link

test : compile link run

compile : 
	g++ -c *.cpp

link :
	g++ -std=c++11 *.o -static -o snake -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean :
	rm *.o
	rm *.exe
	clear

run :
	snake.exe