#include "sdlFiles.h"
#include "objectDef.h"
#include "sprites.h"
#include "level.h"
extern Object *player;
bool requestMove(int x, int y, int xChange, int yChange, Object* obj);
Level* getCurrentLevel();
bool objMove();

extern double delta;

class Flame : Object
{
public:
	OBJECT_DECLARATION(Flame,1012)
	Flame(int x2, int y2) : Object(x2,y2)
	{
		hovering = false;
		numFrames = 1;
		x = x2;
		y = y2;
		objMoveDir = 0;
		objMoveFraction = 0;
		faceDir = 0;
		prevMove = D_NONE;
	}
	Object* clone(int _x, int _y)
	{
		Object *tmp = new Flame(_x, _y);
		//Copy all of the contents of this object over to the new one
		memcpy(tmp, this, sizeof(*this));
		tmp->x = _x;
		tmp->y = _y;
		return tmp;
	}
	void doLogic()
	{
		lifetime -= delta;
		if (lifetime < 0) {
			die();
		}
		for (int xMod = -1; xMod <= 1; xMod++)
			for (int yMod = -1; yMod <= 1; yMod++)
			{
				if (xMod == 0 && yMod == 0)
					continue;
				Object *tmp = getCurrentLevel()->getObject(x + xMod, y + yMod);
				if (tmp != NULL)
					tmp->heat();
			}
	}
};
SPRITE_STATIONARY(Flame, "gfx/flames.png")
