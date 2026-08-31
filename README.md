This repo contains useful tools to save time while doing math. Here, I will explain how to use every
single one of them.

1. Installation
These tools require the g++ compiler. Please make sure you have it installed. To create the executables,
simply run "./compile.sh" on your terminal.

2. Running
To run a tool, type ./[tool name] in your terminal. Please notice that you will have to be in the same
directory/folder with the tools for it to work.

3. How to use each tool
    3.1. cmmdc
    Cmmmdc calculates the greatest common divider of n numbers. The program takes input the number n, then n numbers. It will output the greatest common divider of those numbers.

    3.2. divizori
    Divizori takes input a natural number and outputs its dividers, and how many there are.

    3.3 extragerea_radicalilor
    extragerea_radicalilor takes input a number and simplifies its square root.
     Example: sqrt(12) = 2 * sqrt(3)

    3.4 heron
    Heron takes input 3 numbers, those being a triangle's sides, and outputs its area, in the same form
    as extragerea_radicalilor does

    3.5 simplif_fractii
    simplif_fractii takes input 2 numbers, those being the elements of a fraction, and simplifies them.

    3.6 prime_factors
    prime_factors takes input a natural number and outputs its prime factors along with how many times each one appears.
     Example: 360 = 2^3 * 3^2 * 5^1

     3.7 teorema_cosinusului
    teorema_cosinusului takes input two sides of a triangle (b and c) and the angle between them (in degrees),
    and outputs the third side (a) using the Law of Cosines: a^2 = b^2 + c^2 - 2bc*cos(angle).
    Inputs can be plain numbers, bare radicals, or coefficient times a radical.
     Example: b = 4*sqrt(3), c = 5, angle = 60