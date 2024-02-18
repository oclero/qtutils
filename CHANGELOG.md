# Changelog

## v1.2.1

- Fix deployment on macOS.

## v1.2.0

- Rename `lib` folder into `src`, and `src` subfolder into `source`.
- Add CI jobs to build and test on Windows, Linux and MacOS.
- Add CMake presets.

## v1.1.0

- Add utility function to clear a directory content.

## v1.0.6

- Add convenience event filter for visibility changes.

## v1.0.5

- Ensure the lib works on Linux.

## v1.0.4

- Add event filter utilities.

## v1.0.3

- Use const for read-only QSettings

## v1.0.2

- Fix missing implementation.

## v1.0.1

- Pass `QSettings` as parameter in methods to allow custom settings path.

## v1.0.0

- `singleShotConnect`
- Utilities for enums declared with `Q_ENUM`
- `QtDeleteLaterScopedPointer`
- RAII QMetaObject::Connection
- Utilites to write and read **typed** settings
