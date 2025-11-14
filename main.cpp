#include <iostream>
#include <vector>
#include <utility>
#include "matrix.h"
#include "nn.h"
#include "mnist.h"

int main()
{
  const int TRAINING_IMAGE_COUNT = 10000;
  const int TEST_IMAGE_COUNT = 400;

  // vector of pairs,first element is a 784x1 Matrix with normalized greyscale image data, second element is a 10x1 Matrix with a 1 in the row indicating the correct label
  std::vector<std::pair<Matrix, Matrix>> training_data = load_mnist_images
  ("data/train-images.idx3-ubyte","data/train-labels.idx1-ubyte", TRAINING_IMAGE_COUNT);

  // vector of pairs,first element is a 784x1 Matrix with normalized greyscale image data, second element is a 10x1 Matrix with a 1 in the row indicating the correct label
  std::vector<std::pair<Matrix, Matrix>> test_data = load_mnist_images
  ("data/t10k-images.idx3-ubyte","data/t10k-labels.idx1-ubyte", TEST_IMAGE_COUNT);

  NN network({784, 30, 10});
  network.train(training_data, 40, 64, 0.5, test_data);
  double accuracy = network.test(test_data);
  std::cout << "Test Accuracy: " << accuracy << "%\n";
}