#ifndef STORAGEI_H
#define STORAGEI_H

#include <string>
#include <vector>

#include "storage/storageio.h"

namespace Storage {

class StorageI : public StorageIO {
private:
  // Disable copy and assignment operators
  StorageI(const StorageI&);
  StorageI& operator=(const StorageI&);

public:
  StorageI(
      const std::string& filePath,
      int treeMask=NONE,
      const std::vector<bool>& planeMask=s_dummyMask);
  virtual ~StorageI() {}

  /** Generate the `Event` object filled from entry `n` */
  Event& readEvent(Long64_t n);
};

}

#endif // STORAGEI_H