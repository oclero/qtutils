#include <oclero/QtFileUtils.hpp>

#include <QDir>
#include <QFileInfo>

namespace oclero {
bool clearDirectoryContent(const QString& dirPath, const QStringList& extensionFilter) {
  QDir dir(dirPath);
  if (!dir.exists()) {
    return true;
  }

  const auto& entryInfoList = extensionFilter.isEmpty()
                                ? dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden)
                                : dir.entryInfoList(extensionFilter, QDir::Files | QDir::Hidden);
  for (const auto& entryInfo : entryInfoList) {
    const auto entryAbsPath = entryInfo.absoluteFilePath();
    if (entryInfo.isDir()) {
      QDir subDir(entryAbsPath);
      const auto subDirRemoveSuccess = subDir.removeRecursively();
      if (!subDirRemoveSuccess) {
        return false;
      }
    } else {
      const auto fileRemoveSuccess = dir.remove(entryAbsPath);
      if (!fileRemoveSuccess) {
        return false;
      }
    }
  }

  return true;
}
} // namespace oclero
