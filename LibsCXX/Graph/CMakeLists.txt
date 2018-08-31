project(Graph CXX)

# source directory
set(SRC_DIR ${PROJECT_SOURCE_DIR}/source)

# add additional source files as required
set(SRC_FILES
        ${SRC_DIR}/Node
        ${SRC_DIR}/Edge
        ${SRC_DIR}/AdjacencyList
        ${SRC_DIR}/AdjacencyMatrix
        ${SRC_DIR}/ObjectOriented
        )

# add additional linked libraries as required
set(LINKED_LIBS
        )

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})

# adds this libs include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include PRIVATE ${PROJECT_SOURCE_DIR}/include/private)

# adds linked libs
target_link_libraries(${PROJECT_NAME} ${LINKED_LIBS})