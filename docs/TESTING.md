# Testing and validation

## Host test suite

CMake builds 19 independent test executables. Together they call all 20 public functions. Checks use explicit conditions and return codes, so validation stays active in Release builds with `NDEBUG`.

```sh
cmake -S . -B build -DSIGNUMERA_BUILD_TESTS=ON -DSIGNUMERA_STRICT_WARNINGS=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

Coverage includes integer extrema, invalid pointers and lengths, output preservation, wraparound, tie rounding and state transitions. `test_differential` runs 100,000 fixed-seed iterations against independent formulas and interval/root models for all APIs. The suite is not exhaustive across every input tuple; see `AUDIT.md` for oracle limitations.

## Toolchain status

Local GCC 16.1 Release, Clang 19.1.5 Release and MSVC 19.42 Debug/Release strict-warning builds each passed 19/19 CTest tests. MSVC AddressSanitizer Release passed 19/19. UBSan is NOT RUN locally: GCC's MinGW sanitizer runtimes are absent, and the Windows Clang invocation could not link the MSVC runtime. GitHub Actions run `42869757367` (commit `35def43`) passed all eight GCC, Clang, sanitizer, MSVC Debug and MSVC Release jobs, each with 19/19 tests. A preceding run caught and led to fixing two missing `<stddef.h>` includes in test files.

## Hardware

A functional firmware exercising all 20 APIs was uploaded to the ESP32-S3 on COM19 and emitted `SIGNUMERA_HW_PASS`. A separate `-Os` benchmark on Arduino core 3.3.10 measured five-repeat cycle medians at 240 MHz and captured linker-map, global-RAM and task-stack-watermark data. The results apply to that benchmark firmware; see `PERFORMANCE.md` for the values and limits.
