#include "view.h"

using namespace sf;

void SetView(StructView& view)
{
	view.camera.setSize(view.SIZE_VIEW);
	view.camera.setCenter(view.CENTRE);
	view.view_�entre = view.camera.getCenter();
}
void ViewUpdate(StructView& view)
{
	view.view_�entre = view.camera.getCenter();
}