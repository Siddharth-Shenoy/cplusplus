
#ifndef __STRINGEXTRA_H_INCLUDED__
#define __STRINGEXTRA_H_INCLUDED__
namespace extra
{
    std::string *splitstr(const std::string& string,int *total,char delimiter = ' ');
    std::string *splitstr(const std::string& string,int *total,char delimiter)
    {
        int _i,_j;
        int _total = 0;
        int _last = 0;
        std::string *retsplit = NULL;

        for(_i = 0; _i < string.length(); _i++)
            if(string[_i] == delimiter)
                _total++;

        _total++;
        _j = 0;
        *total = _total;
        retsplit = new std::string[_total];
        for(_i = 0; _i < string.length(); _i++)
        {
            if(string[_i] == delimiter)
            {
                retsplit[_j] = string.substr(_last,_i -_last);
                _last = _i + 1;
                _j++;
            }
            else continue;
        }
        retsplit[_j] = string.substr(_last,string.length() - _last);
        return retsplit;
    }
};
#endif
