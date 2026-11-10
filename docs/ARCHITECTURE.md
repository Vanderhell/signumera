# Architecture

Signumera is a standalone collection of fixed-width C99 signal and timing primitives. Each public operation has a header in `include/signumera/signal/` and a separate implementation in `src/`. Applications may link the static library or compile only the required translation units.

Callers own buffers and mutable state. The library requires no heap allocation, threads, operating-system services or external runtime library beyond the C implementation. Public declarations and contracts live in the headers. CMake exports the include root for canonical `signumera/signal/...` paths and retains the direct signal-header include path.

CTest targets provide host validation. GitHub Actions defines GCC, Clang, sanitizer and MSVC configurations. Hardware validation is recorded separately and is not a performance claim.
