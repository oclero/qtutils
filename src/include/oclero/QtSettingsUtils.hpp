#pragma once

#include <oclero/QtEnumUtils.hpp>

#include <QSettings>
#include <QVariant>

namespace oclero {
template<typename TValue>
std::optional<TValue> tryGetVariantValue(const QVariant& variant) {
  if (!variant.isValid())
    return {};

  if constexpr (std::is_same_v<TValue, int>) {
    const auto variantType = variant.metaType().id();
    const auto validType = variantType == QMetaType::Type::Int || variantType == QMetaType::Type::LongLong
                           || variantType == QMetaType::Type::UInt || variantType == QMetaType::Type::ULongLong;
    return validType ? variant.toInt() : std::optional<TValue>();
  } else if constexpr (std::is_same_v<TValue, double>) {
    const auto variantType = variant.metaType().id();
    const auto validType = variantType == QMetaType::Type::Int || variantType == QMetaType::Type::LongLong
                           || variantType == QMetaType::Type::UInt || variantType == QMetaType::Type::ULongLong
                           || variantType == QMetaType::Type::Double;
    return validType ? variant.toDouble() : std::optional<TValue>();
  } else if constexpr (std::is_same_v<TValue, QString>) {
    const auto variantType = variant.metaType().id();
    return variantType == QMetaType::Type::QString ? variant.toString() : std::optional<TValue>();
  } else if (variant.canConvert<TValue>()) {
    return variant.value<TValue>();
  } else {
    return {};
  }
}

template<typename TValue>
std::optional<TValue> tryLoadSetting(const QSettings& settings, const char* key) {
  if constexpr (std::is_enum<TValue>()) {
    const auto variant_str = settings.value(key).toString();
    return tryGetEnumFromString<TValue>(variant_str);
  } else {
    const auto variant = settings.value(key);
    return tryGetVariantValue<TValue>(variant);
  }
}

template<typename TValue>
std::optional<TValue> tryLoadSetting(const QSettings& settings, const QString& key) {
  const auto byteArray = key.toUtf8();
  const auto* rawKey = byteArray.constData();
  return tryLoadSetting<TValue>(settings, rawKey);
}

template<typename TValue>
TValue loadSetting(const QSettings& settings, const char* key, const TValue& defaultValue = TValue()) {
  return tryLoadSetting<TValue>(settings, key).value_or(defaultValue);
}

template<typename TValue>
TValue loadSetting(const QSettings& settings, const QString& key, const TValue& defaultValue = TValue()) {
  const auto byteArray = key.toUtf8();
  const auto* rawKey = byteArray.constData();
  return loadSetting<TValue>(settings, rawKey, defaultValue);
}

template<typename TValue>
void saveSetting(QSettings& settings, const char* key, const TValue& value) {
  if constexpr (std::is_enum<TValue>()) {
    settings.setValue(key, QVariant::fromValue<QString>(enumToString(value)));
  } else {
    settings.setValue(key, value);
  }
  settings.sync();
}

template<typename TValue>
void saveSetting(QSettings& settings, const QString& key, const TValue& value) {
  const auto byteArray = key.toUtf8();
  const auto* rawKey = byteArray.constData();
  saveSetting<TValue>(settings, rawKey, value);
}

void clearSetting(QSettings& settings, const char* key);

void clearSetting(QSettings& settings, const QString& key);
} // namespace oclero
