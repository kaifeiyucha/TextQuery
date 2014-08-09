#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_ 

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <set>


class TextQuery{
    public:
        typedef std::vector<std::string>::size_type line_no;
        TextQuery();
        ~TextQuery();
        void read_file(std::ifstream &is){//read text
            store_file(is);//store text with lines
            build_map();//map<words, set>
        }

        std::set<line_no> run_query(const std::string &)const ;
        std::string text_line(line_no) const;

    private:
        void store_file(std::ifstream &);
        void build_map();

        std::vector<std::string> lines_of_text;
        std::map< std::string, std::set<line_no> >  word_map;

};
#endif  /*TEXTQUERY_H_*/
