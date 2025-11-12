# Neural Network from Scratch in C++
## Overview
This repository contains my ongoing implementation of a feed-forward neural network based on the book "Neural Networks and Deep Learning" by Michael Nielsen. In its simplest form, the NN is able to classify handwritten digits taken from the MNIST dataset with accuracies of >90% after being trained with backpropagation.
## Motivation
I started this project to understand neural networks and the underlying mathematics more deeply as I have always been fascinated by Machine Learning. Practicing my skills with a very interesting topic was most important.

## Features
The project includes a Matrix class that supports the following operations:

- matrix multiplication,
- in-place addition and subtraction of matrices,
- in-place vector addition,
- in-place elementwise subtraction and multiplication using scalar values,
- elementwise product (Hadamard)
- transposition
- dot product (of column vectors)

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
There are three constructors. One takes in row and column counts, initializing the matrix to all zeros. The second one takes in a const reference to a two-dimensional vector to convert it into a matrix object. The third constructor enables use of an initializer list.
#### Methods for interaction
The class supports nicely formatted printing for usual (up to 2-digit) values and getter/setter for column and row count. These variables could have been made public, but I did not want to expose internal naming. Printing of dimensions and extraction of a certain column are also supported.
#### Helper methods
To simplify the matrix multiplication logic, the implementation file contains a dot function in an anonymous namespace.
#### Operations
The class implements the default cubic time complexity multiplication algorithm with a dimension compatibility check. Addition and subtraction as well as scalar operations, hadamard and vector addition are implemented as well. One important method is transpose() which returns a transposed version of the object for ease of use. Lastly, set() and get() can be used to change and retrieve values without knowing the underlying implementation logic.

Note: This README is a work in progress and will be updated shortly.