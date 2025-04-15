#include <algorithm> // std::sort, std::find, std::copy
#include <iterator> // std::distance, std::advance, std::back_inserter
#include <limits>   // std::numeric_limits<size_t>::max()
#include <numeric>  // std::accumulate()

using namespace std;

#include "containerWrapper.h"


IContainerWrapper::~IContainerWrapper() = default;

void VectorWrapper::push_back(const value_type &num) {
    impl_.push_back(num);
}

void VectorWrapper::push_front(const value_type &num) {
    impl_.insert(impl_.begin(), num);
}

void VectorWrapper::insert(const value_type &num, std::size_t ind) {
    if (ind > std::size(impl_))
        return;
    impl_.insert(impl_.begin() + ind, num);
}

VectorWrapper::value_type &VectorWrapper::at(std::size_t index) {
    return impl_.at(index);
}

void VectorWrapper::sort() {
    ranges::sort(impl_);
}

void VectorWrapper::erase(std::size_t index) {
    if (index > std::size(impl_))
        return;
    impl_.erase(impl_.begin() + index);
}
