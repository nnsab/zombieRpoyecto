
debug.out: main.o Bullet.o Entity.o Game.o Map.o Menu.o Play_mode.o Player.o Sprite_base.o Weapon.o Zombie.o
	g++ main.o Bullet.o Entity.o Game.o Map.o Menu.o Play_mode.o Player.o Sprite_base.o Weapon.o Zombie.o -o debug.out -lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp
	g++ -c -Wall -g3 -O0 src/main.cpp -I include/

Bullet.o: src/Bullet.cpp src/include/Bullet.h
	g++ -c -Wall -g3 -O0 src/Bullet.cpp -I include/

Entity.o: src/Entity.cpp src/include/Entity.h
	g++ -c -Wall -g3 -O0 src/Entity.cpp -I include/

Game.o: src/Game.cpp src/include/Game.h
	g++ -c -Wall -g3 -O0 src/Game.cpp -I include/

Map.o: src/Map.cpp src/include/Map.h
	g++ -c -Wall -g3 -O0 src/Map.cpp -I include/

Menu.o: src/Menu.cpp src/include/Menu.h
	g++ -c -Wall -g3 -O0 src/Menu.cpp -I include/

Play_mode.o: src/Play_mode.cpp src/include/Play_mode.h
	g++ -c -Wall -g3 -O0 src/Play_mode.cpp -I include/

Player.o: src/Player.cpp src/include/Player.h
	g++ -c -Wall -g3 -O0 src/Player.cpp -I include/

Sprite_base.o: src/Sprite_base.cpp src/include/Sprite_base.h
	g++ -c -Wall -g3 -O0 src/Sprite_base.cpp -I include/

Weapon.o: src/Weapon.cpp src/include/Weapon.h
	g++ -c -Wall -g3 -O0 src/Weapon.cpp -I include/

Zombie.o: src/Zombie.cpp src/include/Zombie.h
	g++ -c -Wall -g3 -O0 src/Zombie.cpp -I include/

clean:
	rm *.o *.out
