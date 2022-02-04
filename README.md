<div align="center">
	<img height="50" src="logo.svg">
</div>

# QtUtils

[![License: MIT](https://img.shields.io/badge/license-MIT-green)](https://mit-license.org/)
[![CMake version](https://img.shields.io/badge/CMake-3.19+-064F8C?logo=cmake)](https://www.qt.io)
[![C++ version](https://img.shields.io/badge/C++-17-00599C?logo=++)](https://www.qt.io)
[![Qt version](https://img.shields.io/badge/Qt-5.15.2+-41CD52?logo=qt)](https://www.qt.io)

**QtUtils** is a set of basic utilities that I consider should be part of Qt API. It contains many helpers that improve the Qt experience, from dealing with `enum` to usage of pointers.

---

### Table of Contents

- [Requirements](#requirements)
- [Usage](#usage)
- [Content](#content)
- [Author](#author)
- [License](#license)

---

## Requirements

- Platform: Windows, MacOS, Linux.
- [CMake 3.19+](https://cmake.org/download/)
- [Qt 5.15+](https://www.qt.io/download-qt-installer)

## Usage

1. Add the library's repository as a Git submodule.

   ```bash
   git submodule add https://github.com/oclero/qtutils.git submodules/qtutils
   ```

2. Download submodules.

   ```bash
   git submodule update --init --recursive
   ```

3. Add the library to your CMake project.

   ```cmake
   add_subdirectory(submodules/qtutils)
   ```

4. Link with the library in CMake.

   ```cmake
   target_link_libraries(your_project oclero::QtUtils)
   ```

5. Include headers in your C++ file.

   ```c++
   #include <oclero/QtConnectionUtils.hpp>
   ```

## Content

### QtConnectionUtils

#### Single-shot Connection

This connection handling will be called only once.

```cpp
oclero::singleShotConnect(this, &SomeClass::someSignalTriggered, []() {
  // Do stuff.
});
```

### QtScopedConnection

- This connection will be closed when it is destroyed, i.e. when the scope it belongs ends. It's a RAII `QMetaObject::Connection`.

  ```cpp
  oclero::QtScopedConnection scopedConnection = QObject::connect(this, &SomeClass::someSignalTriggered, []() {
    // Do stuff.
  });
  ```

- This `QMetaObject::Connection` container will close its content RAII-style.

  ```cpp
  oclero::QtScopedConnections scopedConnections;
  scopedConnections.add(QObject::connect(this, &SomeClass::someSignalTriggered, []() {
    // Do stuff.
  }));
  ```

### QtEnumUtils

- Converts `enum` to `QString` and vice-versa. Checks if the value is valid.

  ```cpp
  auto str = oclero::enumToString(SomeEnum::SomeValue);
  auto value = oclero::enumFromString<SomeEnum>("SomeValue");
  ```

- Converts `enum` to `int` and checks if the value is valid.

  ```cpp
  auto value = oclero::enumFromInt(3);
  ```

### QtPointerUtils

- A unique pointer that will call `QObject::deleteLater` instead of `delete` when its scope ends.

  ```cpp
  oclero::QtDeleteLaterScopedPointer<QObject> scopedPointer(rawPointer);
  ```

### QtSettingsUtils

Utilities to make saving and retrieving values with `QSettings` more convenient.

```cpp
auto value = oclero::loadSetting<int>("key", 3 /* default value */);
oclero::saveSetting("key", 3);
oclero::clearSetting("key");
```

## Author

**Olivier Cléro** | [email](mailto:oclero@pm.me) | [website](https://www.olivierclero.com) | [github](https://www.github.com/oclero) | [gitlab](https://www.gitlab.com/oclero)

## License

**QtUtils** is available under the MIT license. See the [LICENSE](LICENSE) file for more info.
