#!/bin/python
# encoding=utf8
import sys
def statistic(filename, user_id):
    f = open(filename)
    win = 0
    lost = 0
    last = ""
    first = ""
    for line in f:
        line = line.decode('utf-8')
        line_r = line.split('\t')
        winner = line_r[8][0]
        white = line_r[3]
        black = line_r[6]
        if black != user_id and white != user_id:
            continue

        last = line_r[1][1:11]
        if first == "":
            first = line_r[1][1:11]

        if winner == "B":
            if black == user_id:
                win += 1
            else:
                lost += 1
        elif winner == "W":
            if white == user_id:
                win += 1
            else:
                lost += 1
    f.close()
    total = win + lost
    print "* %d games" % total
    print "* %s - %s" %(first, last)
    str = "* %dW / %dL / %.2f%%" %(win, lost, float(win * 100) / float(total))
    print str

if len(sys.argv) != 3:
    print "usage: Statistic.py kifu.index english_user_id"
    print "example: Statistic.py kifu.index lxlx"
else:
    filename = sys.argv[1]
    user_id = sys.argv[2]
    statistic(filename, user_id)
