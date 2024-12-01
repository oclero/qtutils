#pragma once

#include <memory>
#include <functional>

#include <QMetaObject>
#include <QObject>

namespace oclero {
/**
 * @brief Allows to connect to a signal a callaback that will be executed only once.
 */
template<typename TSender, typename TSignal>
void singleShotConnect(TSender sender, TSignal signal, const std::function<void()>& callback) {
  auto const connection = std::make_shared<QMetaObject::Connection>();
  *connection = QObject::connect(sender, signal, sender, [connection, callback]() {
    // Delete connection first.
    QObject::disconnect(*connection);

    // Call captured callback.
    if (callback) {
      callback();
    }
  });
}
} // namespace oclero
