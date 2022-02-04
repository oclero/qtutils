#include "QtSettingsUtilsTests.hpp"

#include <QTest>

#include <oclero/QtSettingsUtils.hpp>

constexpr auto SETTINGS_KEY = "Toto";

using namespace oclero;

void QtSettingsUtilsTests::init() {
  {
    QSettings qSettings;
    qSettings.remove(SETTINGS_KEY);
  }
}

void QtSettingsUtilsTests::cleanup() {
  {
    QSettings qSettings;
    qSettings.remove(SETTINGS_KEY);
  }
}

void QtSettingsUtilsTests::test_tryLoadInexistentSetting_enum() const {
  auto const optionalValue = tryLoadSetting<DummyEnum>(SETTINGS_KEY);
  QVERIFY(!optionalValue.has_value());
}

void QtSettingsUtilsTests::test_tryLoadInvalidSetting_enum() const {
  QSettings{}.setValue(SETTINGS_KEY, "1");
  auto const optionalValue = tryLoadSetting<DummyEnum>(SETTINGS_KEY);
  QVERIFY(!optionalValue.has_value());
}

void QtSettingsUtilsTests::test_tryLoadValidSetting_enum() const {
  QSettings{}.setValue(SETTINGS_KEY, "DummyValue2");
  auto const optionalValue = tryLoadSetting<DummyEnum>(SETTINGS_KEY);
  QVERIFY(optionalValue.has_value() && optionalValue.value() == DummyEnum::DummyValue2);
}

void QtSettingsUtilsTests::test_tryLoadInexistentSetting_int() const {
  auto const optionalValue = tryLoadSetting<int>(SETTINGS_KEY);
  QVERIFY(!optionalValue.has_value());
}

void QtSettingsUtilsTests::test_tryLoadInvalidSetting_int() const {
  QSettings{}.setValue(SETTINGS_KEY, "abc");
  auto const optionalValue = tryLoadSetting<int>(SETTINGS_KEY);
  QVERIFY(!optionalValue.has_value());
}

void QtSettingsUtilsTests::test_tryLoadValidSetting_int() const {
  QSettings{}.setValue(SETTINGS_KEY, 42);
  auto const optionalValue = tryLoadSetting<int>(SETTINGS_KEY);
  QVERIFY(optionalValue.has_value() && optionalValue.value() == 42);
}

void QtSettingsUtilsTests::test_loadValidSetting() const {
  QSettings{}.setValue(SETTINGS_KEY, 42);
  auto const value = loadSetting<int>(SETTINGS_KEY);
  QVERIFY(value == 42);
}

void QtSettingsUtilsTests::test_loadInvalidSetting() const {
  auto const value = loadSetting<int>(SETTINGS_KEY, 12);
  QVERIFY(value == 12);
}

void QtSettingsUtilsTests::test_saveSetting_int() const {
  saveSetting<int>(SETTINGS_KEY, 42);
  auto const value = QSettings{}.value(SETTINGS_KEY).toInt();
  QVERIFY(value == 42);
}

void QtSettingsUtilsTests::test_saveSetting_enum() const {
  saveSetting<DummyEnum>(SETTINGS_KEY, DummyEnum::DummyValue2);
  // Enum are saved as strings and parsed.
  auto const value = QSettings{}.value(SETTINGS_KEY).toString();
  QVERIFY(value == "DummyValue2");
}

void QtSettingsUtilsTests::test_useQStringAsKey() const {
  auto qStringKey = QString{ SETTINGS_KEY };

  saveSetting(qStringKey, 42);
  auto const value = QSettings{}.value(SETTINGS_KEY).toInt();
  QVERIFY(value == 42);

  QSettings{}.setValue(qStringKey, "DummyValue");
  auto const valueInSettings = loadSetting(qStringKey, QString{});
  QVERIFY(valueInSettings == "DummyValue");
}
