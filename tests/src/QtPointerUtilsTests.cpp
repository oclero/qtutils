#include "QtPointerUtilsTests.hpp"

#include <QTest>

#include <oclero/QtPointerUtils.hpp>
#include <oclero/QtConnectionUtils.hpp>

void QtPointerUtilsTest::test_pointerShouldNotBeDeletedImmediately() const {
  auto pointerDestroyed = false;

  auto rawPointer = new QObject;
  QObject::connect(rawPointer, &QObject::destroyed, [&pointerDestroyed]() {
    // Set flag.
    pointerDestroyed = true;
  });
  oclero::QtDeleteLaterScopedPointer<QObject> scopedPointer(rawPointer);
  scopedPointer.reset();
  QVERIFY(!pointerDestroyed);
}

void QtPointerUtilsTest::test_pointerShouldBeDeletedAfterEventLoop() {
  auto pointerDestroyed = false;
  QEventLoop eventLoop(this);
  auto rawPointer = new QObject;
  QObject::connect(rawPointer, &QObject::destroyed, [&pointerDestroyed, &eventLoop]() {
    // Set flag.
    pointerDestroyed = true;
    eventLoop.quit();
  });
  oclero::QtDeleteLaterScopedPointer<QObject> scopedPointer(rawPointer);
  scopedPointer.reset();
  eventLoop.exec();
  QVERIFY(pointerDestroyed);
}
