/*
  Base indexer methods, solely relying on lambda functions and IndexedElement methods
*/

#ifndef INDEXERS_INTERFACE_HPP
#define INDEXERS_INTERFACE_HPP

#include "../IndexedElement.hpp"

namespace f2 {

namespace indexers {

class Indexer : public f2::IndexedElement {
public:
  /* New indexer */
  Indexer* cross() {}
  /* One element */
  // Returns first element matching eval
  template<typename CastedAs = f2::IndexedElement>
  IndexedElement* any(std::function<bool (CastedAs*)> eval) {

  }
  /* Procedures */
  // Applies proc to any element matching eval
  template<typename CastedAs = f2::IndexedElement>
  void filtered(std::function<bool (CastedAs*)> eval, std::function<void (CastedAs*)> proc) {
    foreach<CastedAs>([eval,proc](CastedAs* element){
      if(eval(element)) {
        proc(element);
      } else {
        // @TODO add default else function as arg
      }
    });
  }
  // Applies proc to every elements in indexer
  template<typename CastedAs = f2::IndexedElement>
  void foreach(std::function<void (CastedAs*)> proc) {
    apply<CastedAs,void>(proc);
  }
};

};

};

#endif
