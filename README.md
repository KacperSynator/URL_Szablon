# URL_Szablon
University assigment: solve sets of linear equations (real and imaginary). Currently 5x5 equations can be solved, but main can be easly modified for other sizes.
(Imaginary equations are only working for 5x5).

## Getting started
#### 1. Clone repo
```bash
https://github.com/KacperSynator/URL_Szablon.git
```
#### 2. Compile and run 
```bash
make
./URL_S [ < <url_file> ]
```

## Example
```bash
./URL_S < DaneLZ

Wektor rozwiązania:  # Set of equations
|         (2+1i)         (2+3i)         (1+2i)         (3+1i)         (3+2i)  || x_1 |     |      (9+1i) |
|         (1+1i)         (2+5i)         (1.5+3i)         (1+4i)         (2+2i)  || x_2 |     |      (8+2i) |
|         (1+1i)         (3+7i)         (1+1i)         (2+1i)         (2+0i)  || x_3 |  =  |      (8+8i) |
|         (1+2i)         (1+2i)         (1+1i)         (4+3i)         (0+1i)  || x_4 |     |      (9+5i) |
|         (2+3i)         (2+2i)         (0+2i)         (0+0i)         (1+1i)  || x_5 |     |      (1+1i) |
#  result vector
((0.31+3.34i),(1.18-0.44i),(-3.90-5.31i),(3.38+0.02i),(-1.88+1.59i))
Wektor bledu:  # error vector
((-3.6e-15-3.1e-15i),(-3.6e-15-6.7e-15i),(3.6e-15+0.0e+00i),(-3.6e-15-3.6e-15i),(-1.2e-14-1.4e-14i))
Dlugosc wektora bledu: # magnitude of error vector
2.1e-14
```
