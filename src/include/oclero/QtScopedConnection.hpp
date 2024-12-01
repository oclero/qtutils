#pragma once

#include <vector>

#include <QMetaObject>

namespace oclero {
/**
 * @brief RAII QMetaObject::Connection.
 */
class QtScopedConnection {
public:
  QtScopedConnection();
  QtScopedConnection(QtScopedConnection&& other) noexcept;
  QtScopedConnection(const QtScopedConnection& other) = delete;
  ~QtScopedConnection();

  /**
   * @brief Constructs a QtScopedConnection that takes ownership of the QMetaObject::Connection.
   * @param connection The connection to manage and disconnect automatically.
   */
  QtScopedConnection(const QMetaObject::Connection& connection);

  QtScopedConnection& operator=(QtScopedConnection&& other) noexcept;
  QtScopedConnection& operator=(const QtScopedConnection& other) = delete;

  /**
   * @brief Returns true if the connection is valid.
   */
  explicit operator bool() const;

  /**
   * @brief Disconnects the connection.
   */
  void disconnect();

  /**
   * @brief Sets the connection to take ownership of.
   * @param connection The connection to manage.
   */
  void set(QMetaObject::Connection const& connection);

  /**
   * @brief Returns true if the connection is valid.
   */
  bool isValid() const;

private:
  QMetaObject::Connection _connection;
};

/**
 * @brief RAII vector of QMetaObject::Connection.
 */
class QtScopedConnections {
public:
  QtScopedConnections();
  ~QtScopedConnections();

  QtScopedConnections(QtScopedConnections&& other) noexcept;
  QtScopedConnections(const QtScopedConnections& other) = delete;

  QtScopedConnections& operator=(QtScopedConnections&& other) noexcept;
  QtScopedConnections& operator=(const QtScopedConnections& other) = delete;


  void add(QMetaObject::Connection const& connection);
  void clear();

private:
  std::vector<QMetaObject::Connection> _connections;
};
} // namespace oclero
