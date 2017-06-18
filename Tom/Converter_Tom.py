#!/bin/python
# encoding=utf8
import sys
import platform
def kifu_converter(index_name, english_user_id, kifu_folder, save_folder):
    f = open(index_name)
    stack = []
    save_index = ""
    for line in f:
        line = line.decode('utf-8')
        line_r = line.split('\t')
        if line_r[2] != english_user_id and line_r[3] != english_user_id:
            continue

        save_index += line
        Num = line_r[0]
        fn_sgf = line_r[1][0:4] + "-" + line_r[1][5:7]
        DT = line_r[1]
        PW = line_r[2]
        PB = line_r[3]
        RE = line_r[5]
        RO = line_r[6]
        TM = line_r[7].split(' ')[1][0:-2] + " min"
        OT = line_r[7].split(' ')[0]
        OT = OT.split('/')[1] + "x " + OT.split('/')[0] + " sec"

        SGF = "(;CA[UTF-8]GM[1]FF[4]AP[converter]\nSZ[19]"
        SGF += "GN[" + Num + "]\n"
        SGF += "DT[" + DT + "]\n"
        SGF += "PB[" + PB + "]" + "BR[9d]\n"
        SGF += "PW[" + PW + "]" + "WR[9d]\n"
        SGF += "RE[" + RE + "]"
        SGF += "RO[" + RO + "]"
        SGF += "KM[6.5]"
        SGF += "RU[Japanese]"
        SGF += "TM[" + TM + "]" + "OT[" + OT + "]\n"
        SGF += "PC[TYGEM]"
        stack.append([SGF, fn_sgf, Num])
    f.close()

    writer = open(english_user_id + ".index", "w")
    writer.write(save_index.encode('utf-8'))
    writer.close()
    
    if platform.platform() == "Windows":
        if kifu_folder[-1] != "\\":
            kifu_folder += "\\"

        if save_folder[-1] != "\\":
            save_folder += "\\"
    else:
        if kifu_folder[-1] != "/":
            kifu_folder += "/"

        if save_folder[-1] != "/":
            save_folder += "/"

    i = 0
    stack_size = len(stack)
    while i < stack_size:
        info = stack[i]
        SGF = info[0]
        fn_sgf = info[1]
        fn_open = fn_sgf
        Num = info[2]
        f_sgf = open(kifu_folder + fn_sgf)
        for line_sgf in f_sgf:
            line_sgf = line_sgf.decode('utf-8')
            split = line_sgf.split('\t')
            if split[0] == Num:
                SGF += split[1] + ")"
                writer = open(save_folder + Num + ".SGF", "w")
                writer.write(SGF.encode('utf-8'))
                writer.close()

                if i + 1 >= stack_size:
                    break

                if fn_open != stack[i + 1][1]:
                    break

                i += 1
                info = stack[i]
                SGF = info[0]
                fn_sgf = info[1]
                Num = info[2]
        f_sgf.close()
        i += 1

if len(sys.argv) != 5:
    print "usage: python Converter_Tom.py Kifu.index english_user_id kifu_folder save_folder"
    print "example: python Converter_Tom.py Kifu.index 930115 kifu save"
else:
    index_name = sys.argv[1]
    english_user_id = sys.argv[2]
    kifu_folder = sys.argv[3]
    save_folder = sys.argv[4]
    kifu_converter(index_name, english_user_id, kifu_folder, save_folder)