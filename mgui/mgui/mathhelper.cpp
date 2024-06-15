
namespace mgui {
	constexpr int max(int x, int y) {
		return x > y ? x : y;
	}
	constexpr float max(float x, float y) {
		return x > y ? x : y;
	}

	constexpr int min(int x, int y) {
		return x <  y ? x : y;
	}

	constexpr float min(float x, float y) {
		return x < y ? x : y;
	}
}