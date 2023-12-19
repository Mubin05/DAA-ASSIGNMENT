def print_mat(m):
  for i in m:
    print(i)

def matrix_chain_mul(p):
  n=len(p)-1
  mat_val=999999
  m=[[0 for x in range(n)]for x in range(n)]
  s=[[0 for x in range(n)]for x in range(n)]
  for i in range(0,n):
    j = i
    m[i][j]=0
  for L in range(2,n+1):
    for i in range(0,n-L+1):
      j=i+L-1
      max_val = float('inf')
      m[i][j]=max_val
      for k in range(i,j):
        q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1]
        if q<m[i][j]:
          m[i][j]=q
          s[i][j]=k
  mp=[[m[i][j] for i in range(0,n)]]
  for l in range(1,n):
    temp=[m[i][i+l] for i in range(0,n-l)]
    mp.append(temp)
  print("\n Matrix M:")
  print_mat(mp)
  sp=[]
  for l in range(1,n):
    temp=[[s[i][i+l] for i in range(0,n-l)]]
    sp.append(temp)
  print("\n Matrix S:")
  print_mat(sp)
  return m[0][n-1]
n1=int(input("Enter the no of dims:"))
p=[]
print("Enter dims")
for i in range(n1):
  l1=int(input())
  p.append(l1)
print("The dim array:",p)
result=matrix_chain_mul(p)
print("result:",result)
