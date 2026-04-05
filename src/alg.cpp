// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int kolvo = 0;
  for (int i = 0; i < len; i++) {
    for (int k = i + 1; k < len; k++) {
      if ((arr[i] + arr[k]) == value)
        kolvo += 1;
      }
    }
  return kolvo;
}
int countPairs2(int *arr, int len, int value) {
  int start = 0, end = len - 1, kolvo = 0;
  while (start < end) {
    int summa = arr[start] + arr[end];
    if (summa == value) {
      if (arr[start] == arr[end]) {
        int count = end - start + 1;
        kolvo += count * (count - 1) / 2;
        break;
      } else {
        int startVal = arr[start];
        int startCount = 0;
        while (start <= end && arr[start] == startVal) {
          startCount++;
          start++;
        }
        int endVal = arr[end];
        int endCount = 0;
        while (start <= end && arr[end] == endVal) {
          endCount++;
          end--;
        }
        kolvo += startCount * endCount;
      }
    } else if (summa > value) {
      end--;
    } else {
      start++;
    }
  }
  return kolvo;
}
int countPairs3(int *arr, int len, int value) {
  int kolvo = 0;
  for (int i = 0; i < len - 1; i++) {
    int search = value - arr[i];
    int start = i + 1, end = len - 1;
    int id1 = -1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (arr[mid] == search) {
        id1 = mid;
        end = mid - 1;
        } else if (arr[mid] < search) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    if (id1 != -1) {
      start = id1;
      end = len - 1;
      int id2 = id1;
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == search) {
          id2 = mid;
          start = mid + 1;
        } else if (arr[mid] < search) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
      kolvo += (id2 - id1 + 1);
    }
  }
  return kolvo;
}
