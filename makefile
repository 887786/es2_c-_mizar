liste:
	g++ -pedantic -Wall -Wextra --std=c++11 ricorsivo_liste.c++ -o Play

debug:
	valgrind --leak-check=full ./Play