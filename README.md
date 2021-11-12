[![Build Status](https://travis-ci.com/smk-robotics/CrazyRooks.svg?branch=develop)](https://travis-ci.com/github/smk-robotics/CrazyRooks)
# CrazyRooks

Repository with simple multithreading moving crazy chess rooks console 
application.

## Building

For building CrazyRooks console application you need to use CMake:

```
mkdir && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .
```

## Running

To launch CrazyRooks console application you need to run:

```
cd build
./CrazyRooks
```

After finish you can check rooks coordinates if **coordinates.csv** file that 
will be also located if build directory.

## Testing

Before you can build and run tests you will need to build third-party gtest library:

```
cd third-party
./build_third_party.sh
```

If you want to run tests, you need to build packages with `BUILD_TESTS=ON` flag 
and run `ctest`: 

```
mkdir && cd build
cmake -DCMAKE_BUILD_TYPE=DEBUG -DBUILD_TESTS=ON .. && cmake --build .
ctest --verbose
```

## License

GNU General Public License v3.0.

## Maintainers

* Kirill Smirnov <smk.robotics@gmail.com>