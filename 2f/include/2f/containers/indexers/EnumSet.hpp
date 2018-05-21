/*
  Stores indexers as a unordered map of <int,IndexedElement*>
  the "int" is part of an enum given as the first template parameter
  the baseSize argument can be used to initialize the internal storage unit with enum values
  essentially creating Indexers for each enum value until baseSize is reached
*/

#ifndef INDEXERS_ENUMSET_HPP
#define INDEXERS_ENUMSET_HPP

#include <unordered_map>
#include "Indexer.hpp"

typedef unsigned int uint;

namespace f2 {

namespace indexers {

class EnumSet : public Indexer {
protected:
  /* Attributes */
  std::unordered_map<uint,IndexedElement*> data;
  std::unordered_map<uint,IndexedElement*>::iterator iterator;
  /* Methods */

public:
  /* Constructors */
  EnumSet() {
    iterator = data.begin();
  }
  /* Destructor */
  virtual ~EnumSet() {
    for(iterator = data.begin();iterator != data.end();iterator++) {
      delete iterator->second;
    }
  }
  /* Methods */
  // Returns indexer at key [v]
  template<class IndexerType = IndexedElement> IndexerType* get(uint const& v) {
    std::unordered_map<uint,IndexedElement*>::iterator it = data.find(v);
    return static_cast<IndexerType*>(it->second);
  }
  // Inserts element in indexer
  void insert(uint const& v, IndexedElement* e) {
    data[v] = e;
    e->connectIndexer(root,this);
  }
  /* inherited methods */
  // Multiple container
  virtual bool isUnique() {
    return false;
  }
  // Reads an element from the indexer
  virtual IndexedElement* read(bool asFirst) {
    if(data.size() == 0) return 0; // Empty
    if(asFirst) { // First element
      iterator = data.begin();
      return iterator->second;
    }
    iterator++;
    if(iterator == data.end()) { // End of cycle
      iterator = data.begin(); // Cycling back
      return 0; // end signal
    } else { // Cycle continues
      if(iterator->second->isExpired()) { // bye bye
        delete iterator->second;
        data.erase(iterator->first);
      }
      return iterator->second;
    }
  }
};

};

};

#endif
