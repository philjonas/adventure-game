#pragma once

enum Facing
{
	south,
	north,
	west,
	east
};

namespace Data {
	const int SPRITE_SIDE = 32;
	const int HEIGHT_IN_SPRITES = 8;
	const int WIDTH_IN_SPRITES = 16;
	const int SPRITES_PER_SCREEN = HEIGHT_IN_SPRITES * WIDTH_IN_SPRITES;
	const int HEIGHT_IN_PIXELS = SPRITE_SIDE * HEIGHT_IN_SPRITES;
	const int WIDTH_IN_PIXELS = SPRITE_SIDE * WIDTH_IN_SPRITES;
	const int HALF_SPRITE = SPRITE_SIDE / 2;
}
