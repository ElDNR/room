#include "Renderers.h"

using namespace room::client::win::renderers;

bool operator==(const IRenderer& lhs, const IRenderer& rhs) {
	return lhs.GetId() == rhs.GetId();
}

