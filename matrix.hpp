#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <iostream>

// modify this class declaration to take a template for the type of the data it holds

template <typename T>
class Matrix {
public:
    Matrix(std::size_t N){ //constructor with input N
        // initialize an empty NxN matrix
        _N = N; //sets _N equal to N
        for (size_t i = 0; i < N; i++){ //for loop iterates from 0 to N
            std::vector<T> empty_row(N, 0); //got empty_row(N, 0) from chatGPT ~ was having issues of copying same empty_row over and over again resulting in infinite zeros
            _matrix.push_back(empty_row);  //add empty_row to _matrix
        }
    }
    Matrix(std::vector<std::vector<T> > nums){
        _N = nums.size(); //sets _N to length of nums
        for (size_t i = 0; i < _N; i++){ //for loop iterates from 0 to _N
            std::vector<T> row; //intializes row
            for (size_t j = 0; j < _N; j++){ //for loop iterates from 0 to _N
                T entry = nums[i][j]; //initializes entry as num[i][j]
                row.push_back(entry); //adds entry to row
            } 
            _matrix.push_back(row); //adds row to _matrix
        }   
    }
    Matrix<T> operator+(const Matrix<T> &rhs) const{ //matrix addition function
        Matrix<T> result(_N); //creates a matrix of 0s called result
            for (size_t i = 0; i < _N; i++){ //iterates from 0 to _N
                for (size_t j = 0; j < _N; j++){ //iterates from 0 to _N
                    result.set_value(i, j, (get_value(i, j) + rhs.get_value(i, j))); //sets value of result[i][j] equal to the value of _matrix[i][j] plus rhs[i][j]
                }
            }
            return result; //return result (addition matrix)
    }
    Matrix<T> operator*(const Matrix<T> &rhs) const{ //matrix multiplication function 
        Matrix<T> result(_N); //creates a matrix of 0s called result 
            for (size_t i = 0; i < _N; i++){ //iterates from 0 to _N
                for (size_t j = 0; j < _N; j++){ //iterates from 0 to _N
                    T result_value = 0; //result value from multiplication 
                    for (size_t z = 0; z < _N; z++){  //iterates from 0 to _N
                        result_value += get_value(i, z) * rhs.get_value(z, j);  //result_value stores multiplication of _matrix[i][z] times rhs[z][j]
                    } 
                    result.set_value(i, j, result_value); //sets value of result[i][j] equal to result_value
                } 
            }
            return result; //return result (multiplication matrix)
    }
    void set_value(std::size_t i, std::size_t j, T n){ //set value function
        _matrix[i][j] = n; //sets _matrix[i][j] to value n
    }
    T get_value(std::size_t i, std::size_t j) const{ //get value function
        return _matrix[i][j]; //returns value at _matrix[i][j]
    }
    T get_size() const{ //get size function
        return _N; //returns _N
    }
    T sum_diagonal_major() const{ //sum of diagonal major funciton
        T result = 0; //initializes result
        for (size_t i = 0; i < get_size(); i++){ //iterates from 0 to get_size()
            result = result + get_value(i, i); //result equals result plus value at _matrix[i][i] (gets values in major diagonal)
        }
        return result; //returns result 
    }
    T sum_diagonal_minor() const{ //sum of diagonal minor function
        T result = 0; //initializes result
        int row = 0; //initializes row
        for (int i = get_size() - 1; i >= 0; i--){ //iterates from get_size() - 1 to 0
            result = result + get_value(row, i); //result equals result plus value at _matrix[row][i] (gets values in minor diaognal)
            row ++; //increments row
        }
        return result; //reutrns result
    }
    void swap_rows(std::size_t r1, std::size_t r2){ //swap rows function 
        if (r1 >= 0 && r1 < get_size() && r2 >= 0 && r2 < get_size()){ //checks if inputs are within range
            T temp; //initializes temp 
            for (size_t i = 0; i < get_size(); i++){ //iterates from 0 to get_size()
                temp = get_value(r1, i); //temp is set to value at _matrix[r1][i]
                set_value(r1, i, get_value(r2, i)); //_matrix[r1][i] is set to value at _matrix[r2][i]
                set_value(r2, i, temp); //_matrix[r2][i] is set to temp
            }
        }
    }
    void swap_cols(std::size_t c1, std::size_t c2){ //swap cols function 
        if (c1 >= 0 && c1 < get_size()-1 && c2 >= 0 && c2 < get_size()-1){ //checks if inputs are within range
            T temp; //initializes temp 
            for (size_t i = 0; i < get_size(); i++){ //iterates from 0 to get_size()
                temp = get_value(i, c1); //temp is set to value at _matrix[c1][i]
                set_value(i, c1, get_value(i, c2)); //_matrix[i][c1] is set to value at _matrix[i][c2]
                set_value(i, c2, temp); //_matrix[i][c2] is set to temp
            }
        }
    }
    void print_matrix() const { //print matrix function
        // print out the matrix
        for (size_t i = 0; i < _N; i++){ //iterates from 0 to _N
            for (size_t j = 0; j < _N; j++){ //iterates from 0 to _N
                std::cout << _matrix[i][j] << " "; //prints value at _matrix[i][j]
            }
            std::cout << "\n"; //new line 
        }
    }
private: 
    std::vector<std::vector<T> > _matrix; //a vector of vectors containing ints called _matrix 
    std::size_t _N; //int variable containing size of matrix in _n
};

#endif // __MATRIX_HPP__
