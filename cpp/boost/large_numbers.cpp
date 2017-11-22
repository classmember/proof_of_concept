#include <iostream>
#include <iomanip>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>

using boost::multiprecision::cpp_dec_float_50;

template<typename T>
inline T area_of_a_circle(T r)
{
   using boost::math::constants::pi;
   return pi<T>() * r * r;
}

template<typename T>
inline T times_100(T r)
{
   return 100 * r;
}

template<typename T>
inline T times_alot(T r)
{
    for(int i = 0;i<24;i++) {
        r = times_100(r);
    }
    return r;
}


int main(int, char**) {
	const cpp_dec_float_50 radius(cpp_dec_float_50(123) / 100);
    const cpp_dec_float_50 area = area_of_a_circle(radius); 

	// 4.7529155256159981904701331745635599135018975843146
    std::cout
		<< std::setprecision(std::numeric_limits<cpp_dec_float_50>::digits10)
		<< area
		<< std::endl;

	// 475.29155256159981904701331745635599135018975843146
    std::cout
		<< std::setprecision(std::numeric_limits<cpp_dec_float_50>::digits10)
		<< times_100(area)
		<< std::endl;

	// 4752915525615998190470133174563559913501897584314.6
    std::cout
		<< std::setprecision(std::numeric_limits<cpp_dec_float_50>::digits10)
		<< times_alot(area)
		<< std::endl;
}
