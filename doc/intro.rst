INTRO
=========

(base) PS C:\Users\kim\AaltoC\doc-example\source> sphinx-build . build

- Learning objectives of the project

	- Get more familiarity with C++ by designing a whole program from scratch that utilizes different C++ features
	- Learn to design object-oriented program that consists of multiple modules, developed by multiple developers
	- Group work, where the strengths of each group member are taken properly into account, such that each group member will have an important role in the outcome
	- Get to know about different libraries that can be used in a C++ program
	- Get familiar with various important software development tools, such as Git and CMake
	- Reviewing and giving feedback on work made by others

- project description
	
	https://tim.aalto.fi/view/elec-a7151/fall2020/projects/circuit-simulator#basic-features
	
	With this project you will learn UI design, solving complicated problems, and library usage - with circuit analysis as an extra. NOTE: While it is possible to learn everything is needed during the project, it would require a lot of work without any basis in circuit analysis. Therefore, it is recommended for at least one of the group to have previous knowledge of circuit analysis.

	A basic circuit simulator gives us RMS (root mean square) values for voltage and current. For time or frequency domain values, solving of differential equations is needed, either through complex number circuit analysis or with ODE solvers. Note that complex numbers don’t get you very far with more complex circuits.

	MNA (Modified Nodal Analysis) is recommended for implementing the solver. It uses linear matrix algebra and involves laplace transforms for the reactive components and fourier transforms for non-sinusoidal signals.
	
	
	https://www.circuitlab.com/editor/#?id=7pq5wm&from=homepage
	https://www.falstad.com/circuit/
	https://docs.google.com/document/d/1shQ2s8UD8izKcHNQ82qJS6qiMWnS_RHnsDUpiUFOro8/edit

	https://coderefinery.github.io/documentation/