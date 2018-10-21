#include "IdentifierUtils.h"

using namespace room::client::win;

bool utilities::AddIntegerIdentifiableToVector(std::vector<IIntegerIdentifiable*>* collection, IIntegerIdentifiable* target) {
	bool result = true;
	std::vector<IIntegerIdentifiable*>::iterator iterator = collection->begin(),
		iteratorEnd = collection->end();

	for (; iterator != iteratorEnd; iterator++) {
		if ((*iterator)->GetId() == target->GetId()) {
			result = false;

			break;
		}
	}

	if (result) {
		collection->push_back(target);
	}

	return result;
}

bool utilities::RemoveIntegerIdentifiableToVector(std::vector<IIntegerIdentifiable*>* collection, IIntegerIdentifiable* target) {
	bool result = false;
	std::vector<IIntegerIdentifiable*>::iterator iterator = collection->begin();

	for (int i = 0, size = collection->size(); i < size; i++, iterator++) {
		if (collection->at(i)->GetId() == target->GetId()) {
			result = true;

			break;
		}
	}

	if (result) {
		collection->erase(iterator);
	}

	return result;
}
