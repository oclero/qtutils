#pragma once

#include <QObject>

class QtEnumUtilsTest : public QObject {
  Q_OBJECT

public:
  enum TestEnum {
    Value0,
    Value1,
  };
  Q_ENUM(TestEnum);

  enum class TestEnumClass : unsigned int {
    Value0,
    Value1,
  };
  Q_ENUM(TestEnumClass);

  enum class TestUncontiguousEnumClass {
    Value0 = 5,
    Value1 = -2,
    Value2 = 2,
  };
  Q_ENUM(TestUncontiguousEnumClass);

private slots:
  void test_enumToString() const;
  void test_tryGetEnumFromStringWithValidValue() const;
  void test_tryGetEnumFromStringWithInvalidValue() const;
  void test_enumFromStringWithValidValue() const;
  void test_enumFromStringWithInvalidValue() const;
  void test_enumFromStringWithInvalidValueFallback() const;
  void test_enumUnderlyingType() const;
  void test_isEnumValueWithValidValue() const;
  void test_isEnumValueWithInvalidValue() const;
  void test_isEnumValueWithValidValueAndUncontiguousEnum() const;
  void test_isEnumValueWithInvalidValueAndUncontiguousEnum() const;
  void test_enumFromIntWithValidValue() const;
  void test_enumFromIntWithInvalidValue() const;
  void test_enumFromIntWithInvalidValueFallback() const;
};
