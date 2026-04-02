> [!WARNING]
> Outdated repo, go see the latest version over at Cannelle's repo
> 
> https://github.com/cannellegrdt/Pharmalgo-projects

### Turn any video into frames for the Croix

#### Requirements:
- FFMpeg
- uv
- ImageMagick
- WiringPi library

If you use Nix and don't want to download the lib:
```sh
cd Lib_Croix
nix develop
```

#### Steps:

- Download any video
- Convert it:
```sh
cd Lib_Croix
./converter.sh <video>
```
- Compile the program
```sh
g++ main.cpp CroixPharma.cpp -lwiringPi -o programme
```
- Run it with `./programme`
