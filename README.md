Contents
======
* [TYGEM](#1-tygem-dataset)
* [Tom](#2-tom-dataset)
* [Foxwq](#3-foxwq-dataset)
* [Aya](#4-ayas-selfplay-games-for-training-value-network)
* [Professional](#5-professional)
* [AI](#6-ai-dataset)
  * `AlphaGo`
  * `ELF OpenGo`
  * `FineArt`
  * `PhoenixGo`
  * `Zen`
  * `CGI`
  * `DolBaram`
  * `Dancer`
  * `Leela`
  * `CNC`
  * The 1st World AI Go Open 2017
  * Berry Genomics Cup 2018 World AI Weiqi Competition
  * 2018 Tencent World AI WEIQI Competition
  * The 2nd World AI Go Open 2018
  * Berry Genomics Cup 2019 World AI Weiqi Competition
  * 2019 China Securities Cup World AI WEIQI Open
  * The 11th Computer Go UEC Cup
  * 2020 World GO AI Championship
* [CGOS](#7-cgos-dataset)
* [LeelaZero](#8-leela-zero-dataset)
* [KGS](#9-kgs-dataset)
* [Minigo](#10-minigo-dataset)
* [NNGS](#11-nngs-dataset)
* [ELF OpenGo](#12-elf-opengo-dataset)
* [KataGo](#13-katago-dataset)
* [OGS](#14-ogs-dataset)

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
  * char[16]
* white english
  * char[11]
* white nation
  * 0 Korea
  * 1 Japan
  * 2 China
  * 3 USA
  * 4 Chinese Taipei
  * 5 China
* black
  * char[16]
* black english
  * char[11]
* black nation
  * 0 Korea
  * 1 Japan
  * 2 China
  * 3 USA
  * 4 Chinese Taipei
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
* komi
* result
* round
* byoyomi/times minutes

default:

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

2.3 Convert to SGF
------
* [Converter_Tom.py](../master/Tom/Converter_Tom.py)
  * usage: python Converter_Tom.py Kifu.index user_id kifu_folder save_folder
  * example: python Converter_Tom.py Kifu.index 930115 kifu save

3 Foxwq dataset
======

3.1 Github
------
[18k-9d](https://github.com/CamWagner/go-dataset)

3.2 9d vs 9d
------
2013.07.09 - 2019.10.17

166,184 games

4 Aya's selfplay games for training value network
======

**19x19, 13x13, 9x9**

[Aya's selfplay games](http://www.yss-aya.com/ayaself/ayaself.html)


5 Professional
======
1940.01.01 - 2017.01.09

73,522 games

5.1 Format(txt)
------
SGF\nSGF\nSGF\n...

5.2 SGF tags
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

6 AI dataset
======
* `AlphaGo`
  * AlphaGo Zero
    * 83 games
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
      * 55 games
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

* `ELF OpenGo`
  * https://github.com/pytorch/ELF/releases

* `FineArt`
  * fuheyuqi
    * Fox Go Server
    * 171 games
    * 2017.02.20 - 2017.11.23
    * 166W / 5L / 97.07%
  * FineArt
    * Fox Go Server
    * 626 games
    * 2016.11.01 - 2017.05.12
    * 488W / 138L / 77.95%
  * FineArt UEC
    * 11 games
    * 11W / 0L / 100%
  * FineArt vs Gu Li / Tuo Jia Xi / Tan Xiao
    * 1 games
    * 1W / 0L / 100%
  * Li Long
    * Fox Go Server
    * 903 games
    * 2016.10.21 - 2017.09.12
    * 795W / 108L / 88.03%
  * Xing Tian
    * Fox Go Server
    * 45 games
    * 2016.12.27 - 2017.01.02
    * 38W / 7L / 84.44%
  * Tian Xia Wu Gou
    * Fox Go Server
    * 204 games
    * 2016.09.28 - 2016.10.31
    * 159W / 45L / 77.94%
  * Sweeper
    * Fox Go Server
    * 55 games
    * 2016.09.02 - 2016.10.05
    * 38W / 17L / 69.09%
  * Tiger
    * Fox Go Server
    * 63 games
    * 2016.07.28 - 2016.10.28
    * 42W / 21L / 66.66%

* `PhoenixGo`
  * BensonDarr
    * Fox Go Server
    * 666 games
    * 2017.11.28 - 2018.04.24
    * 641W / 24L / 96.39%
  * Shi Kong Qi Dian
    * Fox Go Server
    * 100 games
    * 2018.03.15 - 2018.03.20
    * 100W / 0L / 100.00%
  * Jin Mao Ce Shi
    * Fox Go Server
    * 2744 games
    * 2018.03.20 - 2018.10.10

* `Zen`
  * DeepZenGo
    * Fox Go Server
    * 130 games
    * 2016.11.19 - 2018.04.07
    * 106W / 24L / 81.53%
  * DeepZen(P)
    * TYGEM
    * 2806 games
    * 2016.12.29 - 2017.07.13
    * 2271W / 535L / 80.93%
  * DeepZen(B)
    * TYGEM
    * 303 games
    * 2017.07.13 - 2017.07.27
    * 208W / 95L / 68.65%
  * deepzengo
    * WBaduk
    * 455 games
    * 2017.06.21 - 2017.08.28
    * 437W / 18L / 96.04%
  * Zen19L vs Godmoves
    * KGS
    * 3 games
    * 2016.11.29 - 2016.12.01
    * 0W / 3L / 0%

* `CGI`
  * CGI(P)
    * TYGEM
    * 167 games
    * 2017.07.03 - 2017.07.13
    * 120W / 47L / 71.85%
  * CGI(B)
    * TYGEM
    * 16 games
    * 2017.07.13 - 2017.08.19
    * 10W / 6L / 62.50%
  * CGI
    * Fox Go Server
    * 193 games
    * 2017.09.22 - 2017.11.20
    * 161W / 32L / 83.41%

* `DolBaram`
  * DolBaram
    * TYGEM
    * 26 games
    * 2017.05.08 - 2017.08.03
    * 24W / 2L / 92.31%
  * dolBaram9
    * Fox Go Server
    * 62 games
    * 2017.11.02 - 2018.02.16
    * 50W / 12L / 80.64%

* `Dancer`
  * Dancer(P)
    * TYGEM
    * 171 games
    * 2017.04.02 - 2017.08.27
    * 135W / 36L / 78.95%
  * Dancer(P)
    * Fox Go Server
    * 220 games
    * 2017.12.11 - 2018.04.04
    * 193W / 27L / 87.72%

* `Leela`
  * Leela(P)
    * TYGEM
    * 1851 games
    * 2017.03.29 - 2017.07.13
    * 787W / 1064L / 42.52%
  * Leela(B)
    * TYGEM
    * 481 games
    * 2017.07.13 - 2017.08.11
    * 194W / 287L / 40.33%

* `CNC`
  * cnculture(P)
    * TYGEM
    * 1237 games
    * 2017.04.22 - 2017.07.13
    * 519W / 718L / 41.96%
  * cnculture(B)
    * TYGEM
    * 662 games
    * 2017.07.13 - 2017.08.11
    * 304W / 358L / 45.92%

* The 1st World AI Go Open 2017
  * AI: `Abacus`, `AQ`, `CGI`, `DeepZenGo`, `Dolbaram`, `FineArt`, `Golois`, `Leela`, `MuGo`, `OracleWQ`, `Rayn`, `TianRang`
  * 37 games + 3 special games
  * 2017.08.16 - 2017.08.18
  * 1st: `DeepZenGo`
  * 2nd: `CGI`
  * 3rd: `FineArt`

* Berry Genomics Cup 2018 World AI Weiqi Competition
  * AI: `BADUKi`, `Dolbaram`, `FineArt`, `Golois`, `HEROZ Kishin`, `Leela Zero`, `Phoenix Go`, `TS Go`
  * 26 games
  * 2018.04.27 - 2018.04.28
  * 1st: `Phoenix Go`
  * 2nd: `FineArt`
  * 3rd: `Leela Zero`

* 2018 Tencent World AI WEIQI Competition
  * 2018.06.24, Preliminary Contest: `AQ`, `Aya`, `BADUKi`, `Dolbaram`, `ELFOpenGo`, `FineArt`, `Golaxy`, `LeelaZero`, `Northern Lights`, `Octopus`, `Raynz`
  * 2018.07.09, Repecharge: `FineArt`, `Golaxy`, `ELFOpenGo`, `AQ`, `LeelaZero`, `Octopus`, `BADUKi`, `Dolbaram`
  * 2018.07.29, Semi-final: `FineArt`, `Golaxy`, `ELFOpenGo`, `AQ`
  * 2018.07.30, Final: `FineArt`, `Golaxy`
  * 1st: `FineArt`
  * 2nd: `Golaxy`

* The 2nd World AI Go Open 2018
  * AI: `AQ`, `BADUKi`, `Dolbaram`, `ELFOpenGo`, `Golaxy`, `Raynz`, `Octopus`, `Og-go`
  * 31 games
  * 2018.08.13 - 2018.08.15
  * 1st: `Golaxy`
  * 2nd: `AQ`
  * 3rd: `Octopus`

* Berry Genomics Cup 2019 World AI Weiqi Competition
  * AI: `BADUKi`, `Dolbaram`, `Go Genius`, `Golaxy`, `Golois`, `Leela Zero`, `Raynz`, `YXT`
  * 28 games
  * 2019.04.26 - 2019.04.28
  * 1st: `Golaxy`
  * 2nd: `BADUKi`
  * 3rd: `Leela Zero`

* 2019 China Securities Cup World AI WEIQI Open
  * AI: `CGI`, `ClearStone`, `Dolbaram`, `FineArt`, `Globis-AQZ`, `Go Genius`, `Golaxy`, `HanDol`, `Handtalk`, `LeelaZero`, `MayaGo`, `Octopus`, `YaoGo`, `YiXiaoTian`
  * 51 games
  * 2019.08.22 - 2019.08.25
  * 1st: `FineArt`
  * 2nd: `Golaxy`
  * 3rd: `HanDol`
  * 4th: `LeelaZero`
  
* The 11th Computer Go UEC Cup
  * AI: `Akira`, `BaduGI`, `BSK`, `EsArgo`, `GLOBIS-AQZ`, `Go Genius`, `Golaxy`, `Katsunari`, `Kifuwarabe`, `Kugutsu`, `Maru`, `masacts`, `mayoigo`, `Natsukaze`, `nlp`, `QuinoaIgo`, `Ray`, `Rn`
  * 93 games
  * 2019.12.14 - 2019.12.15
  * 1st: `Golaxy`
  * 2nd: `GLOBIS-AQZ`
  * 3rd: `BaduGI`

* 2020 World GO AI Championship
  * 1st: `Golaxy`
  * 4th: `KataGo 40b384f with training`

7 CGOS dataset
======
  * [19x19](http://www.yss-aya.com/cgos/19x19/archive.html)
  * [13x13](http://www.yss-aya.com/cgos/13x13/archive.html)
  * [9x9](http://www.yss-aya.com/cgos/9x9/archive.html)

8 Leela Zero dataset
======
  * [Self-Play](https://sjeng.org/zero/all.sgf.xz)
  * [Match](https://sjeng.org/zero/all_match.sgf.xz)
  * [Training Data](https://leela.online-go.com/training/)

9 KGS dataset
======
[Kifu](https://u-go.net/gamerecords/)

10 Minigo dataset
======
* CloudyGo
  * [Seth Troisi's Minigo Game Viewer](http://cloudygo.com/)
  * [Results](https://cloudygo.com/RESULTS)
* Github
  * [Results](https://github.com/tensorflow/minigo/blob/master/RESULTS.md)
* Youtube
  * [Building a Go AI with Kubernetes and TensorFlow](https://www.youtube.com/watch?v=kCk1zuowg8E)
  * [MiniGo: TensorFlow Meets Andrew Jackson (TensorFlow Meets)](https://www.youtube.com/watch?v=LRqlmjL3-n8)
* cloud.google.com
  * Under v?-[9x9](https://console.cloud.google.com/storage/browser/minigo-pub) directory you can find
    * data/ Tensorflow tf.Record files corresponding to raw training data
    * models/ The saved model files for each generation
    * sgf/ Zip archives of all games in .sgf form, grouped by generation

  * Under v?-[19x19](https://console.cloud.google.com/storage/browser/minigo-pub) directory you can find
    * models/ The saved model files for each generation
    * sgf/ Zip archives of all games in .sgf form, grouped by generation

11 NNGS dataset
======
[github](https://github.com/zenon/NNGS_SGF_Archive)

* 435,495 SGF files
* 1995.07 - 2005.05

12 ELF OpenGo dataset
======
* [Home Page](https://facebook.ai/developers/tools/elf-opengo)
* [v2-training-run](https://dl.fbaipublicfiles.com/elfopengo/v2_training_run/README)
  * 19,690,954 SGF files
* [Analysis](https://dl.fbaipublicfiles.com/elfopengo/analysis/README)
  * [Analyzing Go Games by the Quality of Their Moves](https://dl.fbaipublicfiles.com/elfopengo/analysis/www/index.html)

13 KataGo dataset
======
* [KataGo Distributed Training](https://katagotraining.org/)
* [Home Page](https://github.com/lightvector/KataGo)
* [dataset](https://d3dndmfyhecmj0.cloudfront.net/)
  * [g65 (Feb 2019 run)](https://d3dndmfyhecmj0.cloudfront.net/g65/index.html)
  * [g104 (June 2019 run)](https://d3dndmfyhecmj0.cloudfront.net/g104/index.html)
  * [g170 (Jan 2020 run)](https://d3dndmfyhecmj0.cloudfront.net/g170/index.html)

14 OGS dataset
======
* [Home Page](https://za3k.com/ogs/)
* All (56 million) Go games, downloaded from [online-go.com](https://online-go.com/) (aka OGS) and redistributed with permission

SGF
======
[SGF Format](http://www.red-bean.com/sgf/)
