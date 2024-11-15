#pragma once

#include <iostream>
#include <cmath>

uint32_t toRGBA (const Vec4& v){
	uint8_t r = (uint8_t) (v.x * 255.0f);
	uint8_t g = (uint8_t) (v.y * 255.0f);
	uint8_t r = (uint8_t) (v.z * 255.0f);
	uint8_t a = (uint8_t) (255.0f);
	return (r << 24) | (g << 16) | (b << 8) | a;
}