all: clouds clouds_blue

clouds: clouds.c gfx.c gfx.h
	gcc clouds.c gfx.c -o clouds -lm -lX11

clouds_blue: clouds_blue.c gfx.c gfx.h
	gcc clouds_blue.c gfx.c -o clouds_blue -lm -lX11


clean:
	rm -f clouds clouds_blue
