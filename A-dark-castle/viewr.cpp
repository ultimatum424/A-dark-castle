#include "view.h"

using namespace sf;

void SetView(StructView& view)
{
	view.camera.setSize(view.SIZE_VIEW);
	view.camera.setCenter(view.CENTRE);
	view.view_ñentre = view.camera.getCenter();
}
void ViewUpdate(StructView& view, float time, int stage_game)
{
	if (stage_game == 1)
	{
		if ((Keyboard::isKeyPressed(Keyboard::D)))
			view.camera.move(-0.5, 0);
		if ((Keyboard::isKeyPressed(Keyboard::A)))
			view.camera.move(0.5, 0);
		if ((Keyboard::isKeyPressed(Keyboard::W)))
			view.camera.move(0, 0.5);
		if ((Keyboard::isKeyPressed(Keyboard::S)))
			view.camera.move(0, -0.5);
	}
	view.view_ñentre = view.camera.getCenter();
}