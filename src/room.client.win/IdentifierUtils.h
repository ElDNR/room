#pragma once

#include <stdlib.h>
#include <vector>
#include "Attributes.h"

using namespace room::client::win::attributes;

namespace room::client::win::utilities
{

	bool AddIntegerIdentifiableToVector(std::vector<IIntegerIdentifiable*>* collection, IIntegerIdentifiable* target);

	bool RemoveIntegerIdentifiableToVector(std::vector<IIntegerIdentifiable*>* collection, IIntegerIdentifiable* target);

};
