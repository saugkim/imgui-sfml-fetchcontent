Features
=========


Basics
-------

These features are the minimum requirements for this project. They are worth no points and must be implemented to get a passing grade from the project.

- Basic components: resistor, capacitor, inductor and a constant voltage source
	
- Graphical user interface for building the circuit and showing results (must be able to add, connect, move and remove components and wires)
	
- Saving and loading circuits from files
	
- RMS voltage and current calculations
	
- Basic ready-made circuits for showing the program’s functionalities
	

Additional
-----------

Implement some additional features if you’re aiming for a good grade. You can suggest your own additional features if they stay relevant to the project. If so, remember to ask the teaching assistant overseeing your project if the feature would be worth some additional points.

General
""""""""""

These features below are essential to a basic circuit simulator. Don’t try to implement too many, as every feature listed here is generally worth two points.

- Sinusoidal AC voltage source and sinusoidal AC and constant DC current sources
- Expand both sources for triangle and square waves. (requires current source)
- Dependent sources: voltage controller voltage, current controlled voltage, voltage controlled current and current controlled current sources.
- Time domain graphs for voltage and current
- Frequency domain graphs for voltage and current
- Ideal BJT and diode
- Ideal operational amplifier
- Ability to import schematics from a third party circuit design software


Advanced
""""""""""

These features might offer a challenge. The features are generally worth two or more points.

- Y and Z parameters for two-port networks
- Allow abstraction of circuits into blocks and precalculate its properties to make the simulation more efficient
- Basic microcontroller emulation (run custom code that can read and write to the ports of an IC in the simulation)






.. code-block:: c

   #include <stdio.h>
   int main()
   {
       printf("Hello, World!");
       return 0;
   }

.. math::
   :label: myequation

   a^2 + b^2 = c^2

.. math::
   :label: myarray

   \begin{eqnarray}
     x^2 & : x < 0 \\
     x^3 & : x \ge 0 \\
   \end{eqnarray}
   
The following is a code block::
  def hello():
      print("Hello world")
	  
	  
Level 4
"""""""