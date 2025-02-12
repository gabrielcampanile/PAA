{
 "cells": [
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Preço maximo da barra"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 8,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "1 2 2\n",
      "2 4 2\n",
      "3 6 4\n",
      "4 8 5\n",
      "5 10 8\n",
      "6 12 10\n"
     ]
    },
    {
     "data": {
      "text/plain": [
       "12"
      ]
     },
     "execution_count": 8,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "precos, vetResp = [], []\n",
    "\n",
    "def maxVenda(tam):\n",
    "    if tam <= 0: return 0\n",
    "    if vetResp[tam - 1] > 0: \n",
    "        return vetResp[tam - 1]\n",
    "    else:\n",
    "        #print((6 - tam)*\" \", tam)\n",
    "        maior = -1\n",
    "        for i in range(1, tam + 1):\n",
    "            resultado = precos[i - 1] + maxVenda(tam - i)\n",
    "            if resultado > maior: maior = resultado\n",
    "        vetResp[tam - 1] = maior\n",
    "        print(tam, maior, precos[tam - 1])\n",
    "        return maior\n",
    "\n",
    "\n",
    "tam = 6\n",
    "precos = [2, 2, 4, 5, 8, 10]\n",
    "vetResp = [-1 for i in precos]\n",
    "maxVenda(tam)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 25,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "1 2 2\n",
      "2 2 4\n",
      "3 4 6\n",
      "4 5 8\n",
      "5 8 10\n",
      "6 10 12\n"
     ]
    },
    {
     "data": {
      "text/plain": [
       "12"
      ]
     },
     "execution_count": 25,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "def maxVendaBottomUp(tam):\n",
    "    vetResp[1 - 1] = precos[1 - 1]\n",
    "    print(1, precos[1-1], vetResp[1-1])\n",
    "    for i in range(2, tam + 1):\n",
    "        maior = precos[i - 1]\n",
    "        for j in range(1, i):\n",
    "            maior = max(maior, precos[j - 1] + vetResp[i - j - 1])\n",
    "        \n",
    "        vetResp[i - 1] = maior\n",
    "        print(i, precos[i - 1], vetResp[i - 1])\n",
    "    return vetResp[tam - 1]\n",
    "\n",
    "vetResp = [-1 for i in precos]\n",
    "maxVendaBottomUp(6)"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "Mostrar não apenas a solução, mas o resultado (cortes)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 36,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "[(1, 1), (3, 2), (4, 1), (6, 2), (7, 1), (9, 2)]"
      ]
     },
     "execution_count": 36,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "def maxVenda(tam, precos, vetResp):\n",
    "    if tam <= 0: return 0\n",
    "    if vetResp[tam - 1] != -1: return vetResp[tam - 1][0]\n",
    "    \n",
    "    maior = (precos[tam - 1], tam)\n",
    "    for i in range(1, tam):\n",
    "        valor = precos[i - 1] + maxVenda(tam - i, precos, vetResp)\n",
    "        if valor > maior[0]:\n",
    "            maior = (valor, i)\n",
    "\n",
    "    vetResp[tam - 1] = maior\n",
    "    return maior[0]\n",
    "\n",
    "def auxMaxVenda(precos):\n",
    "    tam = len(precos)\n",
    "    vetResp = [-1 for i in precos]\n",
    "    maxVenda(tam, precos, vetResp)\n",
    "    return vetResp\n",
    "\n",
    "sol = auxMaxVenda([1, 3, 1, 1, 1, 1])\n",
    "sol"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 46,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "1 [1]\n",
      "2 [2]\n",
      "3 [1, 2]\n",
      "4 [2, 2]\n",
      "5 [1, 2, 2]\n",
      "6 [2, 2, 2]\n"
     ]
    }
   ],
   "source": [
    "def remontarSolucao(sol, tam):\n",
    "    i = tam\n",
    "    barras = []\n",
    "    while sol[i - 1][1] != i:\n",
    "        barras.append(sol[i - 1][1])\n",
    "        i -= barras[-1]\n",
    "    barras.append(sol[i - 1][1])\n",
    "    return barras\n",
    "\n",
    "for i in range(1, len(sol) + 1):\n",
    "    print(i, remontarSolucao(sol, i))\n"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# fibonnaci"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 50,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "[1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987]"
      ]
     },
     "execution_count": 50,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "def fibonnaci(n, f):\n",
    "    if f[n] != -1: return f[n]\n",
    "    else: \n",
    "        f[n] = fibonnaci(n - 1, f) + fibonnaci(n - 2, f)\n",
    "        return f[n]\n",
    "\n",
    "def auxFibonnaci(n):\n",
    "    f = [-1 for i in range(n + 1)]\n",
    "    f[0] = 1\n",
    "    f[1] = 1\n",
    "    fibonnaci(n, f)\n",
    "    return f\n",
    "\n",
    "auxFibonnaci(15)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 56,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "[1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987]"
      ]
     },
     "execution_count": 56,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "def fibonnaciBottomUp(n):\n",
    "    f = [-1 for i in range(n + 1)]\n",
    "    f[0], f[1] = 1, 1\n",
    "    for i in range(2, n + 1):\n",
    "        f[i] = f[i - 1] + f[i - 2]\n",
    "    return f\n",
    "\n",
    "fibonnaciBottomUp(15)"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Longest Increasing Subsequence (LIS)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 80,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "-7 10 \n",
      "-7 9 \n",
      "-7 2 3 8 \n",
      "-7 2 3 8 \n",
      "-7 2 3 \n",
      "-7 2 8 \n",
      "-7 2 8 \n",
      "-7 2 \n",
      "-7 3 8 \n",
      "-7 3 8 \n",
      "-7 3 \n",
      "-7 8 \n",
      "-7 8 \n",
      "-7 1 \n",
      "-7 \n",
      "10 \n",
      "9 \n",
      "2 3 8 \n",
      "2 3 8 \n",
      "2 3 \n",
      "2 8 \n",
      "2 8 \n",
      "2 \n",
      "3 8 \n",
      "3 8 \n",
      "3 \n",
      "8 \n",
      "8 \n",
      "1 \n",
      "\n"
     ]
    },
    {
     "data": {
      "text/plain": [
       "4"
      ]
     },
     "execution_count": 80,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "def isValid(sol, lista, pos):\n",
    "    i = pos - 1\n",
    "    while i >= 0 and sol[i] == False:\n",
    "        i -= 1\n",
    "    if i == -1: return True\n",
    "    if lista[i] < lista[pos]: return True\n",
    "    else: return False\n",
    "\n",
    "def LISBacktracking(sol, lista, pos, maxGlobal):\n",
    "    if pos >= len(lista):\n",
    "        total = sum(sol)\n",
    "        for i, j in enumerate(sol):\n",
    "            if j: print(lista[i], end=\" \")\n",
    "        print()\n",
    "        if total > maxGlobal: return total\n",
    "        else: return maxGlobal\n",
    "    \n",
    "    for i in [True, False]:\n",
    "        if i == False or isValid(sol, lista, pos):\n",
    "            sol[pos] = i\n",
    "            maxGlobal = LISBacktracking(sol, lista, pos + 1, maxGlobal)\n",
    "    \n",
    "    return maxGlobal\n",
    "\n",
    "def auxLISBacktracking(lista):\n",
    "    sol = [False for i in lista]\n",
    "    return LISBacktracking(sol, lista, 0, -1)\n",
    "\n",
    "auxLISBacktracking([-7, 10, 9, 2, 3, 8, 8, 1])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 89,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "4"
      ]
     },
     "execution_count": 89,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "def LISTopDown(pos, maior, lista):\n",
    "    if maior[pos] != -1: return maior[pos]\n",
    "    else:\n",
    "        maximo = 1\n",
    "        for i in range(pos):\n",
    "            if lista[i] < lista[pos]:\n",
    "                maximo = max(LISTopDown(i, maior, lista) + 1, maximo)\n",
    "        maior[pos] = maximo\n",
    "        return maximo\n",
    "\n",
    "def auxLISTopDown(lista):\n",
    "    maior = [-1 for i in lista]\n",
    "    maximo = 1\n",
    "    for i in range(len(lista)):\n",
    "        valor = LISTopDown(i, maior, lista)\n",
    "        maximo = max(maximo, valor)\n",
    "    return maximo\n",
    "\n",
    "\n",
    "auxLISTopDown([-7, 10, 9, 2, 3, 8, 8, 1])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 92,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "[1, 2, 2, 2, 3, 4, 4, 2]"
      ]
     },
     "execution_count": 92,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "def LISBottomUp(lista):\n",
    "    maior = [-1 for _ in lista]\n",
    "\n",
    "    for i in range(len(lista)):\n",
    "        maximo = 1\n",
    "        for j in range(i):\n",
    "            if lista[j] < lista[i]:\n",
    "                maximo = max(maximo, maior[j] + 1)\n",
    "        maior[i] = maximo\n",
    "    \n",
    "    return maior\n",
    "\n",
    "LISBottomUp([-7, 10, 9, 2, 3, 8, 8, 1])"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Longest Common Subsequence (LCS)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "([[1, 1, 1], [1, 2, 2], [1, 2, 2]], 2)"
      ]
     },
     "execution_count": 144,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "def LCSTopDown(l1, l2, maiores, p1, p2):\n",
    "    if p1 < 0 or p2 < 0: return 0\n",
    "    if maiores[p1][p2] != -1: return maiores[p1][p2]\n",
    "    else:\n",
    "        if l1[p1] == l2[p2]:\n",
    "            valor = 1 + LCSTopDown(l1, l2, maiores, p1 - 1, p2 - 1)\n",
    "        else:\n",
    "            valor = max(LCSTopDown(l1, l2, maiores, p1 - 1, p2),\n",
    "                        LCSTopDown(l1, l2, maiores, p1, p2 - 1))\n",
    "        \n",
    "        maiores[p1][p2] = valor\n",
    "        return valor\n",
    "\n",
    "def auxLCSTopDown(l1, l2):\n",
    "    maiores = [[-1 for _ in l2] for _ in l1]\n",
    "    return maiores, LCSTopDown(l1, l2, maiores, len(l1) - 1, len(l2) - 1)\n",
    "\n",
    "auxLCSTopDown('ABD', 'ABC')"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Maior Palindromo"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 150,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "7"
      ]
     },
     "execution_count": 150,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "l1 = 'A1B23CDC4567B89A' # ABCDCBA com Ruido\n",
    "l2 = l1[::-1] # Invertendo a palavra\n",
    "auxLCSTopDown(l1, l2)[1]"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Troco Minimo"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 28,
   "metadata": {},
   "outputs": [],
   "source": [
    "def trocoMinimo(troco, moedas, minimos, pos):\n",
    "    if moedas[pos] == 1: \n",
    "        minimos[troco] = troco\n",
    "        return troco\n",
    "    if minimos[troco] != -1: return minimos[troco]\n",
    "    else:\n",
    "        minimo = troco\n",
    "        for i in range(0, troco//moedas[pos] + 1):\n",
    "            valor = i + trocoMinimo(troco - i*moedas[pos], moedas, minimos, pos + 1)\n",
    "            minimo = min(minimo, valor)\n",
    "        minimos[troco] = minimo\n",
    "        return minimo\n",
    "\n",
    "def auxTrocoMin(troco, moedas):\n",
    "    minimos = [-1 for i in range(troco + 1)]\n",
    "    trocoMinimo(troco, moedas, minimos, 0)\n",
    "    return minimos"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 29,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "0 0\n",
      "1 1\n",
      "2 2\n",
      "3 -1\n",
      "4 -1\n",
      "5 -1\n",
      "6 -1\n",
      "7 1\n",
      "8 8\n",
      "9 -1\n",
      "10 -1\n",
      "11 -1\n",
      "12 -1\n",
      "13 -1\n",
      "14 -1\n",
      "15 15\n",
      "16 -1\n",
      "17 -1\n",
      "18 -1\n",
      "19 -1\n",
      "20 -1\n",
      "21 -1\n",
      "22 2\n"
     ]
    }
   ],
   "source": [
    "sol = auxTrocoMin(22, [20, 15, 7, 1])\n",
    "for i, j in enumerate(sol):\n",
    "    print(i, j)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "def trocoMinBottomUp(troco, moedas):\n",
    "    minimos = [-1 for i in range(troco + 1)]\n",
    "    minimos[0], minimos[1] = 0, 1\n",
    "    for m in moedas:\n",
    "        for i in range(0, troco//m + 1):\n",
    "            "
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Seletor de Atividades"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 5,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "[1, 1, 2, 1, 2, 3, 3, 4, 4]"
      ]
     },
     "execution_count": 5,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "def seletorDeAtividades(atividades, maiores, pos):\n",
    "    if maiores[pos] != -1: return maiores[pos]\n",
    "    else:\n",
    "        maior = 1\n",
    "        for i in range(pos):\n",
    "            if atividades[pos][0] >= atividades[i][1]:\n",
    "                valor = 1 + seletorDeAtividades(atividades, maiores, i)\n",
    "                maior = max(maior, valor)\n",
    "        maiores[pos] = maior\n",
    "        return maior\n",
    "\n",
    "def auxSeletor(atividades):\n",
    "    maiores = [-1 for i in atividades]\n",
    "    seletorDeAtividades(atividades, maiores, len(maiores) - 1)\n",
    "    for i, val in enumerate(maiores):\n",
    "        if val == -1: seletorDeAtividades(atividades, maiores, i)\n",
    "    return maiores\n",
    "\n",
    "auxSeletor([(1,3), (2,5), (4,7), (1,8), (5,9), (8,10), (9,11), (11,14), (13,16)])\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 7,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "[1, 1, 2, 1, 2, 3, 3, 4, 4]"
      ]
     },
     "execution_count": 7,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "def seletorBottomUp(atividades):\n",
    "    maiores = [1 for _ in atividades]\n",
    "    maiores[0] = 1\n",
    "    for i in range(1, len(atividades)):\n",
    "        for j in range(0, i):\n",
    "            if atividades[i][0] >= atividades[j][1]:\n",
    "                maiores[i] = max(maiores[i], 1 + maiores[j])\n",
    "    return maiores\n",
    "\n",
    "seletorBottomUp([(1,3), (2,5), (4,7), (1,8), (5,9), (8,10), (9,11), (11,14), (13,16)])"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "base",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.12.7"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
