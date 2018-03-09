/*
  A 2f Indexer stores elements and goes through them in multiple ways.
  - Single type indexer stores a pointer to a single element
  - Set type indexer stores pointers to multiple different elements
  - Hash type indexer stores indexers linked by a string key
  All elements stored in an indexer should innherit Indexed_element, which references its parent indexer
  and the "root" indexer.
  To delete an element from an indexer, the element's property "expired" must be set to true, after which the
  element will be deleted.
  All elements in a non persistent indexer (where persistent attribute is false (default)) should be dynamically allocated
  and will be freed when indexer gets deleted
*/

#ifndef INDEXER_HPP
#define INDEXER_HPP

#include <set>
#include <functional>
#include <map>
#include <string>

namespace f2 {

class Indexer;

class Indexed_Element {
protected:
	Indexer* root;
	Indexer* source;
	bool expired;
public:
	Indexed_Element() {
		expired = false;
	}
	virtual ~Indexed_Element() {

	}
	void connectIndexer(Indexer* r,Indexer* s) {
		root = r;
		source = s;
	}
	void setExpired(bool const& e = true) {
		expired = e;
	}
	bool isExpired() {
		return expired;
	}
};

typedef struct {
	std::map<std::string,Indexer*> hash; // 420 blazeit
	std::set<Indexed_Element*> elements;
	Indexed_Element* element;
} Data;

class Indexer {
public:
	/* Indexer */
	enum IndexerType {Set = 1,Hash = 2,Single = 3};
	/* Indexed Element Class */
protected:
	/* Properties */
	bool persistent; // Don't delete indexed elements on destruction
	/* Attributes */
	Indexer *root;
	Indexer* source;
	IndexerType type;
	Data data;
	/* Methods */
	Indexer* create(IndexerType const& t) { // Creates child indexer
    if(persistent) {
      // @TODO : Error, allocating memory that won't ever be deleted (memory leak)
    }
		Indexer* i = new Indexer(t);
		i->setRoot(root,this);
		return i;
	}
	void clear() { // Clears Indexed Elements
		switch(type) {
			case Indexer::Single:
			{
				if(data.element == 0) return;
				delete data.element;
				break;
			}
			case Indexer::Set:
			{
				std::set<Indexed_Element*>::iterator set_it = data.elements.begin();
				for(;set_it != data.elements.end();set_it++) {
					delete (*set_it);
				}
				break;
			}
			case Indexer::Hash:
			{
				auto it = data.hash.begin();
				for(;it != data.hash.end();it++) {
					delete it->second;
				}
				break;
			}
		}
	}
	/* Hash methods */
	Indexer* insert(std::string const& key,Indexer* i) { // Inserts indexer into Hash
		data.hash[key] = i;
		return i;
	}
public:
	Indexer(IndexerType const& t,bool const& p = false) { // Creates an Indexer
    type = t;
    persistent = p;
		root = this;
		source = this;
	}
	virtual ~Indexer() { // Clears Indexer if not persistent
    if(!persistent) clear();
	}
	/* Overloaded Operators */
	Indexer* operator[](const char key[]) { // Alias of get
		return get(key);
	}
	/* Hash Type */
	Indexer* create_set(std::string const& key) { // Creates a Set Type Indexer in a Hash Indexer
		return insert(key,create(Indexer::Set));
	}
	Indexer* create_hash(std::string const& key) { // Creates a Hash Type Indexer in a Hash Indexer
		return insert(key,create(Indexer::Hash));
	}
  void link(std::string const& key,Indexer* i) { // Links existing indexer to a Hash indexer
    data.hash[key] = i;
  }
	void insert(std::string const& key,Indexed_Element* e,IndexerType const& t = Indexer::Single) { // Inserts Indexed Element into Hash Indexer
		std::map<std::string,Indexer*>::iterator it = data.hash.find(key);
		if(it == data.hash.end()) {
			insert(key,create(t))->insert(e);
		} else {
			it->second->insert(e);
		}
	}
	Indexer* get(std::string const& key) { // Gets Indexer from Hash Indexer
		std::map<std::string,Indexer*>::iterator it = data.hash.find(key);
		if(it == data.hash.end()) return 0;
		return it->second;
	}
	/* Set & Single Type */
	void insert(Indexed_Element* e) { // Inserts Element into Indexer
		e->connectIndexer(root,this);
		switch(type) {
			case Single:
				data.element = e;
			break;
			case Set:
				data.elements.insert(e);
			break;
			default:
				// Error
			break;
		}
	}
	unsigned int count() { // Counts elements in indexer and its children
		switch(type) {
			case Single:
				return 1;
			break;
			case Set:
				return data.elements.size();
			break;
			case Hash:
				int c = 0;
				std::map<std::string,Indexer*>::iterator it = data.hash.begin();
				for(;it != data.hash.end();it++) {
					c += it->second->count();
				}
				return c;
			break;
		}
	}
	/* Common methods */
	void setRoot(Indexer* r,Indexer* s) { // Sets indexer source
		root = r;
		source = s;
	}
	/* Parcouring */
	template<typename IType = Indexed_Element>
	IType* value() { // Returns data element
		return static_cast<IType*>(data.element);
	}
	template<typename IType = Indexed_Element>
	IType* any(std::function<bool (IType* i)> f) { // Returns first element matching lambda function
		IType *p;
		switch(type) {
			case Indexer::Single:
			{
				if(data.element == 0) return 0;
				p = static_cast<IType*>(data.element);
				if(f(p)) {
					return p;
				}
			}
			case Indexer::Set:
			{
				std::set<Indexed_Element*>::iterator set_it = data.elements.begin();
				for(;set_it != data.elements.end();set_it++) {
					p = static_cast<IType*>(*set_it);
					if(f(p)) return p;
				}
				break;
			}
			case Indexer::Hash:
			{
				auto it = data.hash.begin();
				for(;it != data.hash.end();it++) {
					p = it->second->any<IType>(f);
					if(p != 0) return p;
				}
				break;
			}
		}
		return 0;
	}
	template<typename IType = Indexed_Element>
	void foreach(std::function<void (IType* i)> f) { // Applies lambda to Indexed Element
		switch(type) {
			case Indexer::Single:
			{
				if(data.element == 0) {
					return;
				}
				else if(data.element->isExpired()) {
					delete data.element;
					data.element = 0;
				} else {
					f(static_cast<IType*>(data.element));
				}
				break;
			}
			case Indexer::Set:
			{
				std::set<Indexed_Element*>::iterator set_it = data.elements.begin();
				for(;set_it != data.elements.end();set_it++) {
					if((*set_it)->isExpired()) {
						delete *set_it;
						data.elements.erase(set_it);
					} else {
						f(static_cast<IType*>((*set_it)));
					}
				}
				break;
			}
			case Indexer::Hash:
			{
				auto it = data.hash.begin();
				for(;it != data.hash.end();it++) {
					it->second->foreach<IType>(f);
				}
				break;
			}
		}
	}
};

}

#endif
