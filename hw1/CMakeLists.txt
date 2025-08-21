add_executable(tests hw1_tests.cpp hw1.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
