#pragma once

#include <QObject>

class QtPointerUtilsTest : public QObject {
  Q_OBJECT

private slots:
  void test_pointerShouldNotBeDeletedImmediately();
  void test_pointerShouldBeDeletedAfterEventLoop();
};
