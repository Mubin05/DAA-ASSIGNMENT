#import mul for large dim
import numpy as np


def split(mat):
  r, c = mat.shape
  r2, c2 = r // 2, c // 2
  return mat[:r2, :c2], mat[:r2, c2:], mat[r2:, :c2], mat[r2:, c2:]


def mm(A, B):
  if len(A) == 1:
    return A * B
  a, b, c, d = split(A)
  e, f, g, h = split(B)
  c11 = mm(a, e) + mm(b, g)
  c12 = mm(a, f) + mm(b, h)
  c21 = mm(c, e) + mm(d, g)
  c22 = mm(c, f) + mm(d, h)
  c = np.vstack([np.hstack([c11, c12]), np.hstack([c21, c22])])
  return c


def printf(mat):
  r, c = mat.shape
  for i in range(c):
    for j in range(c):
      print(mat[i, j], end=' ')
    print()
  print()


def readmat():
  r = int(input("Enter the number of rows:"))
  c = int(input("Enter the number of columns"))
  print("Enter the matrix elements")
  elems = list(map(int, input().split()))
  mat = np.array(elems).reshape(r, c)
  print(mat)
  return mat


A = readmat()
B = readmat()
print("The resultant matrix is:")
C = mm(A, B)
printf(C)
