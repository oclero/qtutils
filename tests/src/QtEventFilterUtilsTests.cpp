#include "QtEventFilterUtilsTests.hpp"

#include <QTest>
#include <QDebug>

#include <oclero/QtEventFilterUtils.hpp>

void QtEventFilterUtilsTest::test_filter() const {
  auto* dummyObject = new QObject();
  auto called{ false };

  // Listen to a dummy event.
  oclero::EventFilter<QEvent::Type::ContextMenu>::install(dummyObject, [&called](QContextMenuEvent*) {
    called = true;
    return false;
  });

  // Send this dummy event synchronously.
  QContextMenuEvent dummyEvent(QContextMenuEvent::Reason::Other, QPoint{ 0, 0 }, QPoint{ 0, 0 });
  QCoreApplication::sendEvent(dummyObject, &dummyEvent);

  // Check if callback has correctly been called.
  QVERIFY(called);
}
