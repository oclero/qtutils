set(LIB_TARGET_NAME ${PROJECT_NAME})

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

# Create target.
qt_add_library(${LIB_TARGET_NAME} STATIC
  ${HEADERS}
  ${SOURCES}
)

# Create a target alias.
add_library(${PROJECT_NAMESPACE}::${LIB_TARGET_NAME} ALIAS ${LIB_TARGET_NAME})

target_include_directories(${LIB_TARGET_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/source>
)

target_link_libraries(${LIB_TARGET_NAME}
  PRIVATE
    Qt::Core
)

set_target_properties(${LIB_TARGET_NAME}
  PROPERTIES
    OUTPUT_NAME ${LIB_TARGET_NAME}
    PROJECT_LABEL ${LIB_TARGET_NAME}
    FOLDER lib
    SOVERSION ${PROJECT_VERSION_MAJOR}
    VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    DEBUG_POSTFIX _debug
    CMAKE_AUTORCC ON
    CMAKE_AUTOMOC ON
    CMAKE_AUTOUIC ON
)

target_compile_options(${LIB_TARGET_NAME}
  PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/MP /WX /W4>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Werror>
)
  
# Create source groups.
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${HEADERS}
    ${SOURCES}
)

# Select correct startup project in Visual Studio.
if(WIN32)
  set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${LIB_TARGET_NAME})
endif()
