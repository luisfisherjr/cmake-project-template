cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(Tutorial VERSION 1.0 LANGUAGES C CXX)

set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")

include(proj_Macros)
include(proj_CodeCoverage)

enable_testing()
APPEND_COVERAGE_COMPILER_FLAGS()
set(COVERAGE_LCOV_EXCLUDES '${CMAKE_CURRENT_LIST_DIR}/Test/*' '${CMAKE_CURRENT_LIST_DIR}/ext/*')

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/Ext/googletest/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# holds git modules
add_subdirectory(Ext)
# holds C project library directories
add_subdirectory(LibsC)
# holds C++ project library directories
add_subdirectory(LibsCXX)
# used to test code before unit testing
add_subdirectory(CodeDebugging)
# holds tests
add_subdirectory(Test)






