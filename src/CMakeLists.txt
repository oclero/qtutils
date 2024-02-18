set(LIB_TARGET_NAME ${PROJECT_NAME})

find_package(Qt5
  REQUIRED
    Core
)

set(HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/oclero/QtConnectionUtils.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/oclero/QtEnumUtils.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/oclero/QtEventFilterUtils.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/oclero/QtFileUtils.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/oclero/QtPointerUtils.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/oclero/QtScopedConnection.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/oclero/QtSettingsUtils.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/oclero/QtTestUtils.hpp
)

set(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/source/oclero/QtFileUtils.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/source/oclero/QtScopedConnection.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/source/oclero/QtSettingsUtils.cpp
)

# Configure target.
add_library(${LIB_TARGET_NAME} STATIC)
add_library(${PROJECT_NAMESPACE}::${LIB_TARGET_NAME} ALIAS ${LIB_TARGET_NAME})

target_sources(${LIB_TARGET_NAME}
  PRIVATE
    ${HEADERS}
    ${SOURCES}
)

target_include_directories(${LIB_TARGET_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/source>
)

target_link_libraries(${LIB_TARGET_NAME}
  PRIVATE
    Qt5::Core
)

set_target_properties(${LIB_TARGET_NAME}
  PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    OUTPUT_NAME ${LIB_TARGET_NAME}
    PROJECT_LABEL ${LIB_TARGET_NAME}
    FOLDER lib
    SOVERSION ${PROJECT_VERSION_MAJOR}
    VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    DEBUG_POSTFIX _debug
)

target_compile_options(${LIB_TARGET_NAME} PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Create source groups.
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
  ${HEADERS}
  ${SOURCES}
)

# Select correct startup project in Visual Studio.
if(WIN32)
  set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${LIB_TARGET_NAME})
endif()
