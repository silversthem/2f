/*

*/

#ifndef OBJECTINDEXER
#define OBJECTINDEXER

#include "../IndexedElement.hpp"
#include <set>

namespace f2 {

namespace indexers {

template <typename DataType, typename ObjectType>
class ObjectSet {
protected:
  std::set<ObjectType> data;
  std::set<ObjectType>::iterator iterator;
  ObjectType object;
public:
  /* Methods */

  /* interface methods */

  /* inherited methods */
  virtual IndexedElement* read(bool asFirst) {

  }
  virtual bool isUnique() {
    return false;
  }
};

};

};

#endif
