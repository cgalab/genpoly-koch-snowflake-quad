The code `make_koch_snowflake_quad` generates instances of Koch's
rectilinear snowflake curve. All coordinates are integers if the run-time
option "--perturb" is not used.

# Compilation

Any standard C compiler will do. E.g.:

    gcc -O2 -Wall -o make_koch_snowflake_quad make_koch_snowflake_quad.c -lm

# Usage

    make_koch_snowflake_quad --number N --output <OUTPUTFILE> [--perturb]

where N is a positive integer and OUTPUTFILE is the name of the output file.

# Generating polygonal data

The runtime-option "--number N" specifies the order of the snowflake curve.
For N=1 we simply get a square. The curve is written to the file named OUTPUTFILE,
as specified in "--output OUTPUTFILE". If the option "--perturb" is given then the
coordinates of the curve are slightly perturbed.

Please direct bug reports or suggestions to Martin Held at held@cs.sbg.ac.at.

# License

This is free software.  You may redistribute it and/or modify
it under the terms of the GNU General Public License (v3).
