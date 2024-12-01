#include <oclero/QtScopedConnection.hpp>

#include <QObject>

namespace oclero {
QtScopedConnection::QtScopedConnection() = default;

QtScopedConnection::QtScopedConnection(QtScopedConnection&& other) noexcept {
  disconnect();
  _connection = other._connection;
  other._connection = QMetaObject::Connection();
}

QtScopedConnection::QtScopedConnection(const QMetaObject::Connection& connection) {
  set(connection);
}

QtScopedConnection::~QtScopedConnection() {
  disconnect();
}

QtScopedConnection& QtScopedConnection::operator=(QtScopedConnection&& other) noexcept {
  if (this != &other) {
    disconnect();
    _connection = other._connection;
    other._connection = QMetaObject::Connection();
  }
  return *this;
}

QtScopedConnection::operator bool() const {
  return isValid();
}

void QtScopedConnection::disconnect() {
  QObject::disconnect(_connection);
}

bool QtScopedConnection::isValid() const {
  return _connection;
}

void QtScopedConnection::set(const QMetaObject::Connection& connection) {
  disconnect();
  _connection = connection;
}

QtScopedConnections::QtScopedConnections() {}

QtScopedConnections::~QtScopedConnections() {
  clear();
}

QtScopedConnections::QtScopedConnections(QtScopedConnections&& other) noexcept {
  clear();
  _connections = other._connections;
  other._connections.clear();
}

QtScopedConnections& QtScopedConnections::operator=(QtScopedConnections&& other) noexcept {
  if (this != &other) {
    clear();
    _connections = other._connections;
    other._connections.clear();
  }
  return *this;
}

void QtScopedConnections::add(QMetaObject::Connection const& connection) {
  _connections.emplace_back(connection);
}

void QtScopedConnections::clear() {
  for (auto const& connection : _connections) {
    QObject::disconnect(connection);
  }
  _connections.clear();
}
} // namespace oclero
