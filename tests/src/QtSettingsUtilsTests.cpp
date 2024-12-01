#include "QtSettingsUtilsTests.hpp"

#include <QTest>

#include <oclero/QtSettingsUtils.hpp>

constexpr auto SETTINGS_KEY = "Toto";

using namespace oclero;

void QtSettingsUtilsTests::init() {
  QSettings qSettings;
  qSettings.remove(SETTINGS_KEY);
}

void QtSettingsUtilsTests::cleanup() {
  QSettings qSettings;
  qSettings.remove(SETTINGS_KEY);
}

void QtSettingsUtilsTests::test_tryLoadInexistentSetting_enum() const {
  QSettings settings;
  auto const optionalValue = tryLoadSetting<DummyEnum>(settings, SETTINGS_KEY);
  QVERIFY(!optionalValue.has_value());
}

void QtSettingsUtilsTests::test_tryLoadInvalidSetting_enum() const {
  {
    QSettings{}.setValue(SETTINGS_KEY, "1");
  }
  QSettings settings;
  auto const optionalValue = tryLoadSetting<DummyEnum>(settings, SETTINGS_KEY);
  QVERIFY(!optionalValue.has_value());
}

void QtSettingsUtilsTests::test_tryLoadValidSetting_enum() const {
  {
    QSettings{}.setValue(SETTINGS_KEY, "DummyValue2");
  }
  QSettings settings;
  auto const optionalValue = tryLoadSetting<DummyEnum>(settings, SETTINGS_KEY);
  QVERIFY(optionalValue.has_value() && optionalValue.value() == DummyEnum::DummyValue2);
}

void QtSettingsUtilsTests::test_tryLoadInexistentSetting_int() const {
  QSettings settings;
  auto const optionalValue = tryLoadSetting<int>(settings, SETTINGS_KEY);
  QVERIFY(!optionalValue.has_value());
}

void QtSettingsUtilsTests::test_tryLoadInvalidSetting_int() const {
  {
    QSettings{}.setValue(SETTINGS_KEY, "abc");
  }
  QSettings settings;
  auto const optionalValue = tryLoadSetting<int>(settings, SETTINGS_KEY);
  QVERIFY(!optionalValue.has_value());
}

void QtSettingsUtilsTests::test_tryLoadValidSetting_int() const {
  {
    QSettings{}.setValue(SETTINGS_KEY, 42);
  }
  QSettings settings;
  auto const optionalValue = tryLoadSetting<int>(settings, SETTINGS_KEY);
  QVERIFY(optionalValue.has_value() && optionalValue.value() == 42);
}

void QtSettingsUtilsTests::test_loadValidSetting() const {
  {
    QSettings{}.setValue(SETTINGS_KEY, 42);
  }
  QSettings settings;
  auto const value = loadSetting<int>(settings, SETTINGS_KEY);
  QVERIFY(value == 42);
}

void QtSettingsUtilsTests::test_loadInvalidSetting() const {
  QSettings settings;
  auto const value = loadSetting<int>(settings, SETTINGS_KEY, 12);
  QVERIFY(value == 12);
}

void QtSettingsUtilsTests::test_saveSetting_int() const {
  {
    QSettings settings;
    saveSetting<int>(settings, SETTINGS_KEY, 42);
  }
  auto const value = QSettings{}.value(SETTINGS_KEY).toInt();
  QVERIFY(value == 42);
}

void QtSettingsUtilsTests::test_saveSetting_enum() const {
  {
    QSettings settings;
    saveSetting<DummyEnum>(settings, SETTINGS_KEY, DummyEnum::DummyValue2);
  }
  // Enum are saved as strings and parsed.
  auto const value = QSettings{}.value(SETTINGS_KEY).toString();
  QVERIFY(value == "DummyValue2");
}

void QtSettingsUtilsTests::test_useQStringAsKey() const {
  auto qStringKey = QString{ SETTINGS_KEY };

  {
    QSettings settings;
    saveSetting<int>(settings, qStringKey, 42);
  }
  auto const value = QSettings{}.value(SETTINGS_KEY).toInt();
  QVERIFY(value == 42);

  QSettings{}.setValue(qStringKey, "DummyValue");

  {
    QSettings settings;
    auto const valueInSettings = loadSetting<QString>(settings, qStringKey, QString{});
    QVERIFY(valueInSettings == "DummyValue");
  }
}
