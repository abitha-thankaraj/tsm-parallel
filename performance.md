2 cities
--------
Shortest path is:
0 1
total weight = 10

real    0m0.004s
user    0m0.000s
sys     0m0.003s

time ./ptsm 2 1 ../cities2.txt
Min cost is: 10
Min cost path is: 0 1

real    0m0.010s
user    0m0.004s
sys     0m0.002s
[at4524@crunchy6 scratch]$ time ./ptsm 2 1 ../cities2.txt
Min cost is: 10
Min cost path is: 0 1

real    0m0.009s
user    0m0.002s
sys     0m0.004s

[at4524@crunchy6 scratch]$ time ./ptsm 2 2 ../cities2.txt
Min cost is: 10
Min cost path is: 0 1

real    0m0.009s
user    0m0.001s
sys     0m0.006s
[at4524@crunchy6 scratch]$ time ./ptsm 2 3 ../cities2.txt
Min cost is: 10
Min cost path is: 0 1

real    0m0.008s
user    0m0.004s
sys     0m0.003s

[at4524@crunchy6 scratch]$ time ./ptsm 2 4 ../cities2.txt
Min cost is: 10
Min cost path is: 0 1

real    0m0.010s
user    0m0.003s
sys     0m0.007s

time ./ptsm 2 16 ../cities2.txt
Min cost is: 10
Min cost path is: 0 1

real    0m0.009s
user    0m0.011s
sys     0m0.018s

4 cities
--------
time ./tsmoptimal 4 cities4.txt
Shortest path is:
0 2 1 3
total weight = 23

real    0m0.008s
user    0m0.003s
sys     0m0.003s

time ./ptsm 4 1 ../cities4.txt
Min cost is: 23
Min cost path is: 0 2 1 3

real    0m0.008s
user    0m0.001s
sys     0m0.004s
[at4524@crunchy6 scratch]$ time ./ptsm 4 1 ../cities4.txt
Min cost is: 23
Min cost path is: 0 2 1 3

real    0m0.010s
user    0m0.003s
sys     0m0.003s

[at4524@crunchy6 scratch]$ time ./ptsm 4 2 ../cities4.txt
Min cost is: 23
Min cost path is: 0 2 1 3

real    0m0.008s
user    0m0.003s
sys     0m0.003s
[at4524@crunchy6 scratch]$ time ./ptsm 4 3 ../cities4.txt
Min cost is: 23
Min cost path is: 0 3 1 2

real    0m0.008s
user    0m0.002s
sys     0m0.005s
[at4524@crunchy6 scratch]$ time ./ptsm 4 4 ../cities4.txt
Min cost is: 23
Min cost path is: 0 3 1 2

real    0m0.008s
user    0m0.003s
sys     0m0.005s

6 cities
--------
time ./tsmoptimal 6 cities6.txt
Shortest path is:
0 1 4 3 2 5
total weight = 23

real    0m0.005s
user    0m0.000s
sys     0m0.003s

time ./ptsm 6 1 ../cities6.txt
Min cost is: 23
Min cost path is: 0 1 4 3 2 5

real    0m0.008s
user    0m0.002s
sys     0m0.004s

8 cities
--------
time ./tsmoptimal 8 cities8.txt
Shortest path is:
0 1 5 4 2 3 7 6
total weight = 39

real    0m0.006s
user    0m0.003s
sys     0m0.002s

time ./ptsm 8 1 ../cities8.txt
Min cost is: 39
Min cost path is: 0 1 5 4 2 3 7 6

real    0m0.011s
user    0m0.005s
sys     0m0.003s

[at4524@crunchy6 scratch]$ time ./ptsm 8 1 ../cities8.txt
Min cost is: 39
Min cost path is: 0 1 5 4 2 3 7 6

real    0m0.013s
user    0m0.005s
sys     0m0.004s

[at4524@crunchy6 scratch]$ time ./ptsm 8 2 ../cities8.txt
Min cost is: 39
Min cost path is: 0 1 5 4 2 3 7 6

real    0m0.010s
user    0m0.005s
sys     0m0.006s
[at4524@crunchy6 scratch]$ time ./ptsm 8 3 ../cities8.txt
Min cost is: 39
Min cost path is: 0 6 2 3 7 4 1 5

real    0m0.010s
user    0m0.004s
sys     0m0.009s
[at4524@crunchy6 scratch]$ time ./ptsm 8 4 ../cities8.txt
Min cost is: 39
Min cost path is: 0 5 1 4 2 3 7 6

real    0m0.009s
user    0m0.011s
sys     0m0.003s

10 cities
--------
time ./tsmoptimal 10 cities10.txt
Shortest path is:
0 4 9 1 6 8 2 3 7 5
total weight = 44

real    0m0.118s
user    0m0.115s
sys     0m0.001s

[at4524@crunchy6 scratch]$ time ./ptsm 10 1 ../cities10.txt
Min cost is: 44
Min cost path is: 0 4 9 1 6 8 2 3 7 5

real    0m0.331s
user    0m0.323s
sys     0m0.003s


[at4524@crunchy6 scratch]$ time ./ptsm 10 4 ../cities10.txt
Min cost is: 44
Min cost path is: 0 5 7 3 2 8 6 1 9 4

real    0m0.130s
user    0m0.427s
sys     0m0.005s


12 cities
--------
Shortest path is:
0 1 7 2 9 5 3 8 10 6 11 4
total weight = 52

real    0m16.645s
user    0m16.461s
sys     0m0.010s

time ./ptsm 12 1 ../cities12.txt
Min cost is: 52
Min cost path is: 0 1 7 2 9 5 3 8 10 6 11 4

real    0m32.885s
user    0m32.670s
sys     0m0.010s
[at4524@crunchy6 scratch]$ time ./ptsm 12 1 ../cities12.txt
Min cost is: 52
Min cost path is: 0 1 7 2 9 5 3 8 10 6 11 4

real    0m44.869s
user    0m44.859s
sys     0m0.004s

[at4524@crunchy6 scratch]$ time ./ptsm 12 2 ../cities12.txt
Min cost is: 52
Min cost path is: 0 7 1 2 9 5 3 8 10 6 11 4

real    0m28.076s
user    0m54.123s
sys     0m0.007s

[at4524@crunchy6 scratch]$ time ./ptsm 12 3 ../cities12.txt
Min cost is: 52
Min cost path is: 0 4 9 2 1 7 6 10 8 3 5 11

real    0m19.633s
user    0m56.138s
sys     0m0.008s

[at4524@crunchy6 scratch]$ time ./ptsm 12 4 ../cities12.txt
Min cost is: 52
Min cost path is: 0 9 5 3 8 10 2 1 7 6 11 4

real    0m14.892s
user    0m56.529s
sys     0m0.007s


