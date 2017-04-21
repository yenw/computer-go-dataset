void TYGEM::KifuInfoParser(uint8_t* p, size_t n)
{
    for (size_t i = 0; i < n;)
    {
        wxString parser;
        size_t it = i;

        //number
        int num = 0;
        do num = num * 256 + p[i++];
        while(i < 4 + it)
            ;
        if (num < 75803708)
            return;

        //white name
        char native_name_white[16] = {0};
        for (int k = 0; p[i] && k < 15; ++k)
            native_name_white[k] = p[i++];

        //white rank
        uint8_t rank_white = p[it + 19];
        i = it + 20;

        //white english name
        char english_name_white[11] = {0};
        for (int k = 0; p[i] && k < 10; ++k)
            english_name_white[k] = p[i++];

        //white nation
        uint8_t nation_white = p[it + 31];
        i = it + 32;

        //black name
        char native_name_black[16] = {0};
        for (int k = 0; p[i] && k < 15; ++k)
            native_name_black[k] = p[i++];

        //black rank
        uint8_t rank_black = p[it + 47];
        i = it + 48;

        //black english name
        char english_name_black[11] = {0};
        for (int k = 0; p[i] && k < 10; ++k)
            english_name_black[k] = p[i++];

        //black nation
        uint8_t nation_black = p[it + 59];
        i = it + 60;

        //game type
        uint8_t game_type = p[it + 60];
        wxString type;
        if (game_type == 0x30)
            type = "Rank";
        else
            type = wxString::Format("%X", game_type);

        //result
        uint16_t result_num = p[it + 66] * 256 + p[it + 67];
        wxString result;
        switch (result_num)
        {
        case 55546:
            result = "B+Resign";
            break;
        case 56656:
            result = "B+Time";
            break;
        case 57766:
            result = "B+Offline";
            break;
        case 9990:
            result = "W+Resign";
            break;
        case 8880:
            result = "W+Time";
            break;
        case 7770:
            result = "W+Offline";
            break;
        case 0:
            result = "Draw";
            break;
        default:
            if (result_num > 32727)
                result = wxString::Format("B+%d", (int)((65536 - result_num) / 10)) + ".5";
            else
                result = wxString::Format("W+%d", (int)(result_num / 10)) + ".5";
            break;
        }

        //round
        uint16_t round = p[it + 68] * 256 + p[it + 69];

        //Date
        wxString date = "C";
        for (int k = 0; k < 19 - 3; ++k)
        {
            if (p[it + 70 + k] == 0)
                break;
            date += p[it + 70 + k];
        }

        date[5] = '.';
        date[8] = '.';

        //continue
        i = it + 91;
        while(p[i++])
            ;//Skip 00

        ///skip parser
        //!Rank || !9d || round < 60 || Draw
        if (game_type != 0x30 || rank_black != 0x1A || rank_white != 0x1A || round < 60 || result_num == 0)
            continue;

        //+=
        //number
        parser += wxString::Format("%d\t", num);

        //date
        parser += date + '\t';

        //native_name_white
        wxString tmp;
        switch (nation_white)
        {
        case 0:
            parser += wxString(native_name_white, wxCSConv("EUC_KR")) + '\t';
            break;
        case 1:
            parser += wxString(native_name_white, wxCSConv("CP932")) + '\t';
            break;
        case 2:
            parser += wxString(native_name_white, wxCSConv("GB2312")) + '\t';
            break;
        case 3:
            parser += wxString(native_name_white, wxCSConv("CP1252")) + '\t';
            break;
        case 4:
            parser += wxString(native_name_white, wxCSConv("BIG5")) + '\t';
            break;
        case 5:
            parser += wxString(native_name_white, wxCSConv("GB2312")) + '\t';
            break;
        default:
            parser += wxString(native_name_white) + '\t';
            break;
        }

        //english_name_white
        parser += wxString(english_name_white, wxCSConv("CP1252")) + '\t';

        //nation_white
        parser += wxString::Format("%d\t", nation_white);

        //native_name_black
        switch (nation_black)
        {
        case 0:
            parser += wxString(native_name_black, wxCSConv("EUC_KR")) += '\t';
            break;
        case 1:
            parser += wxString(native_name_black, wxCSConv("CP932")) += '\t';
            break;
        case 2:
            parser += wxString(native_name_black, wxCSConv("GB2312")) += '\t';
            break;
        case 3:
            parser += wxString(native_name_black, wxCSConv("CP1252")) += '\t';
            break;
        case 4:
            parser += wxString(native_name_black, wxCSConv("BIG5")) += '\t';
            break;
        case 5:
            parser += wxString(native_name_black, wxCSConv("GB2312")) += '\t';
            break;
        default:
            parser += wxString(native_name_black);
            break;
        }

        //english_name_black
        parser += wxString(english_name_black, wxCSConv("CP1252")) + '\t';

        //nation_black
        parser += wxString::Format("%d\t", nation_black);

        //result
        parser += result + '\t';

        //round
        parser += wxString::Format("%d", round);
        Kifu_Stack.push(parser);
    }
}