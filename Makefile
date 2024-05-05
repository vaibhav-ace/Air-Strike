#Makefile

#Type make game to start the game
game:
	g++ -Wall *.cpp
	clear
	./a.out


game2:
	g++ -Wall *.cpp -o game.exe
	./game.exe