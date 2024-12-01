cmake_minimum_required(VERSION 3.21.0)
enable_testing()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set project information.
project("QtUtils"
  LANGUAGES CXX
  VERSION 1.3.0.0
  DESCRIPTION "Set of tools for Qt6"
)
set(PROJECT_NAMESPACE "oclero")

# Global flags.
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
if(NOT CMAKE_OSX_DEPLOYMENT_TARGET)
  set(CMAKE_OSX_DEPLOYMENT_TARGET "13.6")
endif()

# Find Qt.
find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

# The library.
add_subdirectory(src)

if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
  # Tests.
  add_subdirectory(tests)
endif()
