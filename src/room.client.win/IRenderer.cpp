#include "IRenderer.h"

using namespace renderers;

bool operator==(const IRenderer& lhs, const IRenderer& rhs) {
	return lhs.getId() == rhs.getId();
}

