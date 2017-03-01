# bengal
  Tiger compiler using bisonc++ for parser generation and llvm for code generation

## Compile it
Install `cmake` and get ready in the path `bisonc++` and `flexc++`. Also you have to get installed `boot-program_options`.
Then, as usual...

```
$ git clone https://github.com/frndgit/bengal.git
$ mkdir bengal-build
$ cd bengal-build
$ cmake ../bengal
$ make # Or cmake --build . --target all -- -j<number-of-threads>
```
To run the tests
```
$ # In the build directory (bengal-build)
$ ctest
```
