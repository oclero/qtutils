#pragma once

#include <QString>
#include <QStringList>

namespace oclero {
/**
 * @brief Clears the directory's content, but not the directory.
 * @returns true (success), false otherwise.
 */
bool clearDirectoryContent(const QString& dirPath, const QStringList& extensionFilter = {});
} // namespace oclero
