TOOLS
=========

Using libraries
The GUI isn’t very complicated, so a basic graphics library should be enough.

For solving differential equations, you should use a library instead of writing your own solver. This might save you from a lot of headache.

- https://mycourses.aalto.fi/course/view.php?id=28448&section=3
	Course: ELEC-A7151 - Object oriented programming with C++, 08.09.2020-11.12.2020, Section: Software project

- git repository 
	https://courses-git.comnet.aalto.fi/CPP-F2020/circuit-sim-2020-1

- https://tim.aalto.fi/view/elec-a7151/fall2020/projects/circuit-simulator

- https://tim.aalto.fi/view/elec-a7151/fall2020/6-project-tools

- https://git-scm.com/book/en/v2   Git - Book

- circuit symbols 
	https://electronicsclub.info/circuitsymbols.htm
- https://learning.oreilly.com/library/view/programming-interactivity/9780596800598/apa.html


- CMake

	CMake is a more advanced build tool that generates the makefile. CMake also works in Windows and OS X environments (it can be integrated with Visual Studio or Xcode). With CMake it is easy to make so called “out-of-place builds” which means that the generated object and executable files are not in the same directory as the source code. This helps keeping the source directory tidy.

	CMake configuration is defined in file titled “CMakeLists.txt”. I defines the high-level configuration about source file locations, target files, and library dependencies. Additionally CMake scans the system build environment, and generates the actual Makefiles based on this information that will build the running program. Benefit of CMake is that it makes it easier to build the source code in different environments.

- SFML

	SFML is a fairly easy to use graphics/sound/etc library especially useful for developing simple graphical games.

	The Aalto Linux machines have SFML 2.5.1 readily installed, so it is advised that you test your project with that version, even though there are also newer versions.

	The SFML web page
	Some helpful tutorials
	Useful book: “SFML game development : learn how to use SFML 2.0 to develop your own feature-packed game” from Aalto univeristy library
	Instructions on how to set SFML on Eclipse (Windows/Linux). In addition, on Windows the SFML .dll files need to be placed in a location that is accessible for the project. One working solution is to copy the .dll files to the same location with your project executable. (Thanks to Kristian Salo for the hint)


Links
-------
- SFML 
	a simple multimedia library for graphics and media playback.
- IMGUI 
	a simple library for making GUIs easily. https://github.com/ocornut/imgui
- IMGUI-SFML 
	library which allows you to use ImGui with SFML.  https://github.com/eliasdaler/imgui-sfml
- Qt 
	an application framework with extended capabilities, like UI features.
- Odeint 
	ODE solver library  http://headmyshoulder.github.io/odeint-v2/
