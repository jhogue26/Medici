all: main

main: main.cpp card.cpp deck.cpp player.cpp exception.cpp game.cpp input.cpp
	g++ -pedantic-errors -g main.cpp card.cpp deck.cpp player.cpp exception.cpp game.cpp input.cpp -o main

clean:
	rm -f main