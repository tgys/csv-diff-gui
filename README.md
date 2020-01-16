# CSV-diff-GUI

A simple diff tool for CSV files with a GUI written in Qt/C++

### Prerequisites

You will need a C++ compiler, e.g clang or MinGW.
If you're building a standalone app, you will need to build Qt5 from source, and the build dependencies are ActivePerl, GPerf, Bison, Flex. 
It's easier to make the standalone app with mxe, which you can get from the github repo at 
https://github.com/mxe/mxe

### Installing

TODO

*get the source code from git:
```
git clone https://github.com/mxe/mxe.git
```
*install the build dependencies, which you can find in the list here:
https://mxe.cc/#requirements

*build Qt5, targeting windows

```
cd mxe && make qt5
```

*export the path

```
export PATH=<mxe root>/usr/bin:$PATH
```

*go the the root directory of the app and run the Qt Makefile generator on the project

```
<mxe root>/usr/bin/i686-w64-mingw32.static-qmake-qt5
```
*build the project

```
make
```
*run the binary from the release directory

## Deployment

use mxe to cross compile and deploy static binaries

## Built With

* [qmake](https://doc.qt.io/qt-5/qmake-manual.html) - The MakeFile generator
* [mxe](https://github.com/mxe/mxe) - For dependency management and cross platform compilation

## Contributing

TODO

## Versioning

TODO

## License

TODO
