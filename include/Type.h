// -----------------------------------------------------------------------------
// GEngine : High-Performance Native Virtual Window System
// Copyright (c) 2026 Bonnie Inc. 
// All rights reserved.
// 
// [ Collaboration ]
// This engine is co-architected and powered by google Gemini and IGTTS0420
// Licensed under the MIT License.
// -----------------------------------------------------------------------------
#pragma once

#include <cstdint>

namespace GEngine
{
	// Basic Axis - Point
	struct Point
	{
		float x;
		float y;

		Point operator+(const Point& other) const { return { x + other.x, y + other.y }; }
		Point operator-(const Point& other) const { return { x - other.x, y - other.y }; }
	};

	// Size
	struct Size
	{
		float width;
		float height;
	};

	// Rect
	struct Rect
	{
		float x, y, w, h;

		Rect(float x = 0, float y = 0, float w = 0, float h = 0) : x(x), y(y), w(w), h(h) {}

		bool Contains(Point pt) const
		{
			return (pt.x >= x && pt.x <= x + w && pt.y >= y && pt.y <= y + h);
		}

		Point TopLeft() const { return { x, y }; }

		// Viewport Culling 에 쓰일 교차 판정
		bool Intersects(const Rect& other) const
		{
			return !(other.x > x + w || other.x + other.w < x ||
				other.y > y + h || other.y + other.h < y);
		}
	};

	// Color
	struct Color
	{
		float r, g, b, a;

		static Color White() { return { 1.0f, 1.0f, 1.0f, 1.0f }; }
		static Color Black() { return { 0.0f, 0.0f, 0.0f, 1.0f }; }
		static Color Red() { return { 1.0f, 0.0f, 0.0f, 1.0f }; }
		static Color Transparent() { return { 0.0f, 0.0f, 0.0f, 0.0f }; }
	};
}