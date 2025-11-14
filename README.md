# Neural Network from Scratch in C++
## Overview
This repository contains my ongoing implementation of a feed-forward neural network based on the book "Neural Networks and Deep Learning" by Michael Nielsen. In its simplest form, the NN is able to classify handwritten digits taken from the MNIST dataset with accuracies of >90% after being trained with backpropagation.
## Motivation
I started this project to understand the inner workings of neural networks, including backpropagation and gradient descent, by building one from scratch.
## Features
The project includes a Matrix class that supports the following operations:

- matrix multiplication
- elementwise operations: addition, subtraction, Hadamard product
- scalar operations: multiplication, addition, subtraction
- vector addition (row- or column-wise)
- transpose

Furthermore, it includes an MNIST-loader function capable of:

- reading image and label files
- converting read data into Matrix objects
- catching incompatible image/label counts before their use in NN training

The Neural Network class implements:

- the creation of valid neural networks with specified layer and neuron counts
- the feed-forward process of inputs to produce predictions
- updating weights and biases using backpropagation and stochastic gradient descent

## Skills and Learnings
This project taught me a lot of new things including:

- matrix operations
- the architecture of neural networks
- the mathematics of gradient descent and backpropagation
- the importance of efficient error handling and verification of small code blocks / functions

## Implementation Details
### Matrix class
#### Structure
The matrix class is implemented as a two-dimensional vector of double values. Matrices must have a valid row and column count and contain their own dimensions as separate variables for ease of use.
#### Constructors
- initializer list
- const reference to another Matrix object
- row and column count
#### Methods for interaction
- formatted printing of matrix and dimensions
- getting/setting individual values
- extraction of certain column
#### Helper functions
- validation of matrix dimensions
- dot product for use in multiplication

### Neural Network class
#### Structure
The neural network class contains a layer count, vector of neuron counts per layer and vectors of matrices for weights and biases. The minimum layer count is 2.
#### Constructor
- vector of neuron counts, biases are zero-initialized; weights are drawn from normal distribution to avoid symmetry
#### Helper functions
- validation of layer count on creation
- application of sigmoid and its derivative
#### Functionality
Training the neural network works by:
1. Generating random batches of data of a specified batch size.
2. Calculating the gradients of weights and biases using backpropagation.
3. Changing the network parameters with gradient descent based on the calculated gradients.
4. Evaluating performance on the test images every epoch and printing current accuracy

## Getting started
### Prerequisites
- C++17 compatible compiler
- Standard C++ Library
- MNIST Dataset:
https://www.kaggle.com/datasets/hojjatk/mnist-dataset

### How to build
```bash
g++ main.cpp matrix.cpp nn.cpp -o nn
```

### Usage
To use the project, define a neural network in your desired main.cpp file, train it using MNIST data and check the output! Make sure to download the dataset first and correctly link your files like so:
```
std::vector<std::pair<Matrix, Matrix>> data = load_mnist_images(img_path, label_path)
```
#### Example:
```cpp
#include <iostream>
#include <vector>
#include <utility>
#include "matrix.h"
#include "nn.h"
#include "mnist.h"
int main()
{
  const int TRAINING_IMAGE_COUNT = 1000;
  const int TEST_IMAGE_COUNT = 50;

  std::vector<std::pair<Matrix, Matrix>> training_data = load_mnist_images
  ("data/train-images.idx3-ubyte","data/train-labels.idx1-ubyte", TRAINING_IMAGE_COUNT);

  std::vector<std::pair<Matrix, Matrix>> test_data = load_mnist_images
  ("data/t10k-images.idx3-ubyte","data/t10k-labels.idx1-ubyte", TEST_IMAGE_COUNT);

  NN network({784, 30, 10});
  network.train(training_data, 30, 10, 1.0, test_data);

  double accuracy = network.test(test_data);
  std::cout << "Test Accuracy: " << accuracy << "%\n";
}
```
#### Training output:
```
Training started!
Epoch 0: Accuracy: 12%
Epoch 1: Accuracy: 22%
Epoch 2: Accuracy: 44%
Epoch 3: Accuracy: 58%
Epoch 4: Accuracy: 70%
Epoch 5: Accuracy: 78%
Epoch 6: Accuracy: 76%
Epoch 7: Accuracy: 86%
Epoch 8: Accuracy: 84%
Epoch 9: Accuracy: 82%
```