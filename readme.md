### For OSX
-----

```
brew install sdl2 sdl2_image sdl2_mixer
```

You also need to download the .dmg versions of each library from the SDL website. A google search for each of them will give you the right pointers. 

You then want to add each `.framework` to your `libraries/frameworks` directory. Create if it doesn't exist.

```
cmake ./
```

```
make
```


