#pragma once

#include <QObject>

class QtConnectionUtilsTests : public QObject {
  Q_OBJECT

private slots:
  void test_singleShotConnect();
  void test_scopedConnection();

signals:
  void signalTriggered();
};
