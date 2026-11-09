cmake_minimum_required(VERSION 3.20)
project(signumera VERSION 0.1.0 LANGUAGES C)
option(SIGNUMERA_BUILD_TESTS "Build migrated tests" ON)
file(GLOB SIGNUMERA_SOURCES CONFIGURE_DEPENDS src/*.c)
add_library(signumera STATIC ${SIGNUMERA_SOURCES})
target_include_directories(signumera PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/signumera/signal)
target_compile_features(signumera PUBLIC c_std_99)
if(SIGNUMERA_BUILD_TESTS)
 enable_testing()
 set(SIGNUMERA_TESTS
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_abs_sum.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_cycle_count.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_gain.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_composition.c)
 foreach(test_source IN LISTS SIGNUMERA_TESTS)
  get_filename_component(test_name "${test_source}" NAME_WE)
  add_executable(signumera_${test_name} ${test_source})
  target_include_directories(signumera_${test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/signumera/signal)
  target_link_libraries(signumera_${test_name} PRIVATE signumera)
  add_test(NAME "${test_name}" COMMAND "signumera_${test_name}")
 endforeach()
endif()
