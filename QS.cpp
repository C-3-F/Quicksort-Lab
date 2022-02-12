#include "QS.h"

QS::QS()
{
  arr = nullptr;
}

QS::~QS()
{
  clear();
}
void QS::sortAll()
{
  recurse(0, insertIndex - 1);
}

int QS::medianOfThree(int left, int right)
{
  if (right < 0 || left < 0 || right > arrSize - 1 || left > arrSize - 1 || right >= insertIndex || left >= insertIndex)
  {
    return -1;
  }
  if (left >= right)
  {
    return -1;
  }

  int middle = (left + right) / 2;

  for (int i = 0; i < 2; i++)
  {
    if (arr[left] > arr[middle])
    {
      swap(left, middle);
    }
    if (arr[middle] > arr[right])
    {
      swap(middle, right);
    }
  }

  return middle;
}

int QS::partition(int left, int right, int pivotIndex)
{
  // cout << "Pivot: " << arr[pivotIndex] << endl;
  if (right < 0 || left < 0 || right > arrSize - 1 || left > arrSize - 1 || right >= insertIndex || left >= insertIndex || left == right)
  {
    return -1;
  }
  if (right - left == 1)
  {
    return -1;
  }
  int up = left + 1;
  int down = right;
  swap(pivotIndex, left);
  do
  {
    cout << getArray() << endl;
    while (arr[up] <= arr[left] && up < right)
    {
      up++;
    }
    while (arr[down] > arr[left] && down > left)
    {
      down--;
    }
    if (up < down)
    {
      swap(down, up);
    }
  } while (up < down);
  swap(down, left);
  return down;
}

string QS::getArray() const
{
  if (arr)
  {

    string out = "";
    for (int i = 0; i < insertIndex; i++)
    {
      out += to_string(arr[i]);
      if (i != insertIndex - 1)
      {
        out += ",";
      }
    }
    return out;
  }
  else
  {
    return "";
  }
}

int QS::getSize() const
{
  return insertIndex;
}

bool QS::addToArray(int value)
{
  if (insertIndex < arrSize && arr)
  {
    arr[insertIndex] = value;
    insertIndex++;
    return true;
  }
  else
  {
    return false;
  }
}

bool QS::createArray(int capacity)
{
  if (capacity <= 0)
  {
    return false;
  }
  else
  {
    if (arr != nullptr)
    {
      clear();
    }
    insertIndex = 0;
    arrSize = capacity;
    arr = new int[capacity];
    return true;
  }
}

void QS::clear()
{
  arr = nullptr;
  delete[] arr;
  arrSize = 0;
  insertIndex = 0;
}

void QS::swap(int ind1, int ind2)
{
  int temp = arr[ind1];
  arr[ind1] = arr[ind2];
  arr[ind2] = temp;
}

void QS::recurse(int left, int right)
{
  int pivot = medianOfThree(left, right);
  if (pivot == -1)
  {
    return;
  }
  if (right - left <= 1)
  {
    return;
  }
  cout << getArray() << endl;
  int endIndex = partition(left, right, pivot);
  cout << getArray() << endl;
  //  Left
  recurse(left, endIndex - 1);
  // Right
  recurse(endIndex + 1, right);
  return;
}