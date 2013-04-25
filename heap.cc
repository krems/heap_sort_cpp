// Author: krems

#include <vector>

template <typename T>
class Heap {
  using std::vector;
  vector<T> _data;
 public:
  Heap() {}
  explicit Heap(T[] data) {
    makeHeap(data);
  }
  explicit Heap(const vector<T>& data) {
    makeHeap(data);
  }

  void makeHeap(vector<T> data) {
    _data = data;
    heapify(0);
  }
  
  void makeHeap(T[] data) {
    _data(std::begin(data), std::end(data));
    for (size_t i = 0 ; i < _data.size(); ++i) {
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
    _data.erase(_data.cend() - 1);
    heapify(0);
    return tmp;
  }
  
  ~Heap() {}

 private:
  void heapify(size_t vertex) {
    size_t left = 2 * vertex + 1;
    size_t right = 2 * vertex + 2;
    if (left >= _data.size() || right >= data.size()) {
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

template <typename T>
void heapSort(T* array) {
  size_t length = std::end(array) -  std::begin(array);
  if (length == 0) {
    return;
  }
  Heap heap(array);
  for (size_t i = length - 1; i >= 0; --i) {
    array[i] = heap.pop();
  }
}

template <typename T>
void heapSort(vector<T>& array) {
  if (array.size() == 0) {
    return;
  }
  Heap heap(array);
  for (size_t i = array.size() - 1; i >= 0; --i) {
    array[i] = heap.pop();
  }
}
