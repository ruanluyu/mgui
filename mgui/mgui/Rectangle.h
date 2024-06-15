#pragma once
#include "assert.h"

#include "mathhelper.cpp"
#include "Point.h"
#include "Size.h"

namespace mgui {
	template<class pointT, class sizeT>
	struct Rectangle2D
	{
		pointT pos;
		sizeT size;

		Rectangle2D(pointT p = pointT(0,0), sizeT s = sizeT(0, 0)) : pos(p), size(s) {

		}


		static Rectangle2D<pointT, sizeT> Empty(pointT p = pointT(0,0))
		{
			return Rectangle2D<pointT, sizeT>(p, sizeT(0, 0));
		}

		static Rectangle2D<pointT, sizeT> IntersectionOf(const Rectangle2D<pointT, sizeT>& a, const Rectangle2D<pointT, sizeT>& b)
		{
			assert(a.size.x >= 0);
			assert(a.size.y >= 0);
			assert(b.size.x >= 0);
			assert(b.size.y >= 0);

			Rectangle2D<pointT, sizeT> res;
			res.pos.x = max(a.pos.x, b.pos.x);
			res.pos.y = max(a.pos.y, b.pos.y);

			res.size.x = min(a.pos.x + a.size.x, b.pos.x + b.size.x) - res.pos.x;
			res.size.y = min(a.pos.y + a.size.y, b.pos.y + b.size.y) - res.pos.y;

			return res;
		}

		static Rectangle2D<pointT, sizeT> UnionOf(const Rectangle2D<pointT, sizeT>& a, const Rectangle2D<pointT, sizeT>& b)
		{
			assert(a.size.x >= 0);
			assert(a.size.y >= 0);
			assert(b.size.x >= 0);
			assert(b.size.y >= 0);

			Rectangle2D<pointT, sizeT> res;
			res.pos.x = min(a.pos.x, b.pos.x);
			res.pos.y = min(a.pos.y, b.pos.y);

			res.size.x = max(a.pos.x + a.size.x, b.pos.x + b.size.x) - res.pos.x;
			res.size.y = max(a.pos.y + a.size.y, b.pos.y + b.size.y) - res.pos.y;

			return res;
		}

		void Formalize()
		{
			if (size.x < 0) {
				pos.x += size.x;
				size.x = -size.x;
			}

			if (size.y < 0) {
				pos.y += size.y;
				size.y = -size.y;
			}
		}

		bool IsEmpty() const
		{
			return size.x == 0 || size.y == 0;
		}


	};

	using Rectangle2Di = Rectangle2D<Point2Di, Size2Di>;
	using Rectangle2Df = Rectangle2D<Point2Df, Size2Df>;
}

