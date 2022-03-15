buid:
	mkdir -p bin
	clang -O3 -o bin/demo `sdl2-config --cflags --libs` -lSDL2_image main.c engine.c player.c

clean:
	rm -rf bin