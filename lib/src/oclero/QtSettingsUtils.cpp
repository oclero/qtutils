#include <oclero/QtSettingsUtils.hpp>

namespace oclero {
void clearSetting(QSettings& settings, const char* key) {
  settings.remove(key);
}

void clearSetting(QSettings& settings, const QString& key) {
  const auto byteArray = key.toUtf8();
  const char* rawKey = byteArray.constData();
  clearSetting(settings, rawKey);
}
} // namespace oclero
