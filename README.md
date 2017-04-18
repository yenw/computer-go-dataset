SGF
======
[SGF Format](http://www.red-bean.com/sgf/)

1 TYGEM dataset
======
2005.11.02 - 2016.12.31

TYGEM "9D vs 9D" dataset (1,516,031 games).


1.1 Format(index)
------
* id
  * TYGEM id
* date
  * YYYY.MM.DD HH:MM
* white
  * char[10]
* white english
  * char[10]
* white nation
  * 0 Korea
  * 1 Japan
  * 2 China
  * 3 USA
  * 4 Taiwan
  * 5 China
* black
  * char[10]
* black english
  * char[10]
* black nation
  * 0 Korea
  * 1 Japan
  * 2 China
  * 3 USA
  * 4 Taiwan
  * 5 China
* komi
  * 7.5
* result
  * B+Resign
  * W+Resign
  * B+X.5
  * W+X.5
  * B+Time
  * W+Time
  * B+Offline
  * W+Offline
* round
  * 60 - 450
* byoyomi/times minutes

Due to the 25 MB file size limit, I have to split the ".index" file. You can merge it by yourself.

1.2 Format(kifu)
------
id\t;B[coord];W[coord];B[coord];W[coord]......

2 TOM dataset
======
2003.09.25 - 2011.12.28

TOM "9D vs 9D" dataset (50,956 games).

2.1 Format(index)
------
* id
* date
* white
* black
* komi
* result
* round
* byoyomi/times minutes


2.2 Format(kifu)
------
id\t;B[coord];W[coord];B[coord];W[coord]......

3 KGS dataset
======
[website](https://u-go.net/gamerecords/)

Licensing
------
The repository is licensed under GPL v3. License is available [here](LICENSE.txt).
