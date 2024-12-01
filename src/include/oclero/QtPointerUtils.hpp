#pragma once

#include <memory>

#include <QObject>

namespace oclero {
struct QtDeleteLater {
  void operator()(QObject* o) const {
    o->deleteLater();
  }
};

template<typename TQObject>
using QtDeleteLaterScopedPointer = std::unique_ptr<TQObject, QtDeleteLater>;
} // namespace oclero
