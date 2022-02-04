#include "QtEnumUtilsTests.hpp"

#include <QTest>

#include <oclero/QtEnumUtils.hpp>

void QtEnumUtilsTest::test_enumToString() const {
  auto const result = oclero::enumToString(QtEnumUtilsTest::Value1);
  QVERIFY(result == QStringLiteral("Value1"));
}

void QtEnumUtilsTest::test_tryGetEnumFromStringWithValidValue() const {
  auto const result = oclero::tryGetEnumFromString<QtEnumUtilsTest::TestEnum>(QStringLiteral("Value1"));
  auto const success = result.has_value() && result.value() == QtEnumUtilsTest::TestEnum::Value1;
  QVERIFY(success);
}

void QtEnumUtilsTest::test_tryGetEnumFromStringWithInvalidValue() const {
  auto const result = oclero::tryGetEnumFromString<QtEnumUtilsTest::TestEnum>(QStringLiteral("Value2"));
  QVERIFY(!result.has_value());
}

void QtEnumUtilsTest::test_enumFromStringWithValidValue() const {
  auto const result = oclero::enumFromString<QtEnumUtilsTest::TestEnum>(QStringLiteral("Value1"));
  QVERIFY(result == QtEnumUtilsTest::TestEnum::Value1);
}

void QtEnumUtilsTest::test_enumFromStringWithInvalidValue() const {
  auto const result = oclero::enumFromString<QtEnumUtilsTest::TestEnum>(QStringLiteral("Value2"));
  QVERIFY(result == QtEnumUtilsTest::TestEnum{});
}

void QtEnumUtilsTest::test_enumFromStringWithInvalidValueFallback() const {
  auto const fallback = QtEnumUtilsTest::TestEnum::Value1;
  auto const result = oclero::enumFromString<QtEnumUtilsTest::TestEnum>(QStringLiteral("Value2"), fallback);
  QVERIFY(result == fallback);
}

void QtEnumUtilsTest::test_enumUnderlyingType() const {
  constexpr auto result = oclero::toUnderlyingType(QtEnumUtilsTest::TestEnumClass::Value1);
  const auto& resultTypeInfo = typeid(&result);
  const unsigned int actual = 0u;
  const auto& actualTypeInfo = typeid(&actual);
  QVERIFY(resultTypeInfo == actualTypeInfo);
}

void QtEnumUtilsTest::test_isEnumValueWithValidValue() const {
  auto const result = oclero::isEnumValue<QtEnumUtilsTest::TestEnumClass>(1);
  QVERIFY(result);
}

void QtEnumUtilsTest::test_isEnumValueWithInvalidValue() const {
  auto const result = oclero::isEnumValue<QtEnumUtilsTest::TestEnumClass>(2);
  QVERIFY(!result);
}

void QtEnumUtilsTest::test_isEnumValueWithValidValueAndUncontiguousEnum() const {
  auto const result = oclero::isEnumValue<QtEnumUtilsTest::TestUncontiguousEnumClass>(-2);
  QVERIFY(result);
}

void QtEnumUtilsTest::test_isEnumValueWithInvalidValueAndUncontiguousEnum() const {
  auto const result = oclero::isEnumValue<QtEnumUtilsTest::TestUncontiguousEnumClass>(1);
  QVERIFY(!result);
}

void QtEnumUtilsTest::test_enumFromIntWithValidValue() const {
  auto const result = oclero::enumFromInt<QtEnumUtilsTest::TestUncontiguousEnumClass>(-2);
  QVERIFY(result == QtEnumUtilsTest::TestUncontiguousEnumClass::Value1);
}

void QtEnumUtilsTest::test_enumFromIntWithInvalidValue() const {
  auto const result = oclero::enumFromInt<QtEnumUtilsTest::TestUncontiguousEnumClass>(1);
  QVERIFY(result == QtEnumUtilsTest::TestUncontiguousEnumClass{});
}

void QtEnumUtilsTest::test_enumFromIntWithInvalidValueFallback() const {
  auto const fallback = QtEnumUtilsTest::TestUncontiguousEnumClass::Value2;
  auto const result = oclero::enumFromInt<QtEnumUtilsTest::TestUncontiguousEnumClass>(1, fallback);
  QVERIFY(result == fallback);
}
