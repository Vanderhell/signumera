# Testing and validation

## Host test suite

CMake builds 18 independent test executables. Together they call all 20 public functions. Checks use explicit conditions and return codes, so validation stays active in Release builds with `NDEBUG`.

```sh
cmake -S . -B build -DSIGNUMERA_BUILD_TESTS=ON -DSIGNUMERA_STRICT_WARNINGS=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

Coverage includes integer extrema, invalid pointers and lengths, output preservation, wraparound, tie rounding and state transitions. Some tests include long deterministic loops. The suite is not exhaustive across every input tuple, and independent oracle coverage remains limited; see `AUDIT.md`.

## Toolchain status

Local GCC 16.1 Release, Clang 19.1.5 Release and MSVC 19.42 Debug/Release strict-warning builds each passed 18/18 CTest tests. MSVC AddressSanitizer Release passed 18/18. UBSan is NOT RUN locally: GCC's MinGW sanitizer runtimes are absent, and the Windows Clang invocation could not link the MSVC runtime. Hosted GitHub Actions for these unpushed changes remains NOT RUN.

## Hardware

A firmware exercising all 20 APIs was compiled with Arduino ESP32 core 3.3.10, uploaded to the connected ESP32-S3 on COM19, and emitted `SIGNUMERA_HW_PASS`. This is a functional smoke test only. It does not measure MCU timing, stack, RAM or flash of a production integration; see `PERFORMANCE.md`.
