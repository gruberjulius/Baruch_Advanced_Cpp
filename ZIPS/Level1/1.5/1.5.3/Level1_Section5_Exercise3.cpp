#include <iostream>
#include <tuple>
#include <vector>
#include <numeric>
#include <algorithm>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

template <typename T, typename Container, typename Tuple, std::size_t N>
struct Statistics
{
	static Tuple calculate(const Container& data) {
		if (data.empty()) {
			Tuple zeroes{ std::make_tuple(0, 0, 0, 0, 0) };
			return zeroes;
		}

		T mean{ std::accumulate(data.begin(), data.end(), 0) / static_cast<T>(N) };
		Container absDeviations(data.size());
		std::transform(data.begin(), data.end(), absDeviations.begin(),
			[=](T value) {
				if (value > mean) {
					return value - mean;
				}
				else {
					return mean - value;
				}
			});

		T meanDeviation{ std::accumulate(absDeviations.begin(), absDeviations.end(), 0) / static_cast<T>(N) };
		T range{ *std::max_element(data.begin(), data.end()) - *std::min_element(data.begin(), data.end()) };
		T variance{ std::inner_product(absDeviations.begin(), absDeviations.end(), absDeviations.begin(), 0) / static_cast<T>(N) };
		T standardDeviation{ std::sqrt(variance) };

		return std::make_tuple(mean, meanDeviation, range, variance, standardDeviation);
	}
};

template <typename T, typename Container, typename Tuple, std::size_t N>
struct Distribution {
	static Tuple calculate(const Container& data) {
		if (data.empty()) {
			Tuple zeroes{ std::make_tuple(0, 0) };
			return zeroes;
		}

		Container sortedData = data;
		std::sort(sortedData.begin(), sortedData.end());

		T median;
		if (static_cast<int>(N) % 2 != 0) {
			median = sortedData[static_cast<int>(N) / 2];
		}
		else {
			median = static_cast<T>((sortedData[(static_cast<int>(N) - 1) / 2] + sortedData[static_cast<int>(N) / 2]) / 2.0);
		}

		T best = sortedData[0];
		int bestCount = 1;
		T current = sortedData[0];
		int count = 1;

		for (int i = 1; i < N; ++i) {
			if (sortedData[i] == current) {
				++count;
			}
			else {
				if (count > bestCount) {
					best = current;
					bestCount = count;
				}
				current = sortedData[i];
				count = 1;
			}
		}

		T mode = best;
		return std::make_tuple(median, mode);
	}
};

int main() {
	using TupleResult = std::tuple<double, double, double, double, double>;
	std::vector<double> data{ 0, 1, 2, 3, 4 };
	TupleResult results{ Statistics<double, std::vector<double>, TupleResult, 5>::calculate(data) };
	std::cout << "Using std::vector: " << std::get<0>(results) << ", " << 
        std::get<1>(results) << ", " << std::get<2>(results) << ", " << std::get<3>(results) 
            << ", " << std::get<4>(results) << std::endl;

	boost::numeric::ublas::vector<double> data2(5);
	for (int i = 0; i < data2.size(); ++i) {
		data2[i] = static_cast<double>(i);
	}

	TupleResult results2{ Statistics<double, boost::numeric::ublas::vector<double>, TupleResult, 5>::calculate(data2) };
	std::cout << "Using boost::numeric::ublas::vector: " << std::get<0>(results2) << ", " 
            << std::get<1>(results2) << ", " << std::get<2>(results2) << ", " << 
                std::get<3>(results2) << ", " << std::get<4>(results2) << std::endl;

	// Part c
	using TupleMM = std::tuple<int, int>;
	std::vector<int> data3{ 23, 24, 29, 18, 17, 28, 23, 33, 31, 25 };
	TupleMM results3{ Distribution<int, std::vector<int>, TupleMM, 13>::calculate(data3) };
	std::cout << "Using std::vector: " << std::get<0>(results3) << ", " << std::get<1>(results3) << std::endl;

	boost::numeric::ublas::vector<int> data4(13);
	for (int i = 0; i < data4.size(); ++i) {
		data4[i] = data3[i];
	}

	TupleMM results4{ Distribution<int, boost::numeric::ublas::vector<int>, TupleMM, 13>::calculate(data4) };
	std::cout << "Using boost::numeric::ublas::vector: " << std::get<0>(results4) << ", " << std::get<1>(results4) << std::endl;

	return 0;
}

