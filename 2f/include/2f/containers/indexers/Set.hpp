/*
  Contains a set of indexed elements
*/

#ifndef INDEXERS_SET_HPP
#define INDEXERS_SET_HPP

#include <set>
#include "Indexer.hpp"

namespace f2 {

namespace indexers {

class Set : public f2::indexers::Indexer {
protected:
  std::set<IndexedElement*> data;
  std::set<IndexedElement*>::iterator iterator;
  /* set properties */
  int maxSize; // maximum size of set (eg. how much IndexedElement* can go inside)
public:
  /* Constructors */
  Set() : maxSize(-1) {}
  /* Destructor */
  virtual ~Set() {
    foreach<IndexedElement>([](IndexedElement* element){
      delete element;
    });
  }
  /* Methods */
  void insert(IndexedElement* element) {
    if(maxSize == -1 || data.size() < maxSize) data.insert(element);
    element->connectIndexer(root,this);
  }
  /* Inherited methods */
  virtual bool isUnique() {
    return false;
  }
  // Reads an element from the indexer
  virtual IndexedElement* read(bool asFirst) {
    if(data.size() == 0) return 0;
    if(asFirst) { // First element
      iterator = data.begin();
      return *iterator;
    }
    iterator++;
    if(iterator == data.end()) { // End of cycle
      iterator = data.begin(); // Cycling back
      return 0; // end signal
    } else { // Cycle continues
      if((*iterator)->isExpired()) { // bye bye
        delete *iterator;
        data.erase(iterator);
      }
      return *iterator;
    }
  }
};

};

};

#endif
