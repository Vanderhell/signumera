# Testing

| Test category | Count | Platform | Result | Evidence |
|---|---:|---|---|---|
| Self-contained CTest tests | 4 | MSVC host | PASS | CMake test gate. |
| Preserved test sources | 30 | Repository | PRESERVED | Cross-product dependencies are excluded. |
| Hardware tests | 0 | ESP32-S3 | NOT TESTED | HW NOT VERIFIED. |

Reproduce with `cmake -S . -B build -DSIGNUMERA_BUILD_TESTS=ON`,
`cmake --build build --config Release`, and
`ctest --test-dir build --output-on-failure -C Release`.

Known gap: MCU footprint, stack use and signal-processing timing are not
measured.
