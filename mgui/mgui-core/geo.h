#pragma once

#include "screen.h"

using namespace mgui::screen;

namespace mgui{

	namespace geo {
		template<class dataT>
		struct Vector2D {
			dataT x, y;
			Vector2D() :x(), y() {}
			Vector2D(dataT x, dataT y) : x(x), y(y) {}
		};

		template<class T>
		using Size2D = Vector2D<T>;

		template<class T>
		using Position2D = Vector2D<T>;

		using Size2Dpx = Size2D<PixelLocT>;
		using Size2Dpt = Size2D<PointLocT>;

		using Position2Dpx = Position2D<PixelLocT>;
		using Position2Dpt = Position2D<PointLocT>;

		template<class T>
		struct Rectangle2D
		{
		private:
			inline static T _inner_min(T l, T r) {
				return l < r ? l : r;
			}

			inline static T _inner_max(T l, T r) {
				return l > r ? l : r;
			}

		public:
			using pointT = Position2D<T>;
			using sizeT = Size2D<T>;
			using valueT = T;

			pointT pos;
			sizeT size;

			

			Rectangle2D(pointT p = pointT(), sizeT s = sizeT()) : pos(p), size(s) {

			}


			T minX() const { return pos.x; }
			T minY() const { return pos.y; }
			T maxX() const { return pos.x + size.x; }
			T maxY() const { return pos.y + size.y; }

			static Rectangle2D<T> Empty(pointT p = pointT(0, 0))
			{
				return Rectangle2D<T>(p, sizeT(0, 0));
			}

			static Rectangle2D<T> IntersectionOf(const Rectangle2D<T>& a, const Rectangle2D<T>& b)
			{
				assert(a.size.x >= 0);
				assert(a.size.y >= 0);
				assert(b.size.x >= 0);
				assert(b.size.y >= 0);

				Rectangle2D<T> res;
				res.pos.x = _inner_max(a.pos.x, b.pos.x);
				res.pos.y = _inner_max(a.pos.y, b.pos.y);

				res.size.x = _inner_min(a.pos.x + a.size.x, b.pos.x + b.size.x) - res.pos.x;
				res.size.y = _inner_min(a.pos.y + a.size.y, b.pos.y + b.size.y) - res.pos.y;

				return res;
			}

			static Rectangle2D<T> UnionOf(const Rectangle2D<T>& a, const Rectangle2D<T>& b)
			{
				assert(a.size.x >= 0);
				assert(a.size.y >= 0);
				assert(b.size.x >= 0);
				assert(b.size.y >= 0);

				Rectangle2D<T> res;
				res.pos.x = _inner_min(a.pos.x, b.pos.x);
				res.pos.y = _inner_min(a.pos.y, b.pos.y);

				res.size.x = _inner_max(a.pos.x + a.size.x, b.pos.x + b.size.x) - res.pos.x;
				res.size.y = _inner_max(a.pos.y + a.size.y, b.pos.y + b.size.y) - res.pos.y;

				return res;
			}


			static Rectangle2D<T> FromMinMax(const T& minXInclusive, const T& minYInclusive, const T& maxXExclusive, const T& maxYExclusive) {
				assert(maxXExclusive >= minXInclusive);
				assert(maxYExclusive >= minYInclusive);
				return Rectangle2D<T>(pointT(minXInclusive, minYInclusive), sizeT(maxXExclusive - minXInclusive, maxYExclusive - minYInclusive));
			}

			static Rectangle2D<T> FromMinMax(const pointT& minInclusive, const pointT& maxExclusive) {
				assert(maxExclusive.x >= minInclusive.x);
				assert(maxExclusive.y >= minInclusive.y);
				return Rectangle2D<T>(pointT(minInclusive.x, minInclusive.y), sizeT(maxExclusive.x - minInclusive.x, maxExclusive.y - minInclusive.y));
			}

			static Rectangle2D<T> FromPosSize(const T& posX, const T& posY, const T& sizeX, const T& sizeY) {
				return Rectangle2D<T>(pointT(posX, posY), sizeT(sizeX, sizeY));
			}

			static Rectangle2D<T> FromPosSize(const pointT& p, const sizeT& s) {
				return Rectangle2D<T>(p, s);
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


			static Rectangle2D<T> Expand(const Rectangle2D<T>& rect, const T& expand)
			{
				return FromMinMax(
					rect.minX() - expand,
					rect.minY() - expand,
					rect.maxX() + expand,
					rect.maxY() + expand
				);
			}

		};

		using Rectangle2Dpx = Rectangle2D<PixelLocT>;
		using Rectangle2Dpt = Rectangle2D<PointLocT>;



		namespace utils {
			Rectangle2Dpx ExpandRectangle(const Rectangle2Dpt rectPt);
			Rectangle2Dpx ShrinkRectangle(const Rectangle2Dpt rectPt);
		}

	}


}