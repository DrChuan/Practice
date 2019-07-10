#include "DrawPlace.h"

void DrawPlace::mouseMoveEvent(QMouseEvent *e)
{
	emit moving(e->windowPos().x(), e->windowPos().y());
}