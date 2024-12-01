set(TESTS_TARGET_NAME ${PROJECT_NAME}Tests)

find_package(Qt6 REQUIRED COMPONENTS
  Core
  Widgets
  Test
)
set(TESTS_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/QtConnectionUtilsTests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/QtConnectionUtilsTests.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/QtEnumUtilsTests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/QtEnumUtilsTests.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/QtEventFilterUtilsTests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/QtEventFilterUtilsTests.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/QtPointerUtilsTests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/QtPointerUtilsTests.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/QtSettingsUtilsTests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/QtSettingsUtilsTests.hpp
)
qt_add_executable(${TESTS_TARGET_NAME}
  ${TESTS_SOURCES}
)

set_target_properties(${TESTS_TARGET_NAME}
  PROPERTIES
    INTERNAL_CONSOLE ON
    EXCLUDE_FROM_ALL ON
    FOLDER tests
    CMAKE_AUTORCC ON
    CMAKE_AUTOMOC ON
    CMAKE_AUTOUIC ON
)

target_include_directories(${TESTS_TARGET_NAME}
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(${TESTS_TARGET_NAME}
  PRIVATE
    ${PROJECT_NAMESPACE}::${PROJECT_NAME}
    Qt::Core
    Qt::Widgets
    Qt::Test
)
add_test(NAME ${TESTS_TARGET_NAME}
  COMMAND $<TARGET_FILE:${TESTS_TARGET_NAME}>
  WORKING_DIRECTORY $<TARGET_FILE_DIR:${TESTS_TARGET_NAME}>)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${TESTS_SOURCES})
