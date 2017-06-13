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
* [tygem_convert.tar.gz](http://www.yss-aya.com/20170418tygem_convert.tar.gz)
  * Thanks for [Hiroshi Yamashita](http://www.yss-aya.com/) writing the converter tool.

* [Converter.py](../master/TYGEM/Converter.py)
  * usage: python Converter.py kifu.index english_user_id kifu_folder save_folder
  * example: python Converter.py kifu.index Lurk(P) Kifu Save


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

73,522 games

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
  * AlphaGo Ke
    * AlphaGo vs Ke Jie
      * 3 games
      * 2017.05.23 - 2017.05.27
      * 3W / 0L / 100%
    * AlphaGo vs China Team
      * 1 games
      * 2017.05.26
      * 1W / 0L / 100%
    * AlphaGo + Lian Xiao vs AlphaGo + Gu Li
      * 1 games
      * 2017.05.26
    * AlphaGo selfplay
      * 50 games
  * AlphaGo Master
    * Master
      * 60 games
      * 2016.12.29 - 2017.01.04
      * 60W / 0L / 100%
  * AlphaGo Lee
    * AlphaGo vs Lee Sedol
      * 5 games
      * 2016.03.09 - 2016.03.15
      * 4W / 1L / 80%
    * AlphaGo selfplay
      * 3 games
  * AlphaGo Fan
    * AlphaGo vs Fan Hui
      * 5 games
      * 2015.10.05 - 2015.10.09
      * 5W / 0L / 100%

* FineArt
  * FineArt
    * 590 games
    * 2016.11.01 - 2017.05.12
    * 454W / 136L / 76.94%
  * FineArt UEC
    * 11 games
    * 11W / 0L / 100%
  * Li Long
    * 477 games
    * 2016.10.21 - 2017.06.05
    * 416W / 61L / 87.21%
  * Xing Tian
    * 45 games
    * 2016.12.27 - 2017.01.02
    * 38W / 7L / 84.44%
  * Tian Xia Wu Gou
    * 204 games
    * 2016.09.28 - 2016.10.31
    * 159W / 45L / 77.94%
  * Sweeper
    * 55 games
    * 2016.09.02 - 2016.10.05
    * 38W / 17L / 69.09%
  * Tiger
    * 63 games
    * 2016.07.28 - 2016.10.28
    * 42W / 21L / 66.66%
* Zen
  * DeepZenGo
    * Fox Go Server
    * 97 games
    * 2016.11.19 - 2017.06.11
    * 80W / 17L / 82.47%
  * DeepZen(P)
    * TYGEM
    * 2422 games
    * 2016.12.29 - 2017.05.18
    * 2007W / 415L / 82.87%
  * Zen19L vs Godmoves
    * KGS
    * 3 games
    * 2016.11.29 - 2016.12.01
    * 0W / 3L / 0%
* Leela
  * Leela(P)
    * TYGEM
    * 1354 games
    * 2017.03.29 - 2017.06.14
    * 559W / 795L / 41.29%

6 KGS dataset
======
[website](https://u-go.net/gamerecords/)

Licensing
======
The repository is licensed under GPL v3. License is available [here](LICENSE.txt).
