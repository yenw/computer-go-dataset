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

default:

* komi
  * 6.5 
* white rank
  * 9d
* black rank
  * 9d
* type
  * ranked
* CA
  * UTF-8
* GM
  * 1
* FF
  * 4


Due to the 25 MB file size limit, I have to split the ".index" file. You can merge it by yourself.

1.2 Format(kifu)
------
id\t;B[coord];W[coord];B[coord];W[coord]......

1.3 Convert to SGF
------
Thanks for [Hiroshi Yamashita](http://www.yss-aya.com/) writing the converter tool.

[tygem_convert.tar.gz](http://www.yss-aya.com/20170418tygem_convert.tar.gz)



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
* result
* round
* byoyomi/times minutes

default:

* komi
  * 7.5 
* white rank
  * 9d
* black rank
  * 9d
* type
  * ranked
* CA
  * UTF-8
* GM
  * 1
* FF
  * 4

2.2 Format(kifu)
------
id\t;B[coord];W[coord];B[coord];W[coord]......

3 Aya's selfplay games for training value network
======
[Aya's selfplay games](http://www.yss-aya.com/ayaself/ayaself.html)

4 Professional
======
1940.01.01 - 2017.01.09

73,522 games (Includes newest AlphaGo/Master games)

4.1 Format(txt)
------
SGF\nSGF\nSGF\n...

4.2 SGF tags
------
* GM
  * 1
* FF
  * 4
* SZ
  * 19
* AP
* CA
  * UTF-8
* GN
* PW
* WR (option)
* PB
* BR (option)
* KM (option)
  * 0 <= komi <= 8
* RE
  * B+
  * W+
  * B+X
  * W+X
  * B+R
  * W+R
  * B+T
  * W+T

* B/W/B/W ...

5 AI dataset
======
* AlphaGo
  * AlphaGo vs Lee Sedol
    * 5 games
    * 4W / 1L / 80%
  * AlphaGo selfplay
    * 3 games
  * Master
    * 60 games
    * 60W / 0L / 100%
* FineArt
  * FineArt
    * 590 games
    * 2016.11.01 - 2017.05.12
    * 454W / 136L / 76.94%
  * FineArt UEC
    * 11 games
    * 11W / 0L / 100%
  * Li Long
    * 301 games
    * 2016.10.21 - 2017.05.15
    * Old version of FineArt
    * 265W / 36L / 88.03%
  * Xing Tian
    * 45 games
    * 2016.12.27 - 2017.01.02
    * 38W / 7L / 84.44%

6 KGS dataset
======
[website](https://u-go.net/gamerecords/)

Licensing
======
The repository is licensed under GPL v3. License is available [here](LICENSE.txt).
