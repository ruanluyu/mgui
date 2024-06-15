#pragma once
#include "Point.h"
#include "Rectangle.h"

namespace mgui {
	struct ScreenSpaceConfigs
	{
		int pixel_division = 16;
		int pixels_per_point = 2;

		int get_sub_points_per_point() const;

		float sp2p(const int& v) const;
		float p2px(const float& v) const;

		float px2p(const float& v) const;
		int p2sp(const float& v) const;



		Point2Df sp2p(const Point2Di& p) const;
		Point2Df p2px(const Point2Df& p) const;

		Point2Df px2p(const Point2Df& p) const;
		Point2Di p2sp(const Point2Df& p) const;

		Size2Df sp2p(const Size2Di& p) const;
		Size2Df p2px(const Size2Df& p) const;

		Size2Df px2p(const Size2Df& p) const;
		Size2Di p2sp(const Size2Df& p) const;


		Rectangle2Df sp2p(const Rectangle2Di& p) const;
		Rectangle2Df p2px(const Rectangle2Df& p) const;

		Rectangle2Df px2p(const Rectangle2Df& p) const;
		Rectangle2Di p2sp(const Rectangle2Df& p) const;



	};
}


