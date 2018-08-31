project(DoubleLinkedList C)

# source directory
set(SRC_DIR ${PROJECT_SOURCE_DIR}/source)

# add additional source files as required
set(SRC_FILES
        ${SRC_DIR}/${PROJECT_NAME}
        ${SRC_DIR}/${PROJECT_NAME}Helper
        )

# add additional linked libraries as required
set(LINKED_LIBS
        )

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})

# adds this libs include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include PRIVATE ${PROJECT_SOURCE_DIR}/include/private)

# adds linked libs
target_link_libraries(${PROJECT_NAME} ${LINKED_LIBS})