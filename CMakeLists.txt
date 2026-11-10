cmake_minimum_required(VERSION 3.20)
project(signumera VERSION 0.1.0 LANGUAGES C)
option(SIGNUMERA_BUILD_TESTS "Build tests" ON)
option(SIGNUMERA_STRICT_WARNINGS "Enable strict compiler warnings" ON)
file(GLOB SIGNUMERA_SOURCES CONFIGURE_DEPENDS src/*.c)
add_library(signumera STATIC ${SIGNUMERA_SOURCES})
target_include_directories(signumera PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/signumera/signal>
  $<INSTALL_INTERFACE:include>)
target_compile_features(signumera PUBLIC c_std_99)
if(SIGNUMERA_STRICT_WARNINGS)
  if(MSVC)
    target_compile_options(signumera PRIVATE /W4 /WX)
  else()
    target_compile_options(signumera PRIVATE -Wall -Wextra -Wpedantic -Werror)
  endif()
endif()
if(SIGNUMERA_BUILD_TESTS)
  enable_testing()
  set(SIGNUMERA_TESTS
    test_abs_sum test_cycle_count test_gain test_composition
    test_antisymmetry test_fir_symmetry test_fir_energy
    test_frequency_bin test_iir_biquad_dc test_iir_normalize test_iir_stability
    test_mod_interval test_mod_window_overlap test_pcm_peak test_pcm_rms
    test_pulse_period test_q_div test_ratio)
  foreach(test_name IN LISTS SIGNUMERA_TESTS)
    add_executable(signumera_${test_name} tests/${test_name}.c)
    target_link_libraries(signumera_${test_name} PRIVATE signumera)
    if(SIGNUMERA_STRICT_WARNINGS)
      if(MSVC)
        target_compile_options(signumera_${test_name} PRIVATE /W4 /WX)
      else()
        target_compile_options(signumera_${test_name} PRIVATE -Wall -Wextra -Wpedantic -Werror)
      endif()
    endif()
    add_test(NAME ${test_name} COMMAND signumera_${test_name})
  endforeach()
endif()
