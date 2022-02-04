#include <QTest>
#include <QCoreApplication>

#include <oclero/QtTestUtils.hpp>

#include "QtConnectionUtilsTests.hpp"
#include "QtEnumUtilsTests.hpp"
#include "QtPointerUtilsTests.hpp"
#include "QtSettingsUtilsTests.hpp"

int main(int argc, char* argv[]) {
  QTEST_SET_MAIN_SOURCE_PATH;

  // Necessary to get a socket name and to have an event loop running.
  QCoreApplication::setApplicationName("QtUtilsTests");
  QCoreApplication::setApplicationVersion("1.0.0");
  QCoreApplication::setOrganizationName("oclero");
  QCoreApplication app(argc, argv);

  // Add your test classes here.
  auto const success = oclero::runTests<
    // clang-format off
    QtConnectionUtilsTests,
    QtEnumUtilsTest,
    QtPointerUtilsTest,
    QtSettingsUtilsTests
    // clang-format on
    >();

  return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
