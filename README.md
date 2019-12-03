# CSV-diff-GUI

A simple diff tool for CSV files with a GUI written in Qt/C++

### Prerequisites

You will need a C++ compiler, e.g clang or MinGW
If you building a standalone app, you will need to build Qt5 from source, and the packages required for this are ActivePerl, GPerf, Bison, Flex. 
It's easier to make the standalone app with mxe, which you can get from the github repo at 
https://github.com/mxe/mxe

### Installing

If you have the Qt SDK and the Qtcreator IDE installed, you can run the release version of the program from the IDE, 
which will automatically create the build and output directories, and use qmake and make to compile and run the project, or alternatively, you can use mxe to compile the app for a specific platform.
This app uses Qt5, and the steps used to compile the windows standalone app in the releases folder are:

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
this took around an hour on my 2.9Ghz machine

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
* [mxe](https://github.com/mxe/mxe) - For dependency management and cross platform compilation (a standalone app for windows is already compiled, and included in the repo)

## Contributing

TODO

## Versioning

TODO

## Authors

* **Tei** - *Initial work* - [isgy](https://github.com/isgy)

## License

TODO

## Acknowledgments

* Qt Docs at https://doc.qt.io/ and the Qt forum  
* StackOverflow
