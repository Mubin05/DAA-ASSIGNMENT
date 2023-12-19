def print_all_subsequences(X, Y, C):
  m = len(X)
  n = len(Y)

  all_subsequences = set()
  LCS = [''] * (C[m][n] + 1)

  def find_all_subsequences(i, j, id):
      nonlocal LCS
      if i == 0 or j == 0:
          all_subsequences.add(''.join(LCS[id:]))
          return
      if X[i - 1] == Y[j - 1]:
          LCS[id - 1] = X[i - 1]
          find_all_subsequences(i - 1, j - 1, id - 1)
      if C[i - 1][j] >= C[i][j - 1]:
          find_all_subsequences(i - 1, j, id)
      if C[i][j - 1] >= C[i - 1][j]:
          find_all_subsequences(i, j - 1, id)

  find_all_subsequences(m, n, C[m][n])
  filtered_subsequences = [i for i in all_subsequences if len(i) == 4]
  print("All LCS sequences:", filtered_subsequences)
  print("Length of LCS is",C[m][n])
X = input("Enter the 1st string: ")
print("1st string:", X)
Y = input("Enter the 2nd string: ")
print("2nd string:", Y)
m = len(X)
n = len(Y)
C = [[0] * (n + 1) for _ in range(m + 1)]
for i in range(1, m + 1):
  for j in range(1, n + 1):
      if X[i - 1] == Y[j - 1]:
          C[i][j] = C[i - 1][j - 1] + 1
      else:
          C[i][j] = max(C[i - 1][j], C[i][j - 1])

print("The matrix is below:")
for i in range(m + 1):
  for j in range(n + 1):
      print(C[i][j], end=" ")
  print()
print()
print_all_subsequences(X,Y,C)