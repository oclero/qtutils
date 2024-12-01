#include "QtConnectionUtilsTests.hpp"

#include <QTest>

#include <oclero/QtConnectionUtils.hpp>
#include <oclero/QtScopedConnection.hpp>

void QtConnectionUtilsTests::test_singleShotConnect() {
  auto count = 0;
  oclero::singleShotConnect(this, &QtConnectionUtilsTests::signalTriggered, [&count]() {
    count++;
  });
  emit signalTriggered();
  emit signalTriggered();
  QVERIFY(count == 1);
}

void QtConnectionUtilsTests::test_scopedConnection() {
  auto count = 0;
  {
    oclero::QtScopedConnection scopedConnection =
      QObject::connect(this, &QtConnectionUtilsTests::signalTriggered, [&count]() {
        count++;
      });
    emit signalTriggered();
  }
  emit signalTriggered();
  QVERIFY(count == 1);
}
