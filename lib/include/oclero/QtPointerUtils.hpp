#pragma once

#include <QObject>
#include <memory>

namespace oclero {
struct QtDeleteLater {
  void operator()(QObject* o) const {
    o->deleteLater();
  }
};

template<typename TQObject>
using QtDeleteLaterScopedPointer = std::unique_ptr<TQObject, QtDeleteLater>;
} // namespace oclero
