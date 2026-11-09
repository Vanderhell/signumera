# signumera

Signumera is a standalone C99 signal-processing library for deterministic embedded filtering, measurement, windowing and pulse analysis.

## Scope

This first extraction contains 55 family headers, 20 implementation units and 30 migrated test sources. It is portable C99, uses no mandatory heap or operating-system service, and keeps caller-owned state explicit where applicable.

## Build and test

```sh
cmake -S . -B build -DSIGNUMERA_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```

## Validation status

Host validation is run during extraction. ESP32-S3 validation and isolated footprint measurements are pending unless explicitly recorded; no hardware result is claimed.

## Name and origin

Signumera combines signum (signal) with a resonant product ending, indicating deterministic signal measurement and conditioning.
It originates from PrimitiveCore's signal/filters_and_measurements family.

## License

Apache License 2.0, copyright Vanderhell. See LICENSE and NOTICE.
