https://circuit-simulator-1-kim.readthedocs.io/en/latest/intro.html

System: Windows10


Program required
 CMake, Mingw64(or something else) 


Build using CMake (cmake-gui)

Create own build directory(any name, any place)

Select source directory and build directory
-> MinGW Makefiles
-> defaults
-> Configure
-> Generate 

Go to build directory

mingw32-make 

Go to src 

run exe


(WIP) CMake FetchContent example
==========================

This is WIP example of using CMake FetchContent in real world scenario. It
downloads ImGui, SFML and ImGui-SFML and then a simple application uses these
dependencies for building.

This example is interesting, because ImGui-SFML depends on both ImGui and SFML,
so you can also see how fetched dependencies can work with each other is well.

Building is simple, just do:

```sh
mkdir build
cd build
cmake <path-to-cloned-repo>
cmake --build .
./src/imgui-sfml-example
```

Options
-------

You can also set the following options when building:

* `USE_SYSTEM_DEPS` (`OFF` by default) - search for SFML installed on system instead of fetching it
## in my windows10 system, USE_SYSTEM_DEPS option ON not working 
## fatal error: SFML/System/Vector2.hpp: No such file or directory
##  #include <SFML/System/Vector2.hpp>
 
 
* `LINK_DEPS_STATIC` (`ON` by default) - link dependencies statically


Depencies
---

CMake >= 3.12

Also, if you're on Linux, you'll need to install dependencies for building SFML
specified
[here](https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php#installing-dependencies).
