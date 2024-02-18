#pragma once

#include <QTest>

namespace oclero {
/// Return true if all tests pass, false otherwise.
template<class T, class... Args>
bool runTests() {
  T t;
  auto result = QTest::qExec(&t) == 0;
  if constexpr (sizeof...(Args) == 0) {
    return result;
  } else {
    return result && runTests<Args...>();
  }
}
} // namespace oclero
