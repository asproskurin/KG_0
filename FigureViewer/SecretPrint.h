#pragma once

#include "Figure.h"

class SecretPrint : public Figure
{
public:
	SecretPrint(int size = 12, int offsetX = 150, int offsetY = 150) : Figure(size, offsetX, offsetY)
	{
	}
	void Draw(HDC dc)
	{
		MoveToEx(dc, offsetX - 3 * size, offsetY - 3 * size, NULL);
		LineTo(dc, offsetX, offsetY - 3 * size);
		LineTo(dc, offsetX, offsetY + size);
		LineTo(dc, offsetX - 2 * size, offsetY + 3 * size);
		LineTo(dc, offsetX - 2.5 * size, offsetY + 2.5 * size);
		LineTo(dc, offsetX - size, offsetY + size);
		LineTo(dc, offsetX - size, offsetY - 2 * size);
		LineTo(dc, offsetX - 3 * size, offsetY - 2 * size);
		LineTo(dc, offsetX - 3 * size, offsetY - 3 * size);

		MoveToEx(dc, offsetX + size, offsetY - 3 * size, NULL);
		LineTo(dc, offsetX + 2 * size, offsetY - 3 * size);
		LineTo(dc, offsetX + 2 * size, offsetY + size);
		LineTo(dc, offsetX - size, offsetY + 4 * size);
		LineTo(dc, offsetX - 1.5 * size, offsetY + 3.5 * size);
		LineTo(dc, offsetX + size, offsetY + size);
		LineTo(dc, offsetX + size, offsetY - 3 * size);
	}

	bool InnerPoint(int X, int Y)
	{
		bool first = (X <= offsetX + 2 * size) && (X >= offsetX + size) && (Y >= offsetY - 3 * size) && (Y <= offsetY + size);
		bool second = (Y >= -1 * X + 2 * size + offsetY + offsetX) && (Y <= -1 * X + 3 * size + offsetY + offsetX)
			&& (Y >= offsetY + size) && (Y <= X + 5 * size + offsetY - offsetX);
		bool third = (X >= offsetX - 3 * size) && (X <= offsetX) && (Y >= offsetY - 3 * size) && (Y <= offsetY - 2 * size);
		bool fourth = (X >= offsetX - size) && (X <= offsetX) && (Y >= offsetY - 2 * size) && (Y <= offsetY + size);
		bool fifth = (Y <= -1 * X + offsetX + offsetY + size) && (Y >= -1 * X + offsetX + offsetY) && (Y >= offsetY + size)
			&& (Y <= X + 5 * size + offsetY - offsetX);
		return first || second || third || fourth || fifth;
	}
};