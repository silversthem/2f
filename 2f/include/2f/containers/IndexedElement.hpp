/*
	All elements in an indexer must innherit from this class
	IndexedElement(s) are linked to their main frame indexer and their origin indexer
	(since indexers can contain other indexers ad infinitum)
	Elements in indexers can "expire", implying they will have to be deleted next iteration
	@TODO : Safety with ref counting
*/

#ifndef INDEXEDELEMENT_HPP
#define INDEXEDELEMENT_HPP

#include <functional>

namespace f2 {

class IndexedElement {
protected:
	IndexedElement* root;
	IndexedElement* source;
	bool expired;
public:
	/* Constructor */
	IndexedElement() {
		expired = false;
		root = this;
	}
	/* Destructor */
	virtual ~IndexedElement() {}
	/* State configuration */
	void connectIndexer(IndexedElement* r,IndexedElement* s) {
		root = r;
		source = s;
		onConnected();
	}
	void setExpired(bool const& e = true) {
		expired = e;
	}
	bool isExpired() {
		return expired;
	}
	/* virtual methods */
	// Overload to adjust indexer on insertion into source indexer
	virtual void onConnected() {

	}
	// Is the indexer a single element container
	virtual bool isUnique() {
		return true;
	}
	/* allows for inherited classes to contain more than one element */
	virtual IndexedElement* read(bool asFirst) {
		return this;
	}
	/* Applies a lambda to the IndexedElement */
	template<typename CastedAs, typename ReturnType = void>
	ReturnType apply(std::function<ReturnType (CastedAs*)> proc) {
		IndexedElement* current = read(true); // Reading from beginning
		if(isUnique()) { // Single type container
			return proc(static_cast<CastedAs*>(this));
		} else { // Multiple type container
			while(current != 0) {
				current->apply<CastedAs,ReturnType>(proc);
				current = read(false); // Reading next element
			}
		}
	}
};

};

#endif
