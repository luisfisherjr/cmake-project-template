project(SubtractAltTest CXX)

add_gtest(SubtractAltTest SubtractAltTest)
target_link_libraries(SubtractAltTest SubtractAlt)
#target_include_directories(SubtractAltTest PRIVATE ${SubtractAlt_SOURCE_DIR})