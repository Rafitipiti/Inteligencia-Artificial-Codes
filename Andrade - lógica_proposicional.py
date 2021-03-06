# -*- coding: utf-8 -*-
"""Lógica Proposicional.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/14DwARwbiHfwpEZA1_3P0swO-D8y7Q08b
"""

def conjuncion(p,q):
  z = (p and q)
  return z

def disyuncion(p,q):
  z = (p or q)
  return z

def negacion(p):
  z = not p
  return z

def implicacion(p,q):
  if p == False:
    z = True
  else:
    z = q
  return z

def bicondicional(p,q):
  z = conjuncion(implicacion(p,q),implicacion(q,p))
  return z

if __name__ == '__main__':
  datos = []
  P = [False, True]
  Q = [False, True]
  for Pval in P:
    for Qval in Q:
      lista = []
      lista.append(Pval)
      lista.append(Qval)
      datos.append(lista)
  for (P,Q) in datos:
    r1 = negacion(P)
    r2 = conjuncion(P,Q)
    r3 = disyuncion(P,Q)
    r4 = implicacion(P,Q)
    r5 = bicondicional(P,Q)
    print(P," ", Q, "---",r1, " ", r2, " ",r3, " ",r4, " ",r5)

import pandas as pd
df = pd.DataFrame() 

cntcol = 7
card = 2
vals= [True, False]
matriz = [[] for i in range(cntcol)]

for i in range(7):
  xcard = pow(2,(i))
  while(len(matriz[i])!=pow(len(vals),cntcol)):
    for j in range(xcard):
      matriz[i].append(vals[0])
    for j in range(xcard):
      matriz[i].append(vals[1])

for i in range(len(matriz[0])):
  a = []
  b = []
  for j in range(len(matriz)):
    a.append(matriz[j][i])
  b.append(negacion(matriz[2][i]))
  b.append(bicondicional(matriz[0][i],disyuncion(matriz[3][i],matriz[4][i])))
  b.append(bicondicional(matriz[1][i],disyuncion(matriz[2][i],disyuncion(matriz[5][i],matriz[6][i]))))
  b.append(negacion(matriz[0][i]))
  b.append(matriz[1][i])
  for k in range(len(b)):
    if b[k] == False:
      b.append(False)
      break
    else:
      if k == len(b)-1:
        b.append(True)
  print(a,"-> ",b)