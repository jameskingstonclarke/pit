#include "value.hpp"

namespace pit {

	RefFN::RefFN(std::string name, std::shared_ptr<Bundle> bundle, uint8_t arity, uint8_t locals) {
		ref_type = FN;
		this->name = name;
		this->bundle = bundle;
		this->arity = arity;
		this->locals = locals;
	}

	std::string RefFN::debug() {
		std::ostringstream ss;
		ss << "<ref-fn " << name << ">";
		return ss.str(); 
	}

	RefArr::RefArr(uint8_t size) {
		this->size = size;
	}

	std::string RefArr::debug() {
		std::ostringstream ss;
		ss << "<ref-arr " << size << ">";
		return ss.str();
	}

	RefContainer::RefContainer(uint32_t size, std::vector<Value> init_values) { 
		ref_type = CONTAINER;
		this->size = size;
		this->data = init_values;
	}

	std::string RefContainer::debug() {
		std::ostringstream ss;
		ss << "<ref-container>";
		for (auto v : data)
			ss << v.debug() << ", ";
		return ss.str();
	}
}