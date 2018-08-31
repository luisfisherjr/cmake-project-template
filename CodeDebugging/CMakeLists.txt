project(CodeDebugging CXX)

# source directory
set(SRC_DIR ${PROJECT_SOURCE_DIR}/source)

# add additional source files as required
set(SRC_FILES
        ${SRC_DIR}/${PROJECT_NAME}.cpp
        )

# create executuable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# add additional linked libraries as required
set(LINKED_LIBS
        Graph
        )

# adds linked libs
target_link_libraries(${PROJECT_NAME} ${LINKED_LIBS})

# add private headers for testing if needed
foreach(LIB ${LINKED_LIBS})

    target_include_directories(${PROJECT_NAME} PRIVATE
            ${${LIB}_SOURCE_DIR}/include/private
            )
endforeach()