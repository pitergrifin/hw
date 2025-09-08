add_executable(tests2 hw2_tests.cpp hw2.cpp)
target_link_libraries(tests2 PRIVATE Catch2::Catch2WithMain common)
target_include_directories(tests2 PUBLIC ${CMAKE_SOURCE_DIR}/common)
