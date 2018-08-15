project(AddAltTest CXX)

add_gtest(AddAltTest AddAltTest)
target_link_libraries(AddAltTest AddAlt)
#target_include_directories(AddAltTest PRIVATE ${AddAlt_SOURCE_DIR})