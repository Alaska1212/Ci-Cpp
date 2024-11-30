#include <iostream>
#include <vector>
#include <iterator>
#include <functional>


template <typename InputIt, typename OutputIt, typename UnaryPredicate, typename UnaryOperation>
OutputIt transform_if(InputIt first, InputIt last, OutputIt d_first, UnaryPredicate pred, UnaryOperation op) {
    while (first != last) {
        if (pred(*first)) {
            *d_first = op(*first);
            ++d_first;
        }
        ++first;
    }
    return d_first;
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> output;

    auto is_even = [](int x) { return x % 2 == 0; };

    auto multiply_by_two = [](int x) { return x * 2; };

    output.resize(input.size());

    auto new_end = transform_if(input.begin(), input.end(), output.begin(), is_even, multiply_by_two);

    output.erase(new_end, output.end());

    std::cout << "Result: ";
    for (const auto& val : output) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
