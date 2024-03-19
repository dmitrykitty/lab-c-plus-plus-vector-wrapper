#include <algorithm> // std::sort, std::find, std::copy
#include <iterator> // std::distance, std::advance, std::back_inserter
#include <limits>   // std::numeric_limits<size_t>::max()
#include <numeric>  // std::accumulate()

using namespace std;

#include "containerWrapper.h"

#warning "Metody klasy sa do zaimplementowania. Instrukcja w pliku naglowkowym i README.md" // po zaimplementowaniu sugeruje usuniecie tej linijki - nie chcemy warningow

IContainerWrapper::~IContainerWrapper() = default;
