//
//  main.cpp
//  TCP Echo Project
//
//  Created by 김수민 on 2022/10/30.
//

#include <boost/range/adaptor/adjacent_filtered.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/assign.hpp>
#include <iterator>
#include <functional>
#include <openssl/aes.h>
#include <iostream>
#include <vector>

int main(int argc, const char* argv[])
{
    using namespace boost::assign;
    using namespace boost::adaptors;

    std::vector<int> input;
    input += 1,1,2,2,2,3,4,5,6;

    boost::copy(
        input | adjacent_filtered(std::not_equal_to<int>()),
        std::ostream_iterator<int>(std::cout, ","));

    return 0;
}
