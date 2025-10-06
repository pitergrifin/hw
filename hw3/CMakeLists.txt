add_executable(tests3 tests.cpp hw.cpp)
target_link_libraries(tests3 PRIVATE Catch2::Catch2WithMain common)
target_include_directories(tests3 PUBLIC ${CMAKE_SOURCE_DIR}/common)
