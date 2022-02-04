#include <oclero/QtSettingsUtils.hpp>

namespace oclero {
void clearSetting(const char* key) {
  QSettings settings;
  settings.remove(key);
}

void clearSetting(const QString& key) {
  const auto byteArray = key.toUtf8();
  const char* rawKey = byteArray.constData();
  clearSetting(rawKey);
}
} // namespace oclero
