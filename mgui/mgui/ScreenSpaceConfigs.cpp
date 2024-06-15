#include "ScreenSpaceConfigs.h"

#include "math.h"
using namespace mgui;

int ScreenSpaceConfigs::get_sub_points_per_point() const
{
	return pixels_per_point * pixel_division;
}

float ScreenSpaceConfigs::sp2p(const int& v) const
{
	return v / float(get_sub_points_per_point());
}

float ScreenSpaceConfigs::p2px(const float& v) const
{
	return v * pixels_per_point;
}

int ScreenSpaceConfigs::p2sp(const float& v) const
{
	return static_cast<int>(roundf(v * float(get_sub_points_per_point())));
}

float ScreenSpaceConfigs::px2p(const float& v) const
{
	return v / pixels_per_point;
}



Point2Df ScreenSpaceConfigs::sp2p(const Point2Di& p) const
{
	return Point2Df(sp2p(p.x), sp2p(p.y));
}

Point2Df ScreenSpaceConfigs::p2px(const Point2Df& p) const
{
	return Point2Df(p2px(p.x), p2px(p.y));
}

Point2Df ScreenSpaceConfigs::px2p(const Point2Df& p) const
{
	return Point2Df(px2p(p.x), px2p(p.y));
}

Point2Di ScreenSpaceConfigs::p2sp(const Point2Df& p) const
{
	return Point2Di(p2sp(p.x), p2sp(p.y));
}

Size2Df ScreenSpaceConfigs::sp2p(const Size2Di& p) const
{
	return Size2Df(sp2p(p.x), sp2p(p.y));
}

Size2Df ScreenSpaceConfigs::p2px(const Size2Df& p) const
{
	return Size2Df(p2px(p.x), p2px(p.y));
}

Size2Df ScreenSpaceConfigs::px2p(const Size2Df& p) const
{
	return Size2Df(px2p(p.x), px2p(p.y));
}

Size2Di ScreenSpaceConfigs::p2sp(const Size2Df& p) const
{
	return Size2Di(p2sp(p.x), p2sp(p.y));
}

Rectangle2Df ScreenSpaceConfigs::sp2p(const Rectangle2Di& p) const
{
	return Rectangle2Df(sp2p(p.pos), sp2p(p.size));
}

Rectangle2Df ScreenSpaceConfigs::p2px(const Rectangle2Df& p) const
{
	return Rectangle2Df(p2px(p.pos), p2px(p.size));
}

Rectangle2Df ScreenSpaceConfigs::px2p(const Rectangle2Df& p) const
{
	return Rectangle2Df(px2p(p.pos), px2p(p.size));
}

Rectangle2Di ScreenSpaceConfigs::p2sp(const Rectangle2Df& p) const
{
	return Rectangle2Di(p2sp(p.pos), p2sp(p.size));
}
