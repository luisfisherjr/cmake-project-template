[![Build Status](https://travis-ci.org/luisfisherjr/cmake-project-template.svg?branch=master)](https://travis-ci.org/luisfisherjr/cmake-project-template) [![codecov](https://codecov.io/gh/luisfisherjr/cmake-project-template/branch/master/graph/badge.svg)](https://codecov.io/gh/luisfisherjr/cmake-project-template)





# CMake Project Template

## Purpose

This is a C/C++ cmake project template using Google Test, Travis CI and Codecov
* [Google Test](https://github.com/google/googletest#google-test) C++ test framework
* [Travis CI](https://travis-ci.org/) hosted continuous integration software
* [Codecov](https://coveralls.io/)  code coverage web service

### To Build and Run GTests (Local)

* fork this project
* $ bash run_bash

### To Get Coverage (w/ Travis & Codecov)

* clone this project and add it as your own repository
* Sign up for [Travis CI](https://travis-ci.org/) add fork of this project
* Sign up for [Codecov](https://coveralls.io/)
* Change the links in the tags to match your name and your project:
  - luisfisherjr/cmake-project-template -> new-owner-name/new-project-name

### Possible Changes

* change .travis.yml to specify cotainer/compiler/flags
* change the root CMakeLists.txt to specify compiler/flags

## Reference projects:
* [CodeCoverage.cmake](https://github.com/bilke/cmake-modules/blob/master/CodeCoverage.cmake) Codecov Cmake helper module
* [Codecov C++ example](https://github.com/codecov/example-cpp11-cmake) Codecov/Travis integration
* [Modern CMake](https://cliutils.gitlab.io/modern-cmake/) CMake guide with code snippets
