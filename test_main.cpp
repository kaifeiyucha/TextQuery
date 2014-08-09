#include "TextQuery.h"
#include <iostream>
#include <errno.h>
#include <stdlib.h>

using namespace std;

#define ERR_EXIT(m)\
    do{\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

ifstream &open_file(ifstream &in, const string &file);

//std::string make_plural(line_nums::type_size size);

void printf_results(const set<TextQuery::line_no>& locs, const string& sought, const TextQuery &file);


int main(int argc, const char *argv[])
{
    ifstream infile;
    cout  << "please input the name to look for:" << endl;
    std::string name;
    cin >> name;

    if(name == "" || !open_file(infile, name)){
        ERR_EXIT("NO INPUT FILE");
    }
    TextQuery txt;
    txt.read_file(infile);
    while(1){
        cout << endl;
        cout << "please input the words to look for:" << endl;
        string s;
        cin >> s;
        if(!cin || s == "q")  break;
        set<TextQuery::line_no> locs = txt.run_query(s);
        printf_results(locs, s, txt);
    }

    return 0;
}



ifstream &open_file(ifstream &in, const string &file){
    in.close();
    in.clear();
    in.open(file.c_str());
    return in;
}

/*std::string make_plural(line_nums::type_size size){
     return size > 1 ? "times" : "time";
}*/

void printf_results(const set<TextQuery::line_no>& locs, const string& sought, const TextQuery &file){

    typedef set<TextQuery::line_no> line_nums;
    
    line_nums::size_type size = locs.size();
    cout << sought  << "   occures   " << size <<" times" << endl; 
    line_nums::const_iterator it = locs.begin();
    for(; it != locs.end(); ++it){
        cout << "line : " << (*it)+1 << file.text_line(*it) << endl;
    }
}
