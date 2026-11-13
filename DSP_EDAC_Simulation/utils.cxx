#include "utils.hxx"

#include <vector>
#include <cstdint>

namespace Utils
{
	// Executes XOR beetween two vectors of data type uint16_t.
	// Use return_value.empty() to check if the function was executed successfully.
	std::vector<uint16_t> XOR_uint16t_vectors(const std::vector<uint16_t> &vec_a, const std::vector<uint16_t> &vec_b)
	{
		if (vec_a.size() != vec_b.size()) return {};

		std::vector<uint16_t> result;
		for (size_t i = 0; i < vec_a.size(); i++)
		{
			result.push_back(vec_a[i] ^ vec_b[i]);
		}

		return result;
	}
}