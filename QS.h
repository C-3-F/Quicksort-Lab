#include "QSInterface.h"

class QS : public QSInterface
{
private:
  int *arr;
  int arrSize;
  int insertIndex = 0;

public:
  QS();
  ~QS();
  void sortAll();
  void recurse(int left, int right);
  void swap(int ind1, int ind2);
  int medianOfThree(int left, int right);
  int partition(int left, int right, int pivotIndex);
  string getArray() const;
  int getSize() const;
  bool addToArray(int value);
  bool createArray(int capacity);
  void clear();
};