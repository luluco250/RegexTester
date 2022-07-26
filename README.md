RegexTester
===========

A simple program to test regex expressions.

While you can build it with any compiler you want, it comes with a small meson build project that you can use.

To use, simply call: 
```
regex "[expression]" "[string]"
```

Quotes are recommended because certain regex characters may be confused with terminal commands.

You can call:
```
regex cheatsheet
```

To get a quick regex reference taken from [RegexOne](https://regexone.com/).

Compiling
=========
1. Install [Meson](https://mesonbuild.com/Getting-meson.html) using Python's PIP or your OS's package manager.
2. Open the project folder in a terminal.
3. Do:
```sh
meson build
cd build
meson compile
```
4. Use the resulting `regex` binary, you can copy it to `/usr/local/bin` or any other folder in your `PATH` to install it.
