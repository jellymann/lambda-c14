Lambda Calculus
===============

This is an attempt to implement the FizzBuzz application in lambda calculus using C++14.

It is basically an attempt at a C++14 version of [this](http://codon.com/programming-with-nothing).

To run:
-------

    $ make run

That's it.

What works
----------

  * Church numeral constants 0-3, 5, 15 and 100
  * True and False constants
  * Conditional (IF function)
  * ISZERO predicate
  * SUCC, PLUS and MULT functions
  * Helper functions to convert from Church types to C++ types

What doesn't work
-----------------

  * PRED function outputs garbage
  * Numerals defined in terms of PLUS and MULT sometimes fail (segfault)

To-Do
-----

  * PAIR, LIST and associated functions
  * String encoding
  * The FizzBuzz program