#include <iostream>

#include <boost/date_time.hpp>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

void dateExample() {
    using namespace boost::gregorian;
	date firstEarthDay( 1970, Apr, 22);
	date sputnikFirstOrbit( 1957, Oct, 4);
	date berlinWallFell( 1989, Nov, 10);

    date today = day_clock::local_day();
    std::cout << today << std::endl;
} // end dateEx()

int main()
{
    // output dates
	dateExample();

    //output uuids
    boost::uuids::random_generator generator;
    boost::uuids::uuid uuid1 = generator();
    std::cout << uuid1 << std::endl;
    boost::uuids::uuid uuid2 = generator();
    std::cout << uuid2 << std::endl;

    return 0;
}
