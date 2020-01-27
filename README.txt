The code make_koch_snowflake_quad generates instances of Koch's
rectilinear snowflake curve. All coordinates are integers if the run-time
option "--perturb" is not used.

Compilation: 
Any standard C compiler will do. E.g.: 
    gcc -O2 -Wall -o make_koch_snowflake_quad make_koch_snowflake_quad.c -lm

Usage:
    make_koch_snowflake_quad --number N --output XYZ [--perturb]
       where N is a positive integer.

Generating polygonal data: 

The runtime-option "--number N" specifies the order of the snowflake curve.
For N=1 we simply get a square. The curve is written to the file named XYZ,
as specified in "--output XYZ". If the option "--perturb" is given then the
coordinates of the curve are slightly perturbed.

Please direct bug reports or suggestions to Martin Held at held@cs.sbg.ac.at.
