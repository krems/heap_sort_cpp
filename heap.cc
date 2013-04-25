// Author: krems

#include <vector>
#include <stdlib.h>
#include <iostream>

using std::vector;

template <typename T>
class Heap {
  vector<T> _data;
 public:
  Heap() {}
  template <size_t N>
  explicit Heap(T (&data)[N]) {
    makeHeap<N>(data);
  }
  explicit Heap(const vector<T>& data) {
    makeHeap(data);
  }

  void makeHeap(vector<T> data) {
    _data = data;
    for (int i = _data.size(); i >= 0; --i) {
      heapify(i);
    }
  }

  template<size_t N>
  void makeHeap(T (&data)[N]) {
    _data = vector<T>(data, data + N);
    for (int i = _data.size(); i >= 0; --i) {
      heapify(i);
    }
  }

  const T& peek() const {
    return _data[0];
  }

  void add(const T& element) {
    _data.push_back(element);
    size_t el_position = _data.size() - 1;
    size_t parent_position = (el_position - 1) / 2;
    while (_data[parent_position] < _data[el_position] && el_position > 0) {
      std::swap(_data[parent_position], _data[el_position]);
      el_position = parent_position;
      parent_position = (el_position - 1) / 2;
    }
  }

  T pop() {
    T tmp = _data[0];
    _data[0] = *(_data.end() - 1);
    _data.pop_back();
    heapify(0);
    return tmp;
  }
  
  ~Heap() {}

 private:
  void heapify(size_t vertex) {
    size_t left = 2 * vertex + 1;
    size_t right = 2 * vertex + 2;
    if (left >= _data.size() || right >= _data.size()) {
      return;
    }
    if (_data[vertex] < _data[left] || _data[vertex] < _data[right]) {
      size_t max_child_position = left;
      if (_data[left] < _data[right]) {
        max_child_position = right;
      }
      std::swap(_data[vertex], _data[max_child_position]);
      heapify(max_child_position);
    }
  }
};

template <typename T, size_t N>
void heapSort(T (&array)[N]) {
  if (N == 0) {
    return;
  }
  Heap<T> heap(array);
  for (int i = N - 1; i >= 0; --i) {
    array[i] = heap.pop();
  }
}

template <typename T>
void heapSort(vector<T>& array) {
  if (array.size() == 0) {
    return;
  }
  Heap<T> heap(array);
  for (int i = array.size() - 1; i >= 0; --i) {
    array[i] = heap.pop();
  }
}

int main() {
  vector<int> arr {9, 8, 10, 99, 100, 0};
  for (auto i = 0; i < 6; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  heapSort(arr);
  for (auto i = 0; i < 6; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  
  int array[] = {9, 8, 10, 99, 100, 0};
  for (auto i = 0; i < 6; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
  heapSort(array);
  for (auto i = 0; i < 6; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}
