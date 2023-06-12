#include <iostream>
#include <bitset>
#include <array>

template<int N, int M>
class BitMatrix {
    std::array<std::bitset<M>, N> matrix;

public:
    BitMatrix() {
        matrix.fill(std::bitset<M>(0));
    }

    BitMatrix(unsigned long val) {
        matrix.fill(std::bitset<M>(val));
    }

    BitMatrix(const BitMatrix<N, M>& bitmatrix) {
        matrix = bitmatrix.matrix;
    }

    BitMatrix(BitMatrix<N, M>&& bitmatrix) {
        matrix = std::move(bitmatrix.matrix);
    }

    void print() {
        for (const auto& row : matrix) {
            std::cout << row << "\n";
        }
        std::cout << std::endl;
    }

    void set() {
        for (auto& row : matrix) {
            row.set();
        }
    }

    void set(int row) {
        matrix[row].set();
    }

    void reset() {
        for (auto& row : matrix) {
            row.reset();
        }
    }

    void reset(int row) {
        matrix[row].reset();
    }

    void flip() {
        for (auto& row : matrix) {
            row.flip();
        }
    }

    void flip(int row) {
        matrix[row].flip();
    }

    bool all() {
        return std::all_of(matrix.begin(), matrix.end(),
                           [](const std::bitset<M>& row) { return row.all(); });
    }

    bool all(int row) {
        return matrix[row].all();
    }

    bool none() {
        return std::all_of(matrix.begin(), matrix.end(),
                           [](const std::bitset<M>& row) { return row.none(); });
    }

    bool none(int row) {
        return matrix[row].none();
    }

    bool any() {
        return std::any_of(matrix.begin(), matrix.end(),
                           [](const std::bitset<M>& row) { return row.any(); });
    }

    bool any(int row) {
        return matrix[row].any();
    }

    bool operator()(std::size_t row, std::size_t col) {
        return matrix[row][col];
    }

    std::bitset<M>& operator()(std::size_t row) {
        return matrix[row];
    }

    int count() {
        int sum = 0;
        for (const auto& row : matrix) {
            sum += row.count();
        }
        return sum;
    }

    int count(int row) {
        return matrix[row].count();
    }

    BitMatrix<N, M> operator^(const BitMatrix<N, M>& bm2) {
        BitMatrix<N, M> out;
        for (int i = 0; i < matrix.size(); ++i) {
            out.matrix[i] = matrix[i] ^ bm2.matrix[i];
        }
        return out;
    }

    BitMatrix<N, M> operator|(const BitMatrix<N, M>& bm2) {
        BitMatrix<N, M> out;
        for (int i = 0; i < matrix.size(); ++i) {
            out.matrix[i] = matrix[i] | bm2.matrix[i];
        }
        return out;
    }

    BitMatrix<N, M> operator&(const BitMatrix<N, M>& bm2) {
        BitMatrix<N, M> out;
        for (int i = 0; i < matrix.size(); ++i) {
            out.matrix[i] = matrix[i] & bm2.matrix[i];
        }
        return out;
    }
};

