bool TYGEM::GibParser(int Kifu_id, const wxString& gib, wxString& SGF, wxString& overtime)
{
    int STO = 0;
    int REM = 0;
    int DSC = 0;
    int SKI = 0;
    int WIT = 0;
    int SKI_re = 0;
    SGF = wxString::Format("%d\t", Kifu_id);
    overtime = "";
    wxArrayString AStr;
    size_t pos, pos2;

    pos = gib.find("GAMETAG", 0);
    if (pos == gib.npos)
        return false;

    pos += 7;
    pos = gib.find('T', pos);
    if (pos == gib.npos)
        return false;
    pos2 = gib.find(',', pos);
    overtime = gib.substr(pos + 1, pos2 - pos - 1);
    AStr = wxStringTokenize(overtime, "-");
    overtime = AStr[0] + '/' + AStr[1] + ' ' + wxString::Format("%d",wxAtoi(AStr[2])/60) + 'm';

    pos = gib.find("INI", pos);
    pos = gib.find('\n', pos) + 1;
    wxString line, mark;
    wxArrayString as;
    int line_count = 0;
    int pass = 0;
    int x = -1, y = -1;
    bool black = true;
    // 0 no pass
    // 1 B[]
    // 2 W[]
    while( (pos2 = gib.find('\n', pos)) != gib.npos )
    {
        line = gib.substr(pos, pos2 - pos);
        mark = line.substr(0, 3);
        pos = pos2 + 1;
        ++line_count;

        if (mark == "STO")
        {
            ++STO;
            if (pass == 1)
                SGF += ";B[]";
            else
            if (pass == 2)
                SGF += ";W[]";
            pass = 0;
            as = wxStringTokenize(line, " ");
            if (as.GetCount() != 6)
                return false;
            if (as[3] != "1" && as[3] != "2")
                return false;
            x = wxAtoi(as[4]);
            y = wxAtoi(as[5]);
            if (x < 0 || x > 18 || y < 0 || y > 18)
                return false;

            if (as[3] == "1")
            {
                SGF += wxString::Format(";B[%c%c]", x + 'a', y + 'a');
                black = false;
            }
            else
            {
                SGF += wxString::Format(";W[%c%c]", x + 'a', y + 'a');
                black = true;
            }

        }
        else
        if (mark == "REM")
        {
            ++REM;
        }
        else
        if (mark == "DSC")
        {
            ++DSC;
        }
        else
        if (mark == "SKI")
        {
            ++SKI;
            if (pass == 0)
                pass = 2 - black;
            else
            if ( (pass == 1) ^ black)
            {
                pass = 0;
                SKI_re += 2;
            }
            black = !black;
        }
        else
        if (mark == "SUR")
        {
            break;
        }
        else
        if (mark == "WIT")
        {
            ++WIT;
        }
    }

    if (   WIT != 0
        || SKI - SKI_re >= 3
        || DSC >= 10
        || REM >= 40
        || STO >= 450)
    {
        SGF = "";
        return false;
    }
    SGF += '\n';
    return true;
}