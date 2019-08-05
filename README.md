# MJIT Output and Disassembly

By running Ruby 2.6+ code with extra options, you can not only JIT it, you can see the results of that JIT.

This repository shows output from doing so.

Each set of code is based on simple Ruby code of roughly the following form:

``` ruby
def multiply(a, b)
  a * b
end

1_000_000.times do
  multiply(7.0, 10.0)
end
```

The three files (multiply_2.rb, multiply_3.rb, multiply_4.rb) are named according to the number of Floats they multiply together before returning.

Each set of files has the initial Ruby file (multiply_*.rb) and one or more MJIT-ted versions (multiply_*_version_*.c). MJIT produces only one C file for multiplying two numbers, but produces three versions for multiplying three or four numbers.

This results in the following files:

* multiply_2.rb
* multiply_2_version_0.c
* multiply_3.rb
* multiply_3_version_0.c
* multiply_3_version_1.c
* multiply_3_version_2.c
* multiply_4.rb
* multiply_4_version_0.c
* multiply_4_version_1.c
* multiply_4_version_2.c

## Compilation and Disassembly

All of this is done in Ruby 2.6 on a Mac with CLang. Some output will be different with Linux and/or GCC.

For the multiply_2 files, there is an object file and a disassembly of that object file:

* multiply_2_obj_mac.o
* multiply_2_obj_mac_disassembly.txt
