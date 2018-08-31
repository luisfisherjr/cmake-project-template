project(AddAltTest CXX)

add_gtest(${PROJECT_NAME} ${PROJECT_NAME})

# add additional linked libraries as required
set(LINKED_LIBS
        AddAlt
        )

# adds linked libs
target_link_libraries(${PROJECT_NAME} ${LINKED_LIBS})

# add private headers for testing if needed
foreach(LIB ${LINKED_LIBS})

    target_include_directories(${PROJECT_NAME} PRIVATE
            ${${LIB}_SOURCE_DIR}/include/private
            )
endforeach()