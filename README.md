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

TODO

## Author

**Olivier Cléro** | [email](mailto:oclero@pm.me) | [website](https://www.olivierclero.com) | [github](https://www.github.com/oclero) | [gitlab](https://www.gitlab.com/oclero)

## License

**QtUtils** is available under the MIT license. See the [LICENSE](LICENSE) file for more info.
