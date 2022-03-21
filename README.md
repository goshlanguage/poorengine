# poor engine

In terms of sophistication, this project aims to be a rudimentary game engine.

This project leverages the `SDL2` project, _Simple DirectMedia Layer_. See:

|Link|Description|
|-|-|
|[wiki.libsdl.org/](https://wiki.libsdl.org/)|SDL2 General Wiki|
|[APIByCategory](https://wiki.libsdl.org/APIByCategory)|API references for SDL2|
|[SDL_PollEvent](https://wiki.libsdl.org/SDL_PollEvent)|Poll event reference for input|
|[SDL_Init](https://wiki.libsdl.org/SDL_Init)|SDL Init and subsystems|

## Dependencies

This project uses `SDL2`, and `SDL2_image`.

### SDL2

To setup `SDL2`, visit the [download page](https://libsdl.org/download-2.0.php) and install the `Development Libraries`. OS X users can refer to [this guide](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/index.php) if you use Xcode.

I prefer _unix style_ build tools, as [described here](https://wiki.libsdl.org/FAQMacOSX).

This process may look something like this:

```sh
# Download your source to the ~/Downloads folder 
$ tar zxvf ~/Downloads/SDL2-2.0.20.tar.gz -C /Users/ryan/src/c/
$ cd /Users/ryan/src/c/SDL-2.0.20
$ ./configure && make && make install
$ cd -
```

### SDL2_image

SDL2_image can be found [here](https://www.libsdl.org/projects/SDL_image/)

```sh
# Download your source to the Downloads folder
$ tar zxvf ~/Downloads/SDL2_image-2.0.5.tar.gz -C /Users/ryan/src/c/
$ cd /Users/ryan/src/c/SDL2_image-2.0.5
$ ./configure && make && make install
$ cd -
```
