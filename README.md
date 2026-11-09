# signumera

Signumera is a standalone C99 signal-processing library for deterministic embedded filtering, measurement, windowing and pulse analysis.

## Scope

The package contains 55 public headers and 20 implementation units. It is portable C99, uses no mandatory heap or operating-system service, and keeps caller-owned state explicit where applicable.

## Build and test

```sh
cmake -S . -B build -DSIGNUMERA_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```

## Validation status

Host validation is run during extraction. ESP32-S3 validation and isolated footprint measurements are pending unless explicitly recorded; no hardware result is claimed.

## Architecture and integration

Signal measurement, pulse analysis and filtering operations are separate C99
translation units. Link `signumera` with CMake or compile only the required
sources; state is explicit and caller-owned.

## API, configuration and dependencies

Public headers are under `include/signumera/signal`. `SIGNUMERA_BUILD_TESTS`
controls host tests. There are no mandatory OS, heap, thread or third-party
dependencies. Sampling and fixed-point contracts are documented per header.

## Resource, performance and limitations

The enabled host suite passes 4/4 tests. MCU flash, RAM, stack, cycle and
worst-case timing measurements are `PENDING`; HW NOT VERIFIED. The library is
not a security or authentication primitive.

## Version, license and origin

The product is independently versioned with semantic-versioning intent before
1.0. Apache License 2.0, copyright Vanderhell. It is self-contained and was
maintained as a self-contained library.

## Name and origin

Signumera combines signum (signal) with a resonant product ending, indicating deterministic signal measurement and conditioning.
Its technical scope is signal filtering, measurement and pulse analysis.

## License

Apache License 2.0, copyright Vanderhell. See LICENSE and NOTICE.
