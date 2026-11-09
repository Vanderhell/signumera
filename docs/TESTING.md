# Testing

| Test category | Count | Platform | Result | Evidence |
|---|---:|---|---|---|
| Self-contained CTest tests | 4 | MSVC host | PASS | CMake test gate. |
| Strict warning build | 4 | GCC 13.3 / Ubuntu 24.04 | PASS 4/4 | `-Wall -Wextra -Werror` |
| Preserved test sources | 30 | Repository | PRESERVED | Cross-product dependencies are excluded. |
| Hardware tests | 0 | ESP32-S3 | NOT TESTED | HW NOT VERIFIED. |

Reproduce with `cmake -S . -B build -DSIGNUMERA_BUILD_TESTS=ON`,
`cmake --build build --config Release`, and
`ctest --test-dir build --output-on-failure -C Release`.

Strict GCC reproduction:

```sh
cmake -S . -B build-linux -DSIGNUMERA_BUILD_TESTS=ON -DCMAKE_C_FLAGS="-Wall -Wextra -Werror"
cmake --build build-linux --parallel
ctest --test-dir build-linux --output-on-failure
```

Known gap: MCU footprint, stack use and signal-processing timing are not
measured.
