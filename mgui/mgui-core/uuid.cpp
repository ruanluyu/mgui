#include "pch.h"
#include "uuid.h"
#include <iomanip>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/container_hash/hash.hpp>

namespace mgui {
	size_t UUIDKey::GetHashCode() const
	{
		return boost::hash_range(raw, raw + sizeof(raw));
	}

	static void print_hex(std::stringstream& ss, const unsigned char* pos, int len)
	{
		ss << std::hex;
		for (size_t i = 0; i < len; i++)
		{
			ss << std::setw(2) << std::setfill('0');
			ss << static_cast<int>(*(pos + i));
		}
	}
	std::string UUIDKey::ToString() const
	{
		std::stringstream ss;
		int division[] = {4,2,2,2,6};
		const int division_len = sizeof(division) / sizeof(division[0]);
		size_t last_pos = 0;
		for (size_t i = 0; i < division_len; i++)
		{
			if (i > 0) ss << "-";
			auto cur_len = division[i];
			print_hex(ss, raw + last_pos, cur_len);
			last_pos += cur_len;
		}

		return ss.str();
	}
	bool UUIDKey::operator==(const UUIDKey& other) const
	{
		return memcmp(raw, other.raw, sizeof(raw)) == 0;
	}
	bool UUIDKey::operator>(const UUIDKey& other) const
	{
		return memcmp(raw, other.raw, sizeof(raw)) > 0;
	}


	UUIDKey UUIDKey::Generate()
	{
		auto buid = boost::uuids::random_generator()();
		UUIDKey res;
		assert(buid.size() == 16);
		std::copy(buid.begin(), buid.end(), res.raw);
		return res;
	}
	UUIDKey UUIDKey::GenerateZeroed()
	{
		UUIDKey key;
		memset(key.raw, sizeof(key.raw), 0);
		return key;
	}
}
