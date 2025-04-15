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

VectorWrapper::value_type VectorWrapper::count() const {
    value_type result = 0;
    for (const auto &element: impl_)
        result += element;
    return result;
}

std::size_t VectorWrapper::find(const value_type &element) const {
    for (std::size_t i = 0; i < std::size(impl_); ++i)
        if (element == impl_.at(i)) {
            return i;
        }
    return SIZE_MAX;
}

VectorWrapper::value_type VectorWrapper::pop_front() {
    value_type result = impl_.front();
    impl_.erase(impl_.begin());
    return result;
}


VectorWrapper::value_type VectorWrapper::pop_back() {
    value_type result = impl_.back();
    impl_.pop_back();
    return result;
}
