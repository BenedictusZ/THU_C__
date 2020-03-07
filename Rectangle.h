//
// Created by Benedicate on 2020/2/13.
//

#ifndef THU_C___RECTANGLE_H
#define THU_C___RECTANGLE_H

#include "Point.h"

class Rectangle : public Point {
public:
	void initRectangle(float x, float y, float w, float h) {
		initPoint(x, y);
		this->w = w;
		this->h = h;
	}
	
	float getH() const { return h; }
	
	float getW() const { return w; }

private:
	float w;
	float h;
};


#endif //THU_C___RECTANGLE_H
