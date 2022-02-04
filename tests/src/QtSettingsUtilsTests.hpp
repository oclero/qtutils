#pragma once

#include <QObject>

class QtSettingsUtilsTests : public QObject {
  Q_OBJECT

public:
  enum class DummyEnum {
    DummyValue0,
    DummyValue1,
    DummyValue2,
  };
  Q_ENUM(DummyEnum)

private slots:
  void init();
  void cleanup();

  void test_tryLoadInexistentSetting_enum() const;
  void test_tryLoadInvalidSetting_enum() const;
  void test_tryLoadValidSetting_enum() const;

  void test_tryLoadInexistentSetting_int() const;
  void test_tryLoadInvalidSetting_int() const;
  void test_tryLoadValidSetting_int() const;

  void test_loadValidSetting() const;
  void test_loadInvalidSetting() const;

  void test_saveSetting_int() const;
  void test_saveSetting_enum() const;

  void test_useQStringAsKey() const;
};
