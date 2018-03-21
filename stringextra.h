
#ifndef __STRINGEXTRA_H_INCLUDED__
#define __STRINGEXTRA_H_INCLUDED__

namespace extra
{
    typedef struct dictionary
    {
        std::string _entry;
        int count;
    }
    dictionary;
    
    int occurance(const std::string& string,const std::string& finddata);
    std::string *splitstr(const std::string& string,int *total,char delimiter = ' ');


    int occurance(const std::string& string,const std::string& finddata)
    {
        int _i;
        int _total = 0;
        for(_i = 0; _i < string.length(); _i++)
        {
            if(string[_i] == finddata[0])
            {
                if(_i + finddata.length() <= string.length())
                {
                    if(string.substr(_i,finddata.length()) == finddata)
                        _total++;
                }
                else break;
            }
            else continue;
        }
        return _total;
    }
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
