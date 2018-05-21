/*
  Master game engine indexer class
  Each frame uses one indexer to represent every object inside it
  Indexers can contain other indexers
*/

#ifndef INDEXER_HPP
#define INDEXER_HPP

#include "indexers/EnumSet.hpp"
#include "indexers/Set.hpp"
#include "indexers/ObjectSet.hpp"

namespace f2 {

class Indexer : public indexers::EnumSet {
public:
  /* Methods */
  void createSet(uint const& key) {
    insert(key,new indexers::Set);
  }
  void createEnumSet(uint const& key) {
    insert(key,new indexers::EnumSet);
  }
  void createIndexer(uint const& key) {
    insert(key,new Indexer);
  }
};

};

#endif
